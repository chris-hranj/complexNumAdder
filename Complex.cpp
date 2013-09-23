// Name: Christopher Hranj
// Course: CSC 260
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Last modified on: 4/16/13
// Description: Complex class definition containing input, output, addition,
//				equality, and multiplication functions for two complex numbers.
// Filename: Complex.cpp

#include "Complex.h"
#include <iomanip>

Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}

//---------------------------------------------------------
// operator<< function will output a complex number depending
// on the values of the real and imaginary parts of the complex
// number.
//---------------------------------------------------------
ostream& operator<<(ostream& lhs, Complex& rhs)
{
    if (rhs.real !=0)
    {
        lhs << fixed << setprecision(2) << rhs.real;
    	if (rhs.imag < 0)
    		lhs << rhs.imag << "i";
    	else if (rhs.imag > 0)
    		lhs << "+" << rhs.imag << "i";
    	else
    		lhs << "\t";
    }
    else
    {
    	if (rhs.imag != 0)
    	    lhs << rhs.imag << "i" << "\t";
    	else
    		lhs << 0 << "\t";
    }
    return lhs;
}

//---------------------------------------------------------
// operator>> allows input from a file or from the user
// and will create of Complex number object from the input 
//---------------------------------------------------------
istream& operator>>(istream& lhs, Complex& rhs)
{
    lhs >> rhs.real >> rhs.imag;
    return lhs;
}

//---------------------------------------------------------
// operator+ will add two complex numbers together and return the
// retult as a new Complex object.
//---------------------------------------------------------
const Complex Complex::operator+(const Complex& rhs) const
{
    return (Complex (real + rhs.real, imag + rhs.imag));
}

//---------------------------------------------------------
// operator+ will add a double to a complex number and return the
// retult as a new Complex object.
//---------------------------------------------------------
const Complex operator+(double lhs, const Complex& rhs)
{
    Complex result;
    result.real = lhs + rhs.real;
    result.imag = rhs.imag;
    return result;
}

//---------------------------------------------------------
// operator* will multiply two complex number together
// and return the result.
//---------------------------------------------------------
const Complex Complex::operator*(const Complex& rhs) const
{
	Complex result;
	double realPart1 = real*rhs.real;
	double realPart2 = -(imag*rhs.imag);
	double imagPart1 = real*rhs.imag;
	double imagPart2 = imag*rhs.real;
	result.real = realPart1+realPart2;
	result.imag = imagPart1+imagPart2;
	return result;
}

//---------------------------------------------------------
// operator= will set the real and imaginary parts of one
// complex number to the real and imaginary parts of another
// complex number.
//---------------------------------------------------------
Complex Complex::operator=(const Complex& rhs)
{
    real = rhs.real;
    imag = rhs.imag;
    return *this;
}
