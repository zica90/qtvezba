#include "mainwindow.h"
#include <QApplication>
#include <QScopedPointer>
QScopedPointer<MainWindow> w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w.reset(new MainWindow());
    w->show();

    return a.exec();
}
