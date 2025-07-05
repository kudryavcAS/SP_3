#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QVector<std::shared_ptr<Car>>& _cars, QVector<std::shared_ptr<Truck>>& _trucks ,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), cars(_cars), trucks(_trucks)
{
    ui->setupUi(this);

    QIntValidator *validator = new QIntValidator(0, 1000000000, this);
    ui->lineEdit_2->setValidator(validator);

    QIntValidator *validator2 = new QIntValidator(0, 1000, this);
    ui->lineEdit_3->setValidator(validator2);
    ui->lineEdit_4->setValidator(validator2);

    int max = cars.size() + trucks.size();
    ui->tableWidget->setRowCount(max);

    int x = cars.size();
    for (int row = 0; row < max; row++)
    {
        if(row < x){
            QTableWidgetItem* Item = new QTableWidgetItem();
            QString str = "Автомобиль\n";
            str+=cars[row]->GetName();
            Item->setText(str);
            ui->tableWidget->setItem(row, 0, Item);
            str.clear();

            QTableWidgetItem* ItemC = new QTableWidgetItem();
            str+=QString::number(cars[row]->GetCost());
            ItemC->setText(str);
            ui->tableWidget->setItem(row, 1, ItemC);
            str.clear();

            QTableWidgetItem* ItemP = new QTableWidgetItem();
            str+=QString::number(cars[row]->GetPower());
            ItemP->setText(str);
            ui->tableWidget->setItem(row, 2, ItemP);
            str.clear();

            QTableWidgetItem* ItemY = new QTableWidgetItem();
            str+="-";
            ItemY->setText(str);
            ui->tableWidget->setItem(row, 3, ItemY);
            str.clear();
        }
        else {
            QTableWidgetItem* Item = new QTableWidgetItem();
            QString str = "Грузовик\n";
            str+=trucks[row-x]->GetName();
            Item->setText(str);
            ui->tableWidget->setItem(row, 0, Item);
            str.clear();

            QTableWidgetItem* ItemC = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetCost());
            ItemC->setText(str);
            ui->tableWidget->setItem(row, 1, ItemC);
            str.clear();

            QTableWidgetItem* ItemP = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetPower());
            ItemP->setText(str);
            ui->tableWidget->setItem(row, 2, ItemP);
            str.clear();

            QTableWidgetItem* ItemY = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetPayload());
            ItemY->setText(str);
            ui->tableWidget->setItem(row, 3, ItemY);
            str.clear();
        }
    };
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    int cost = ui->lineEdit_2->text().toInt();
    int pow = ui->lineEdit_3->text().toInt();
    int payload = ui->lineEdit_4->text().toInt();

    if(payload == 0) cars.append(std::make_shared<Car>(name,cost,pow));

    else trucks.append(std::make_shared<Truck>(name, cost, pow, payload));

    ui->tableWidget->clear();
    int max = cars.size() + trucks.size();
    ui->tableWidget->setRowCount(max);

    int x = cars.size();

    for (int row = 0; row < max; row++)
    {
        if(row < x){
            QTableWidgetItem* Item = new QTableWidgetItem();
            QString str = "Автомобиль\n";
            str+=cars[row]->GetName();
            Item->setText(str);
            ui->tableWidget->setItem(row, 0, Item);
            str.clear();

            QTableWidgetItem* ItemC = new QTableWidgetItem();
            str+=QString::number(cars[row]->GetCost());
            ItemC->setText(str);
            ui->tableWidget->setItem(row, 1, ItemC);
            str.clear();

            QTableWidgetItem* ItemP = new QTableWidgetItem();
            str+=QString::number(cars[row]->GetPower());
            ItemP->setText(str);
            ui->tableWidget->setItem(row, 2, ItemP);
            str.clear();

            QTableWidgetItem* ItemY = new QTableWidgetItem();
            str+="-";
            ItemY->setText(str);
            ui->tableWidget->setItem(row, 3, ItemY);
            str.clear();
        }
        else {
            QTableWidgetItem* Item = new QTableWidgetItem();
            QString str = "Грузовик\n";
            str+=trucks[row-x]->GetName();
            Item->setText(str);
            ui->tableWidget->setItem(row, 0, Item);
            str.clear();

            QTableWidgetItem* ItemC = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetCost());
            ItemC->setText(str);
            ui->tableWidget->setItem(row, 1, ItemC);
            str.clear();

            QTableWidgetItem* ItemP = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetPower());
            ItemP->setText(str);
            ui->tableWidget->setItem(row, 2, ItemP);
            str.clear();

            QTableWidgetItem* ItemY = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetPayload());
            ItemY->setText(str);
            ui->tableWidget->setItem(row, 3, ItemY);
            str.clear();
        }
    };
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);


}


void MainWindow::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text();
    int cost = ui->lineEdit_2->text().toInt();
    int pow = ui->lineEdit_3->text().toInt();
    int payload = ui->lineEdit_4->text().toInt();
    int z = cars.size();
    int y = trucks.size();
    if(payload == 0){
        Car* car = new Car(name, cost, pow);
         for(int i=0; i< cars.size();i++){
            if(*car == *cars[i]){
                cars.removeAt(i);
            }

        }
         delete car;
    }
    else {
        Truck* car = new Truck(name, cost, pow, payload);
        for(int i=0; i< trucks.size();i++){
            if(*car == *trucks[i]){
                trucks.removeAt(i);
            }

        }
        delete car;
    }

    if(z == cars.size() && y ==trucks.size()){

        QMessageBox::information(
            this,
            "Ошибка удаления",
            "ТС с такими характеристиками не найдено!"
            );
    }

    ui->tableWidget->clear();
    int max = cars.size() + trucks.size();
    ui->tableWidget->setRowCount(max);

    int x = cars.size();

    for (int row = 0; row < max; row++)
    {
        if(row < x){
            QTableWidgetItem* Item = new QTableWidgetItem();
            QString str = "Автомобиль\n";
            str+=cars[row]->GetName();
            Item->setText(str);
            ui->tableWidget->setItem(row, 0, Item);
            str.clear();

            QTableWidgetItem* ItemC = new QTableWidgetItem();
            str+=QString::number(cars[row]->GetCost());
            ItemC->setText(str);
            ui->tableWidget->setItem(row, 1, ItemC);
            str.clear();

            QTableWidgetItem* ItemP = new QTableWidgetItem();
            str+=QString::number(cars[row]->GetPower());
            ItemP->setText(str);
            ui->tableWidget->setItem(row, 2, ItemP);
            str.clear();

            QTableWidgetItem* ItemY = new QTableWidgetItem();
            str+="-";
            ItemY->setText(str);
            ui->tableWidget->setItem(row, 3, ItemY);
            str.clear();
        }
        else {
            QTableWidgetItem* Item = new QTableWidgetItem();
            QString str = "Грузовик\n";
            str+=trucks[row-x]->GetName();
            Item->setText(str);
            ui->tableWidget->setItem(row, 0, Item);
            str.clear();

            QTableWidgetItem* ItemC = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetCost());
            ItemC->setText(str);
            ui->tableWidget->setItem(row, 1, ItemC);
            str.clear();

            QTableWidgetItem* ItemP = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetPower());
            ItemP->setText(str);
            ui->tableWidget->setItem(row, 2, ItemP);
            str.clear();

            QTableWidgetItem* ItemY = new QTableWidgetItem();
            str+=QString::number(trucks[row-x]->GetPayload());
            ItemY->setText(str);
            ui->tableWidget->setItem(row, 3, ItemY);
            str.clear();
        }
    };
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);



}

