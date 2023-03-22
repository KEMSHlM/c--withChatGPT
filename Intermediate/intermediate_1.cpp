#include <iostream>

class Car {
    protected:
        std::string name;
        int year;
        double mileage;

    public:
        Car(const std::string& name, int year)
            : name(name), year(year) {}
        void print();
        void update(double addDistance);
};

void Car::print() {
    std::cout << "Name : " << name << " , Year : " << year << " , Mileage : " << mileage << std::endl;
}

void Car::update (double addDistance) {
    mileage += addDistance; 
}

class ElectricCar : public Car {
    public:
        ElectricCar(const std::string& name, int year, double capacity)  
            : Car(name, year), capacity(capacity) {} // Carのメンバー変数に代入つつ，ElectricCarをコンストラクトしている
    private:
        double capacity; 
};

int main (void) {
    Car A("XV", 2015);
    A.update(100.0);
    ElectricCar B("Leaf", 2018, 500); 
    B.update(100.0);
    
    A.print();
    B.print();
    
    return 0; 
}