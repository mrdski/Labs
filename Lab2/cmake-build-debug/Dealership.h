#ifndef LAB2_DEALERSHIP_H
#define LAB2_DEALERSHIP_H
#include <iostream>
#include "Showroom.h"
using namespace std;
#include <string>
class Dealership{
private:
    vector<Showroom> rooms;
    string name;
    unsigned int capacity;
public:
    Dealership(string name = "Generic Dealership", unsigned int capacity = 0);
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();
};
#endif //LAB2_DEALERSHIP_H
