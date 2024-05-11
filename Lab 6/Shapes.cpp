//
// Created by Matthew Dylewski on 3/17/22.
//
#include <iostream>
#include "Shapes.h"
using namespace std;

Shape::~Shape(){

}
Square ::Square() {
    length = 0;
}
Square :: Square(float l) {
    length = l;
}
float Square :: Area() const{
    float a = length * length;
    return a;
}
string Square ::GetName2D() const {
    return "Square";
}
void Square::Scale(float sf) {
    length = length * sf;
}
void Square::Display() const {
    cout<<"The area of the Square is : "<<Area()<<endl;
    cout<<"Length of a side: "<<length<<endl;
}
Triangle::Triangle() {
    base = 0;
    height = 0;
}
void Triangle::Scale(float sf) {
    base = base * sf;
    height = height * sf;
}
Triangle ::Triangle(float b, float h) {
    base = b;
    height = h;
}
float Triangle :: Area() const{
    float a = (height * base) / 2;
    return a;
}
string Triangle ::GetName2D() const {
    return "Triangle";
}
void Triangle::Display() const {
    cout<<"The area of the Triangle is : "<<Area()<<endl;
    cout<<"Base: "<<base<<endl;
    cout<<"Height: "<<height<<endl;
}
Circle::Circle(){
    radius = 0;
}
void Circle::Scale(float sf) {
    radius = radius * sf;
}
Circle ::Circle(float r) {
    radius = r;
}
float Circle :: Area() const{
    float a = pi * ((radius) * (radius));
    return a;
}
string Circle ::GetName2D() const {
    return "Circle";
}
void Circle::Display() const {
    cout<<"The area of the Circle is : "<<Area()<<endl;
    cout<<"Radius: "<<radius<<endl;
}
void Shape2D::ShowArea() const{
    cout<<"The area of the "<<GetName2D()<<"is : "<<Area()<<endl;
}
bool Shape2D::operator>(const Shape2D &rhs) const{
    if(this->Area() > rhs.Area()){
        return true;
    }
    return false;
}
bool Shape2D::operator<(const Shape2D &rhs) const{
    if(this->Area() < rhs.Area()){
        return true;
    }
    return false;
}
bool Shape2D::operator==(const Shape2D &rhs) const{
    if(this->Area() == rhs.Area()){
        return true;
    }
    return false;
}

TriangularPyramid::TriangularPyramid() {
    heightP = 0;
    Triangle::base = 0;
    Triangle::height = 0;
}
TriangularPyramid ::TriangularPyramid(float hp, float lb, float hb) {
    heightP = hp;
    Triangle::base = lb;
    Triangle::height = hb;
}
float TriangularPyramid :: Volume() const{
    //a = (base * scale)* (height* scale) / 2;
    float v = ((Triangle::Area()) * (heightP) / 3);
    return v;
}
void TriangularPyramid::Scale(float sf) {
    heightP = heightP * sf;
    Triangle::height = height * sf;
    Triangle::base = base * sf;
}
string TriangularPyramid ::GetName3D() const {
    return "TriangularPyramid";
}
void TriangularPyramid::Display() const {
    cout<<"The volume of the TriangularPyramid is : "<<Volume()<<endl;
    cout<<"The height is: "<<heightP<<endl;
    cout<<"The area of the Triangle is : "<<Area()<<endl;
    cout<<"Base: "<<base<<endl;
    cout<<"Height: "<<height<<endl;
}
Cylinder::Cylinder() {
    Circle::radius = 0;
}
Cylinder ::Cylinder(float h, float r){
    Circle::radius = r;
    heightC = h;
}
float Cylinder :: Volume() const{
    //a = pi * ((radius) * (radius));
    float v = pi * ((radius)*(radius))*(heightC);
    return v;
}
string Cylinder ::GetName3D() const {
    return "Cylinder";
}
void Cylinder::Scale(float sf) {
    Circle::radius = radius * sf;
    heightC = heightC * sf;
}
void Cylinder::Display() const {
    cout<<"The volume of the Cylinder is : "<<Volume()<<endl;
    cout<<"The height is: "<<heightC<<endl;
    cout<<"The area of the Circle is : "<<Area()<<endl;
    cout<<"Radius: "<<radius<<endl;
}
Sphere::Sphere() {
    Circle::radius = 0;
}
Sphere ::Sphere(float r) {
    Circle::radius = r;
}
float Sphere :: Volume() const{
    //a = pi * ((radius) * (radius));
    float v = (pi * ((radius)*(radius)*(radius))) * 4/3;
    return v;
}
string Sphere ::GetName3D() const {
    return "Sphere";
}
void Sphere::Scale(float sf) {
    radius = radius * sf;
}
void Sphere::Display() const {
    cout<<"The volume of the Sphere is : "<<Volume()<<endl;
    cout<<"The area of the Circle is : "<<Area()<<endl;
    cout<<"Radius: "<<radius<<endl;
}
void Shape3D::ShowVolume() const{
    cout<<"The volume of the "<<GetName3D()<<" is : "<<Volume()<<endl;
}
bool Shape3D::operator>(const Shape3D &rhs) const{
    if(this->Volume() > rhs.Volume()){
        return true;
    }
    return false;
}
bool Shape3D::operator<(const Shape3D &rhs) const{
    if(this->Volume() < rhs.Volume()){
        return true;
    }
    return false;
}
bool Shape3D::operator==(const Shape3D &rhs) const{
    if(this->Volume() == rhs.Volume()){
        return true;
    }
    return false;
}