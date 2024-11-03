#include "Complex.h"
#include "ccomplex"
#include <iosfwd>
#include <iostream>

using my::Complex;

Complex::Complex() : real(0.f), imaginary(0.0) {}

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

Complex::Complex(const Complex &other) : real(0.f), imaginary(0.0) {

	this->real = other.real;
	this->imaginary = other.imaginary;
}

const Complex &my::Complex::operator=(const Complex &other)  {

	if (this != &other) { // Check for self-assignment
		real = other.real;
		imaginary = other.imaginary;
	}
	return *this;
}

bool my::Complex::operator==(const Complex &other) const {
	return (real == other.real) && (imaginary == other.imaginary);
}

bool my::Complex::operator!=(const Complex &other) const {
	return !(*this==other);
}

std::ostream &my::operator<<(std::ostream &out, const Complex &complex) {
	return out << '(' << complex.GetReal() << ',' << complex.GetImaginary() << ')';
}

Complex my::operator+(const Complex &c1, const Complex &c2) {
	return Complex(c1.GetReal() + c2.GetReal(), c1.GetImaginary() + c2.GetImaginary());
}

Complex my::operator+(const Complex &c1, const double &d) {
	return Complex(c1.GetReal() + d, c1.GetImaginary());
}

Complex my::operator+(const double &d, const Complex &c1) {
	return Complex(c1.GetReal() + d, c1.GetImaginary());
}

