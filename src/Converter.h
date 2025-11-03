#ifndef CONVERTER_H
#define CONVERTER_H

// Converter.h
#pragma once
#include <QObject>
#include <QProcess>
#include "ConversionItem.h"
#include "Profile.h"

class Converter : public QObject {
    Q_OBJECT
public:
    explicit Converter(QObject* parent = nullptr);
    void start(const QList<ConversionItem>& items, const QString& outDir, const Profile& p);
signals:
    void itemProgress(int index, double percent, qint64 elapsedMs);
    void itemStatus(int index, ItemStatus status, const QString& msg);
    void overallProgress(double percent);
    void finished(int successCount, int failCount);
private:
    QList<ConversionItem> items_;
    QString outDir_;
    Profile profile_;
    int currentIndex_ = -1;
    QProcess proc_;
    qint64 startMs_ = 0;
    void startNext();
    QString makeOutputPath(const QString& input);
private slots:
    void onReadyReadStandardError();
    void onProcessFinished(int exitCode, QProcess::ExitStatus status);
};


#endif // CONVERTER_H
