#include <iostream>
#include "Showroom.h"
#include "Vehicle.h"
using namespace std;
Showroom::Showroom(string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}
vector<Vehicle> Showroom::GetVehicleList(){
    return vehicles;
}
void Showroom::AddVehicle(Vehicle v){
    if(vehicles.size() == capacity){
        cout<<"Showroom is full! Cannot add "<<v.GetYearMakeModel()<<endl;
    }
    else{
        vehicles.push_back(v);
    }
}
void Showroom::ShowInventory() {
    if(vehicles.size()==0){
        cout<<this->name<<" is empty!"<<endl;
    }
    else{
        cout<<"Vehicles in "<<this->name<<endl;
        for(int i = 0; i < vehicles.size(); i++){
            vehicles.at(i).Display();
        }
    }
    cout<<endl;
}
float Showroom::GetInventoryValue() {
    float total = 0;
    for(int i = 0; i < vehicles.size(); i++){
        total += vehicles.at(i).GetPrice();
    }
    return total;
}