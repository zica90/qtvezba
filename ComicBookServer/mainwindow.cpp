#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DbManager.reset(new DatabaseManager);
    DbManager->getAllComics(comics);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mServer.reset(new MyServer());
}

void MainWindow::on_pushButton_2_clicked()
{

    bool succ=false;
    ComicBook cb(ui->lineEdit->text().toInt(),ui->lineEdit_2->text(),ui->lineEdit_3->text().toDouble(),ui->spinBox->value());
    if(!comics.count(ui->lineEdit->text().toInt()))
    {
        qDebug()<<"asddasda";
        if(DbManager->insertComicBook(cb))
        {
            comics[cb.getId()]=cb;
            succ=true;
        }
    }
    else
    {
        comics[ui->lineEdit->text().toInt()].setStock(ui->spinBox->value());
        succ=DbManager->upgradeDB(comics[ui->lineEdit->text().toInt()]);
    }

    if(succ)
    {
       QMessageBox::information(this,"Insert","ComicBook added to the store");
    }
    else
    {
        QMessageBox::information(this,"Insert","Error");
    }

}

QMap<int, ComicBook> MainWindow::getComics() const
{
    return comics;
}

void MainWindow::processOrder(const QString& str)
{
    QStringList line=str.split("|");
    for(auto a:line)
    {

        QStringList parts = a.split(";");
        comics[parts.at(0).toInt()].setStock((-1)*parts.at(1).toInt());
      //  qDebug()<<comics[]
        if(DbManager->upgradeDB(comics[parts.at(0).toInt()])==false)
        {
            qDebug()<<"kojimoj";
            mServer->orderProcessed(false);
            return;
        }
    }
    mServer->orderProcessed(true);
}

void MainWindow::pushInTable()
{   int row=0;
    ui->tableWidget->setRowCount(comics.size());
    ui->tableWidget->setColumnCount(3);
    for(auto a:comics)
    {
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(a.getId())));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(a.getName()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(a.getPrice(), 'f', 2)));
        ui->tableWidget->setItem(row++,3,new QTableWidgetItem(QString::number(a.getStock())));
    }

}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    pushInTable();
}

void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex currentIndex = ui->tableWidget->currentIndex();
    int id=ui->tableWidget->item(currentIndex.row(),0)->text().toInt();
    if(DbManager->deleteCBfromDB(id))
    {
        comics.remove(id);
        QMessageBox::information(this,"Delete","Comic deleted from DB");
        pushInTable();
    }
    else
    {
        QMessageBox::information(this,"Delete","Error!");
    }

}
