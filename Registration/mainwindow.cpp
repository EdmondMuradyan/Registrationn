#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_S_Button_clicked()
{
    QString name = ui->Name_Line->text();
    QString age = ui->Age_Spin->text();
    QString birth = ui->Birth_Line->text();

    user.setInfo(name, age, birth);
    ui->Birth_Line->clear();
    ui->Name_Line->clear();
    ui->Age_Spin->clear();

    user.saveFile("/Users/edmondmuradyan/Desktop/Atlas/new.txt");
}

void MainWindow::on_D_Button_clicked()
{
    User::printFileContents("/Users/edmondmuradyan/Desktop/Atlas/new.txt");
}
