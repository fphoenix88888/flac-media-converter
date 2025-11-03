// FirstRunWizard.cpp
#include "FirstRunWizard.h"
#include "Settings.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QUuid>
#include <QCryptographicHash>

static QString generateLocalHashcode() {
    auto uuid = QUuid::createUuid().toString(QUuid::WithoutBraces).toUtf8();
    auto hash = QCryptographicHash::hash(uuid, QCryptographicHash::Sha256);
    return QString::fromLatin1(hash.toHex());
}

FirstRunWizard::FirstRunWizard(QWidget* parent) : QDialog(parent) {
    auto layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel(tr("歡迎！請完成初始設定。")));
    // TODO: 語言選擇、ffmpeg 路徑偵測、輸出目錄設定等
    auto ok = new QPushButton(tr("開始使用"));
    connect(ok, &QPushButton::clicked, this, [this](){
        Settings::set("General/local_hashcode", generateLocalHashcode());
        accept();
    });
    layout->addWidget(ok);
}
