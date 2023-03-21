#include <iostream>
#include <math.h>

class Circle {
    public:
        Circle(double r);
        void calculation(std::ostream *os);

    private:
        double r;
};

Circle::Circle (double r) {
    this->r = r;
}

void Circle::calculation (std::ostream *os) {
    *os << "Area is " << M_PI * this->r * this->r << "\n";
    *os << "Circumferenc is " << 2 * M_PI * this->r << "\n";
}

#define R 10

int main (void) {
    Circle A(R);
    A.calculation(&std::cout);

    return 0;
}