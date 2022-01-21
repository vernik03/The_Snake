#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFocusEvent>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   Qt::FocusPolicy pol;

   srand(time(NULL));
    /*
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "snake_qt_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }*/


    MainWindow w;
    w.show();
    return a.exec();
}
