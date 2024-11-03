#pragma once
#include <iosfwd>

namespace my {

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

	std::ostream &operator<<(std::ostream &out, const Complex &complex);
	Complex operator+(const Complex &c1, const Complex &c2);
	Complex operator+(const Complex &c1, const double &d);
	Complex operator+(const double &d, const Complex &c1);
}