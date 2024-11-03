#include "Complex.h"
#include <iosfwd>
#include <iostream>


Complex::Complex() : real(0.f), imaginary(0.0) {


}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) : real(0.f), imaginary(0.0) {

	this->real = other.real;
	this->imaginary = other.imaginary;
}

const Complex &Complex::operator=(const Complex &other) {

	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

const std::ostream &operator<<(std::ostream &out, const Complex &complex) {
	return out << '(' << complex.GetReal() << ',' << complex.GetImaginary() << ')';
}
