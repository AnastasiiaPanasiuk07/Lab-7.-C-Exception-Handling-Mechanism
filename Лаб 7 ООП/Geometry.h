#pragma once
#include "Exceptions.h"

// Клас для представлення точки P1
class Point {
private:
    double x, y;
public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
};

// Клас для представлення прямої Ax + By + C = 0
class Line {
private:
    double A, B, C;

public:
    Line(double A, double B, double C);

    bool isValid() const;

    // Чотири варіанти обчислення та генерації виключень
    double calculateDistance1(const Point& p) const;
    double calculateDistance2(const Point& p) const noexcept;
    double calculateDistance3(const Point& p) const;
    double calculateDistance4(const Point& p) const;

    double getA() const;
    double getB() const;
    double getC() const;
};