// Name: Christopher Hranj
// Course: CSC 260
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Last modified on: 4/16/13
// Description: Prototype of a class that represents a matrix containing complex numbers. 
// Filename: Matrix.h
#include <iostream>
#include "Complex.h"

using namespace std;

class Matrix
{
private:
    int rows;
    int columns;
    Complex arr[10][15];
    
public:
    Matrix(int rows=10, int columns=15);
    
    Matrix operator=(const Matrix&);
    Matrix operator=(Complex&);
    
    Matrix operator+(const Matrix&);
    Matrix operator+(const Complex&);
    friend Matrix operator+(Complex&, const Matrix&);
    
    Matrix operator*(const Matrix&);
    Matrix operator*(const Complex&);
    friend Matrix operator*(Complex&, const Matrix&);
    
    friend istream& operator>>(istream&, Matrix&);
    friend ostream& operator<<(ostream&, Matrix&);
};

