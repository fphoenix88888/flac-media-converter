#ifndef CONVERSIONITEM_H
#define CONVERSIONITEM_H

// ConversionItem.h
#pragma once
#include <QString>

enum class ItemStatus { Pending, Converting, Done, Failed };

struct ConversionItem {
    QString sourcePath;
    QString fileName;
    ItemStatus status = ItemStatus::Pending;
    double progress = 0.0; // 0..100
    qint64 elapsedMs = 0;
    QString errorMessage;
};


#endif // CONVERSIONITEM_H
