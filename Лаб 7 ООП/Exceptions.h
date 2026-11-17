#pragma once
#include <exception>
#include <string>

// 1. Порожній клас виключення
class EmptyLineException {};

// 2. Незалежний клас із полями-параметрами прямої
class LineParametersException {
private:
    double a, b, c;
public:
    LineParametersException(double a, double b, double c);
    void printError() const;
};

// 3. Клас-нащадок від стандартного виключення 
class DetailedLineException : public std::exception {
private:
    std::string message;
public:
    DetailedLineException(double a, double b);
    const char* what() const noexcept override;
};