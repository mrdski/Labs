//
// Created by Matthew Dylewski on 3/17/22.
//

#ifndef LAB_6_SHAPES_H
#define LAB_6_SHAPES_H
#include <iostream>
#include <string>

using namespace  std;
class Shape{
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    float pi = 3.14159f;
    virtual ~Shape() = 0;
};

class Shape2D : virtual public Shape{
public:
    float length = 0;
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};
class Square : virtual public Shape2D{
public:
    Square();
    Square(float l);
    float Area() const;
    string GetName2D() const;
    void Display() const;
    void Scale (float sf);
};
class Triangle: virtual public Shape2D{
public:
    float base = 0;
    float height = 0;
    Triangle();
    Triangle(float b, float h);
    float Area() const;
    string GetName2D() const;
    void Display() const;
    void Scale (float sf);
};
class Circle: virtual public Shape2D{
public:
    float radius = 0;
    Circle();
    Circle(float r);
    float Area() const;
    string GetName2D() const;
    void Display() const;
    void Scale (float sf);
};

class Shape3D : virtual public Shape{
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};
class TriangularPyramid: virtual public Shape3D, virtual private Triangle{
    float heightP = 0;
public:
    TriangularPyramid();
    TriangularPyramid(float hp, float lb, float hb);
    float Volume() const;
    string GetName3D() const;
    void Display() const;
    void Scale (float sf);
};
class Cylinder: virtual public Shape3D, virtual private Circle{
    float heightC = 0;
public:
    Cylinder();
    Cylinder(float h, float r);
    float Volume() const;
    string GetName3D() const;
    void Display() const;
    void Scale (float sf);
};
class Sphere: virtual public Shape3D, virtual private Circle{
public:
    Sphere();
    Sphere(float r);
    float Volume() const;
    string GetName3D() const;
    void Display() const;
    void Scale (float sf);
};
#endif //LAB_6_SHAPES_H
