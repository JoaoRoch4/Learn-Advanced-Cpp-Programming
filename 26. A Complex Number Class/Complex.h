#pragma once
#include <iosfwd>

class Complex {

private:

	double real;
	double imaginary;

public:

	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);

	inline double GetReal() const { return real; }
	inline double GetImaginary() const { return imaginary; }
};

const std::ostream &operator<<(std::ostream &out, const Complex &complex);