//
// Created by Matthew Dylewski on 4/15/22.
//

#include <vector>
#include "Color.h"
Color::Color(string n, int v) {
    this->name = n;
    this->value = v;
    SetValue(v);
}
void Color::SetValue(int value){
    string h;
    this->value=value;
    while(value!=0){
        int re = value%16;
        value = value/16;
        if(re>9){
            switch (re) {
                case 10:
                    h = 'A' + h;
                    break;
                case 11:
                    h = 'B' + h;
                    break;
                case 12:
                    h = 'C' + h;
                    break;
                case 13:
                    h = 'D' + h;
                    break;
                case 14:
                    h = 'E' + h;
                    break;
                case 15:
                    h = 'F' + h;
                    break;
            }
        }
        else{
            h= to_string(re)+h;
        }
    }
    if(h.length()<6){
        int t = 6-h.length();
        for(int i = 0; i < t; i++){
            h= to_string(0)+h;
        }
    }
    this->hex = "0x" + h;
    char c[6];
    int cs[6];
    c[0] = hex.at(2);
    c[1] = hex.at(3);
    c[2] = hex.at(4);
    c[3] = hex.at(5);
    c[4] = hex.at(6);
    c[5] = hex.at(7);
    for(int i = 0; i < 6; i++){
        if(c[i]-48<10){
            cs[i] = c[i]-48;
        }
        else{
            switch (c[i]) {
                case 'A':
                    cs[i] = 10;
                    break;
                case 'B':
                    cs[i] = 11;
                    break;
                case 'C':
                    cs[i] = 12;
                    break;
                case 'D':
                    cs[i] = 13;
                    break;
                case 'E':
                    cs[i] = 14;
                    break;
                case 'F':
                    cs[i] = 15;
                    break;
            }
        }
    }
    int r=cs[0]*16 + cs[1];
    int g=cs[2]*16 + cs[3];
    int b=cs[4]*16 + cs[5];
    this->red=r;
    this->green=g;
    this->blue=b;
}
void Color::Setname(const char* n){
    this->name = n;
}
unsigned char Color::GetR() const{
    return this->red;
}
unsigned char Color::GetG() const{
    return this->green;
}
unsigned char Color::GetB() const{
    return this->blue;
}
string Color::GetHexValue() const{
    return this->hex;
}
string Color::GetName() const{
    return this->name;
}