//Алексей Кудрявцев, 6-я группа
#include "mainwindow.h"
#include "veclass.h"
#include <QApplication>
#include <QFile>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile input("vehicle.txt");
    if (!input.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Couldn't open input.txt";
        return -1;
    }
    QTextStream in(&input);

    QVector<std::shared_ptr<Car>> cars;
    QVector<std::shared_ptr<Truck>> trucks;


    QString name;
    int cost, pow, payload;
    while(!in.atEnd()){
        name = in.readLine();
        cost = in.readLine().toInt();
        pow = in.readLine().toInt();
        payload = in.readLine().toInt();

        if(payload == 0) cars.append(std::make_shared<Car>(name,cost,pow));

        else trucks.append(std::make_shared<Truck>(name, cost, pow, payload));
    }
    MainWindow w(cars, trucks);

    w.show();
    return a.exec();
}
