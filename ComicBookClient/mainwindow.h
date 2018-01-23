#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QByteArray>
#include <QStringList>
#include <comicbook.h>
#include <QScopedPointer>
#include <item.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
    void readData();
    void drawCBlist();
    void addToBasket(int id, int quantaty);
    void drawBasket();
    void connectToCB();


private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QScopedPointer<QTcpSocket> Socket;
    QMap<int, ComicBook*> comics;
    QMap<int, Item> Basket;
};

#endif // MAINWINDOW_H
