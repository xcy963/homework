#include <iostream>
using namespace std;
struct mycomplex {
    double real;
    double imag;
    mycomplex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    mycomplex operator+(const mycomplex& other) const {
        return mycomplex(real + other.real, imag + other.imag);
    }
    mycomplex operator-(const mycomplex& other) const {
        return mycomplex(real - other.real, imag - other.imag);
    }
    mycomplex operator*(const mycomplex& other) const {
        return mycomplex(real * other.real - imag * other.imag,
                         real * other.imag + imag * other.real);
    }

    mycomplex operator/(const mycomplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::runtime_error("zero");
        }
        return mycomplex((real * other.real + imag * other.imag) / denominator,
                         (imag * other.real - real * other.imag) / denominator);
    }
};

int main() {
    mycomplex a(1, 2), b(0, 0);
    mycomplex c;
    c = a / b;
    return 0;
}