// Name: Christopher Hranj
// Course: CSC 260
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Last modified on: 4/16/13
// Description: Prototype of a class that represents a complex number. 
// Filename: Complex.h
#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imag;
    
public:
    Complex(double = 0.0, double = 0.0);

    const Complex operator+(const Complex&) const;
    Complex operator=(const Complex&);
    friend const Complex operator+(double, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, Complex&);
    const Complex operator*(const Complex&) const;
};

