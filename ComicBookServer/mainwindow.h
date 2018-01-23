#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myserver.h"
#include <QScopedPointer>
#include <databasemanager.h>
#include <QMessageBox>
#include <QMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMap<int, ComicBook> getComics() const;
    void processOrder(const QString& str);
    void pushInTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QScopedPointer<MyServer> mServer;
    QScopedPointer<DatabaseManager> DbManager;
    QMap<int,ComicBook> comics;
};

#endif // MAINWINDOW_H
