#include <iostream>
using namespace std;

class automobile
{
private:
    /* data */
public:
    string gearbox;
    string brake;
    string wheel;
    string engine;
    string steering;
    automobile(string gearbox,
               string brake,
               string wheel,
               string engine,
               string steering) : gearbox(), brake(), wheel(), engine(), steering() {}
    void run(string name) { cout << name << " RUN!" << endl; };
    void stop(string name) { cout << name << " STOP!" << endl; };
    void start(string name) { cout << name << " START!" << endl; };
};

class Car : public automobile
{
private:
    /* data */
public:
    Car(string gearbox,
        string brake,
        string wheel,
        string engine,
        string steering) : automobile(gearbox, brake, wheel, engine, steering){};
    void Car_PC() { cout << "PC,PLAY!" << endl; };
    void ATO() { cout << "ATO,START!" << endl; };
};

class Truck : public automobile
{
private:
    /* data */
public:
    Truck(string gearbox,
          string brake,
          string wheel,
          string engine,
          string steering) : automobile(gearbox, brake, wheel, engine, steering){};
    void unloading() { cout << "Unloading,START!" << endl; };
    void cargo() { cout << "OK,cargo." << endl; };
};

int main()
{
    Car *peter = new Car("Precipart", "EBC", "BBS", "Toyota", "JDM");
    Truck *stwee = new Truck("BDI", "Brembo", "Enkei", "Ford", "MOMO ");
    cout << "功能测试↓" << endl;
    cout << ">peter CAR:" << endl;
    peter->run("peter");
    peter->stop("peter");
    peter->start("peter");
    peter->Car_PC();
    peter->ATO();
    cout << ">stwee Truck:" << endl;
    stwee->run("stwee");
    stwee->stop("stwee");
    stwee->start("stwee");
    stwee->unloading();
    stwee->cargo();
    
    delete peter;
    delete stwee;
    return 0;
}