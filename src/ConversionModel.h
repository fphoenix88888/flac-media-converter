#ifndef CONVERSIONMODEL_H
#define CONVERSIONMODEL_H

// ConversionModel.h
#pragma once
#include <QAbstractTableModel>
#include <QVector>
#include "ConversionItem.h"

class ConversionModel : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit ConversionModel(QObject* parent=nullptr);
    int rowCount(const QModelIndex&) const override;
    int columnCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex&, int role) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    void setItems(const QVector<ConversionItem>& items);
    void updateItem(int index, const ConversionItem& item);
private:
    QVector<ConversionItem> items_;
};


#endif // CONVERSIONMODEL_H
