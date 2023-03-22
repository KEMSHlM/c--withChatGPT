#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0; // const を設定することで，データを変更しない
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;

    // デコンストラクタの基本的なものを明示的に支持することができる．
    // また，deleteを指定するとそのコンストラクタを禁止することができる．
    // 派生クラスのデコンストラクタは基底クラスのデコンストラクタも呼び出す．
    virtual ~Shape() = default;
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double area() const override {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }

    void printInfo() const override {   // << はオーバーロードらしい．
        std::cout << "Triangle: Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double side) : side(side) {}

    double area() const override {
        return side * side;
    }

    double perimeter() const override {
        return 4 * side;
    }

    void printInfo() const override {
        std::cout << "Square: Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void printInfo() const override {
        std::cout << "Circle: Area: " << area() << ", Perimeter: " << perimeter() << std::endl;
    }
};

int main() {
    // newが必要みたい
    Shape* shapes[] = {new Triangle(3, 4, 5), new Square(4), new Circle(5)};

    // Vector配列じゃなくても使えるみたい
    for (Shape* shape : shapes) {
        shape->printInfo();
        delete shape;
    }

    return 0;
}