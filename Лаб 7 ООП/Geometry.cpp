#include "Geometry.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

// Реалiзацiя LineParametersException 
LineParametersException::LineParametersException(double a, double b, double c) : a(a), b(b), c(c) {}

void LineParametersException::printError() const {
    std::cout << "[LineParametersException] Помилка: пряма "
        << a << "x + " << b << "y + " << c << " = 0 має A = 0 та B = 0.\n";
}

// Реалiзацiя DetailedLineException
DetailedLineException::DetailedLineException(double a, double b) {
    message = "DetailedLineException: знаменник A^2 + B^2 = 0 (A = " + std::to_string(a) + ", B = " + std::to_string(b) + ").";
}

const char* DetailedLineException::what() const noexcept {
    return message.c_str();
}

// Реалiзацiя Point 
Point::Point(double x, double y) : x(x), y(y) {}
double Point::getX() const { return x; }
double Point::getY() const { return y; }

// Реалiзацiя Line
Line::Line(double A, double B, double C) : A(A), B(B), C(C) {}

bool Line::isValid() const {
    return !(A == 0 && B == 0);
}

double Line::calculateDistance1(const Point& p) const {
    if (!isValid()) {
        throw std::string("Помилка (Варіант 1): Коефіцієнти A та B дорівнюють нулю");
    }
    return std::abs(A * p.getX() + B * p.getY() + C) / std::sqrt(A * A + B * B);
}

double Line::calculateDistance2(const Point& p) const noexcept {
    return std::abs(A * p.getX() + B * p.getY() + C) / std::sqrt(A * A + B * B);
}

double Line::calculateDistance3(const Point& p) const {
    if (!isValid()) {
        throw std::invalid_argument("Помилка (Варіант 3): A і B не можуть бути нулями одночасно (std::invalid_argument).");
    }
    return std::abs(A * p.getX() + B * p.getY() + C) / std::sqrt(A * A + B * B);
}

double Line::calculateDistance4(const Point& p) const {
    if (!isValid()) {
        throw DetailedLineException(A, B);
    }
    return std::abs(A * p.getX() + B * p.getY() + C) / std::sqrt(A * A + B * B);
}

double Line::getA() const { return A; }
double Line::getB() const { return B; }
double Line::getC() const { return C; }