#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("bonwick.dev");
    QCoreApplication::setOrganizationDomain("bonwick.dev");
    QCoreApplication::setApplicationName("Symetrix460Controller");
    QCoreApplication::setApplicationVersion("0.1");
    MainWindow w;
    w.show();
    return a.exec();
}
