#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include "Settings.h"
#include "FirstRunWizard.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Settings::init(); // 初始化 QSettings 作用域等
    QTranslator translator;
    QString lang = Settings::get("General/language", "zh-TW").toString();
    if (translator.load(QString(":/i18n/app_%1.qm").arg(lang))) {
        app.installTranslator(&translator);
    }

    if (!Settings::get("General/first_run_completed", false).toBool()) {
        FirstRunWizard wizard;
        if (wizard.exec() == QDialog::Accepted) {
            Settings::set("General/first_run_completed", true);
        }
    }

    MainWindow w;
    w.show();
    return app.exec();
}
