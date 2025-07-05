#include "veclass.h"


Engine::Engine() : power(0) {}

Engine::Engine(int p) : power(p) {}

Engine::Engine(const Engine& other) : power(other.power) {}

int Engine::GetPow() const {
    return power;
}

void Engine::SetPow(int p) {
    power = p;
}


Car::Car(QString name, int cost, int pow): engine(pow), Brand(name), price(cost){}

Car::Car() : engine(0), Brand(QString()), price(0) {}

Car::Car(const Car& other): engine(other.engine), Brand(other.Brand), price(other.price) {}

Car::~Car() {
    Brand.clear();
}

void Car::Rename(const QString& name) {
    Brand = name;
}

Truck::Truck(QString name, int cost, int pow, int payload) : Car(name, cost, pow), payload(payload) {}

Truck::Truck() : Car(), payload(0) {}

Truck::Truck(const Truck& other)
    : Car(other), payload(other.payload) {}

Truck::~Truck() {}

void Truck::print(QTextStream& out) const {
    out << "Information about truck:\n\n" << "Brand: " << Brand << "\n" << "Price: " << price << "$\n"
        << "Engine power: " << engine.GetPow() << "W\n"
        << "Payload: " << payload << "t\n\n";
    out.flush();
}

QString Car::GetName(){return Brand;}
int Car::GetPower(){return engine.GetPow();}
int Car::GetCost(){return price;}
bool Car::operator==(const Car& car){

    return (Brand==car.Brand && price == car.price && engine.GetPow() == car.engine.GetPow());
}


QString Truck::GetName(){return Brand;}
int Truck::GetPower(){return engine.GetPow();}
int Truck::GetCost(){return price;}
int Truck::GetPayload(){return payload;}
bool Truck::operator==(const Truck& car){

    return (Brand==car.Brand && price == car.price && engine.GetPow() == car.engine.GetPow() && payload == car.payload);
}
