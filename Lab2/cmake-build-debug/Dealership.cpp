#include "Dealership.h"
using namespace std;
Dealership::Dealership(string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}
void Dealership::AddShowroom(Showroom s) {
    if(rooms.size()==capacity){
        cout<<"Dealership is full, can't add another showroom!"<<endl;
    }
    else{
        rooms.push_back(s);
    }
}
float Dealership::GetAveragePrice() {
    float totalPrice = 0.00;
    unsigned int numVehicles = 0;
    if(rooms.size()>0) {
        for (int i = 0; i < rooms.size(); i++) {
            totalPrice += rooms.at(i).GetInventoryValue();
            numVehicles += rooms.at(i).GetVehicleList().size();
        }
        return totalPrice / (float)numVehicles;
    }
    else{
        return totalPrice;
    }
}
void Dealership::ShowInventory() {
    if(rooms.size()==0){
        cout<<this->name<<" is empty!"<<endl;
    }
    else{
        for(int i = 0; i < rooms.size(); i++){
            rooms.at(i).ShowInventory();
        }
    }
    cout<<"Average car price: $"<<GetAveragePrice();
}