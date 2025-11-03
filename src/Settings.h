#ifndef SETTINGS_H
#define SETTINGS_H

// Settings.h
#pragma once
#include <QVariant>
namespace Settings {
void init(); // 設定組織/應用名稱、QSettings backend
QVariant get(const QString& key, const QVariant& def = {});
void set(const QString& key, const QVariant& value);
}


#endif // SETTINGS_H
