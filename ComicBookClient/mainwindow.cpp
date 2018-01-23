#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    for(auto a:comics)
        delete a;
}

void MainWindow::on_pushButton_clicked()
{
    connectToCB();
}

void MainWindow::connectToCB()
{
    Socket.reset(new QTcpSocket( this ));
    connect( Socket.data(), SIGNAL(readyRead()), SLOT(readData()));
    Socket->connectToHost("127.0.0.1", 1234);
}

void MainWindow::readData()
{
    QByteArray data = Socket->readAll();

    QString stringData=QString::fromUtf8(data);

    if(stringData=="successful order")
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Message", "Your order is procesed. Do you want to new order?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            for(auto a:comics)
                delete a;
            ui->tableWidget->clear();
            connectToCB();
        }
        else
        {
            QApplication::quit();
        }

    }
    else if(stringData=="error")
    {
        QMessageBox::information(this,"error","order failed");
    }
    else
    {

    QStringList list=QString::fromUtf8(data).split("|");
    for(auto a:list)
    {
        QStringList sp=a.split(";");
        double d=sp.at(2).toDouble();
        comics[sp.at(0).toInt()]=new ComicBook(sp.at(0).toInt(),sp.at(1),d,sp.at(3).toInt(),this);
    }

    drawCBlist();
    }
}

void MainWindow::drawCBlist()
{
    double pos;
    for(auto cb:comics)
    {
        cb->setGeometry(0,pos,200,40);
        pos+=20;
        cb->show();
    }
}

void MainWindow::addToBasket(int id,int quantaty)
{
    int i=0;
    Basket[id]= Item(id,quantaty);
    drawBasket();

}

void MainWindow::drawBasket()
{
    int row=0;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(Basket.size());
    for(auto a:Basket)
    {
        double pr=a.getQuantaty()*comics[a.getID()]->getPrice();
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(comics[a.getID()]->getName()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::number(a.getQuantaty())));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(pr, 'f', 2)));
        row++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString data="";
    for(auto a:Basket)
    {
        data+=a.toString()+"|";
    }
    data=data.left(data.size()-1);
    Socket->write(data.toUtf8());
}
