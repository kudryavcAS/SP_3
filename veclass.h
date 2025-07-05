#ifndef VECLASS_H
#define VECLASS_H

#include <QTextStream>
#include <QString>
class Engine{
public:
    Engine();
    Engine(int p);
    Engine(const Engine&);
    int GetPow()const;
    void SetPow(int p);
private:
    int power;

};

class Car{
protected:
    Engine engine;
    QString Brand;
    int price=0;

public:
    Car(QString name, int cost,int pow);
    Car();
    Car(const Car&);
    virtual ~Car();
    void Rename(const QString&name);
    QString GetName();
    int GetPower();
    int GetCost();
    bool operator==(const Car& car);

};

class Truck : public Car {
public:
    Truck(QString name, int cost, int pow, int payload);
    Truck();
    Truck(const Truck&);
    ~Truck();
    void print(QTextStream& out) const;
    QString GetName();
    int GetPower();
    int GetCost();
    int GetPayload();
    bool operator==(const Truck& car);
private:
    int payload;
};


#endif // VECLASS_H
