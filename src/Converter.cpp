// Converter.cpp
#include "Converter.h"
#include "FfmpegCommand.h"
#include <QFileInfo>
#include <QDir>
#include <QDateTime>

Converter::Converter(QObject* parent) : QObject(parent) {
    connect(&proc_, &QProcess::readyReadStandardError, this, &Converter::onReadyReadStandardError);
    connect(&proc_, QOverload<int,QProcess::ExitStatus>::of(&QProcess::finished),
            this, &Converter::onProcessFinished);
}

void Converter::start(const QList<ConversionItem>& items, const QString& outDir, const Profile& p) {
    items_ = items;
    outDir_ = outDir;
    profile_ = p;
    currentIndex_ = -1;
    startNext();
}

void Converter::startNext() {
    currentIndex_++;
    if (currentIndex_ >= items_.size()) {
        int ok = 0, fail = 0;
        for (const auto& it : items_) (it.status == ItemStatus::Done ? ok++ : fail++);
        emit finished(ok, fail);
        return;
    }
    auto& it = items_[currentIndex_];
    it.status = ItemStatus::Converting;
    emit itemStatus(currentIndex_, it.status, QString());
    QString out = makeOutputPath(it.sourcePath);
    QStringList args = FfmpegCommand::build(it.sourcePath, out, profile_).split(' ');
    proc_.setProgram("ffmpeg"); // 可改為 Settings 中的 ffmpeg_path
    proc_.setArguments(args);
    startMs_ = QDateTime::currentMSecsSinceEpoch();
    proc_.start();
}

QString Converter::makeOutputPath(const QString& input) {
    QFileInfo fi(input);
    QString base = fi.completeBaseName();
    QString outFile = base + ".flac";
    return QDir(outDir_).filePath(outFile);
}

void Converter::onReadyReadStandardError() {
    QByteArray data = proc_.readAllStandardError();
    // 簡單解析：尋找 "time=" 與 "speed=" 估算進度（需要 input 時長，MVP 可用檔案索引近似）
    // TODO: 透過預先以 ffprobe 取時長，進度 = 輸出 time / 總時長 * 100
    qint64 now = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsed = now - startMs_;
    emit itemProgress(currentIndex_, 0.0 /*暫定*/, elapsed);
}

void Converter::onProcessFinished(int exitCode, QProcess::ExitStatus status) {
    auto& it = items_[currentIndex_];
    if (status == QProcess::NormalExit && exitCode == 0) {
        it.status = ItemStatus::Done;
    } else {
        it.status = ItemStatus::Failed;
        it.errorMessage = QString::fromUtf8(proc_.readAllStandardError());
    }
    emit itemStatus(currentIndex_, it.status, it.errorMessage);
    double overall = (double)(currentIndex_ + 1) / (double)items_.size() * 100.0;
    emit overallProgress(overall);
    startNext();
}
