// Settings.cpp
#include "Settings.h"
#include <QSettings>
#include <QCoreApplication>
static QSettings* s_settings = nullptr;

void Settings::init() {
    QCoreApplication::setOrganizationName("YourOrg");
    QCoreApplication::setApplicationName("FLAC Media Converter");
    s_settings = new QSettings(QSettings::IniFormat, QSettings::UserScope,
                               QCoreApplication::organizationName(),
                               QCoreApplication::applicationName());
}

QVariant Settings::get(const QString& key, const QVariant& def) {
    return s_settings ? s_settings->value(key, def) : def;
}
void Settings::set(const QString& key, const QVariant& value) {
    if (s_settings) s_settings->setValue(key, value);
}
