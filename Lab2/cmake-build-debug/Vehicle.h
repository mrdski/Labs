#ifndef LAB2_VEHICLE_H
#define LAB2_VEHICLE_H
#include <string>
using namespace std;
class Vehicle{
private:
    string make;
    string model;
    unsigned int year;
    float price;
    unsigned  int mileage;

public:
    Vehicle();
    Vehicle(string make, string model, int year, float price, int milage);
    void Display();
    string GetYearMakeModel();
    float GetPrice();
};
#endif //LAB2_VEHICLE_H

