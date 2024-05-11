#ifndef LAB2_SHOWROOM_H
#define LAB2_SHOWROOM_H
#include "Vehicle.h"
#include <vector>
using namespace std;
#include <string>
class Showroom{
private:
    string name;
    vector<Vehicle> vehicles;
    unsigned int capacity;
public:
    Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
    vector<Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};
#endif //LAB2_SHOWROOM_H
