#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// MainWindow.h
#pragma once
#include <QMainWindow>
#include <QVector>
#include "ConversionItem.h"

class QAction;
class QTableView;
class QComboBox;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
private slots:
    void onAddFiles();
    void onDragDropFiles(const QStringList& files);
    void onChooseOutputDir();
    void onManageProfiles();
    void onStartConversion();
private:
    QVector<ConversionItem> items_;
    QString outputDir_;
    QTableView* table_;
    QComboBox* profileCombo_;
    void setupUi();
    void loadProfiles();
    void refreshTable();
};

#endif
