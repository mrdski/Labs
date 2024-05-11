//
// Created by Matthew Dylewski on 4/15/22.
//

#ifndef LAB_8_COLOR_H
#define LAB_8_COLOR_H
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace  std;
class Color
{
    string name;
    string hex;
    int value;
    unsigned char red;
    unsigned char green;
    unsigned char blue;
public:
    //Given an integer value, convert it to RGB and Hex values
    Color(string n, int v);
    void SetValue(int value);
    void Setname(const char* name);
    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
    string GetHexValue() const;
    string GetName() const;
};
#endif //LAB_8_COLOR_H
