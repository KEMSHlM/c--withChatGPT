/*
オーバーロードを使って、整数と浮動小数点数の加算、減算、乗算、除算を行う「Calculator」クラスを作成してください。それぞれのオペレーションに対して適切な関数シグネチャを用意してください。
*/

#include <iostream>

class Calculator {
public:
    // 整数の加算
    int add(int a, int b) {
        return a + b;
    }

    // 浮動小数点数の加算
    double add(double a, double b) {
        return a + b;
    }

    // 整数の減算
    int subtract(int a, int b) {
        return a - b;
    }

    // 浮動小数点数の減算
    double subtract(double a, double b) {
        return a - b;
    }

    // 整数の乗算
    int multiply(int a, int b) {
        return a * b;
    }

    // 浮動小数点数の乗算
    double multiply(double a, double b) {
        return a * b;
    }

    // 整数の除算
    int divide(int a, int b) {
        if (b == 0) {
            std::cerr << "Error: Division by zero is not allowed!" << std::endl;
            return 0;
        }
        return a / b;
    }

    // 浮動小数点数の除算
    double divide(double a, double b) {
        if (b == 0.0) {
            std::cerr << "Error: Division by zero is not allowed!" << std::endl;
            return 0.0;
        }
        return a / b;
    }
};

int main() {
    Calculator calc;

    int int_a = 10, int_b = 5;
    double double_a = 7.0, double_b = 3.0;

    std::cout << "Integer operations:" << std::endl;
    std::cout << "Addition: " << calc.add(int_a, int_b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(int_a, int_b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(int_a, int_b) << std::endl;
    std::cout << "Division: " << calc.divide(int_a, int_b) << std::endl;

    std::cout << "\nFloating-point operations:" << std::endl;
    std::cout << "Addition: " << calc.add(double_a, double_b) << std::endl;
    std::cout << "Subtraction: " << calc.subtract(double_a, double_b) << std::endl;
    std::cout << "Multiplication: " << calc.multiply(double_a, double_b) << std::endl;
    std::cout << "Division: " << calc.divide(double_a, double_b) << std::endl;

    return 0;
}
