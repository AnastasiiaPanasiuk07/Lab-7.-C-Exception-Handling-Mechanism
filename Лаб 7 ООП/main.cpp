#include <iostream>
#include <windows.h>
#include "Geometry.h"
#include "Exceptions.h"

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Point p1(1.0, 2.0);
    Line invalidLine(0.0, 0.0, 5.0); // Пряма з помилковими параметрами (A=0, B=0)
    Line validLine(3.0, 4.0, 5.0);   // Коректна пряма

    std::cout << "=== Лабораторна робота №7: варіант 19 ===\n\n";

    // 1. Без специфікації виключень
    std::cout << "1. Без специфікації виключень \n";
    try {
        double d = invalidLine.calculateDistance1(p1);
        std::cout << "Відстань: " << d << "\n";
    }
    catch (const std::string& err) {
        std::cout << "[Перехоплено string]: " << err << "\n\n";
    }

    // 2. Зі специфікацією throw() / noexcept 
    std::cout << "--- 2. Зі специфікацією throw() / noexcept ---\n";
    try {
        double d = validLine.calculateDistance2(p1);
        std::cout << "Відстань обчислена: " << d << "\n\n";
    }
    catch (...) {
        std::cout << "Перехоплено виключення.\n\n";
    }

    // 3. Зі стандартним виключенням
    std::cout << "--- 3. З конкретною специфікацією та стандартним виключенням ---\n";
    try {
        double d = invalidLine.calculateDistance3(p1);
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "[Перехоплено std::invalid_argument]: " << ex.what() << "\n\n";
    }

    // 4. Із власними реалізованими виключеннями
    std::cout << "--- 4. Специфікація із власними реалізованими виключеннями ---\n";

    // А) Нащадок std::exception
    try {
        double d = invalidLine.calculateDistance4(p1);
    }
    catch (const DetailedLineException& ex) {
        std::cout << "[Перехоплено DetailedLineException]: " << ex.what() << "\n";
    }

    // Б) Незалежний клас із полями
    try {
        if (!invalidLine.isValid()) {
            throw LineParametersException(invalidLine.getA(), invalidLine.getB(), invalidLine.getC());
        }
    }
    catch (const LineParametersException& ex) {
        ex.printError();
    }

    // В) Порожній клас виключення
    try {
        if (!invalidLine.isValid()) {
            throw EmptyLineException();
        }
    }
    catch (const EmptyLineException&) {
        std::cout << "[EmptyLineException] Перехоплено порожнє виключення класу.\n";
    }

    std::cout << "\nРоботу завершено.\n";
    return 0;
}