// Name: Christopher Hranj
// Course: CSC 260
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Last modified on: 4/16/13
// Description: Matrix class definition containing input, output, addition,
//				equality, and multiplication functions.
// Filename: Matrix.cpp

#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int r, int c)
{
    rows = r;
    columns = c;
    Complex arr[r][c];
}

//---------------------------------------------------------
// operator<< will loop through the contents of a matrix
// and return a two dimensional array
//---------------------------------------------------------
ostream& operator<<(ostream& lhs, Matrix& rhs)
{
    for(int i=0; i < rhs.rows; i++)
    {
    	for(int j=0; j < rhs.columns; j++)
    	{
    		lhs << rhs.arr[i][j] << "\t";
    	}
    	lhs << endl;
    }
    return lhs;
}

//---------------------------------------------------------
// operator>> will loop through the contents of a matrix
// and return a two dimensional array
//---------------------------------------------------------
istream& operator>>(istream& lhs, Matrix& rhs)
{
	for(int i=0; i < rhs.rows; i++)
	    {
	    	for(int j=0; j < rhs.columns; j++)
	    	{
	    		 lhs >> rhs.arr[i][j];	
	    	}
	    }
    return lhs;
}

//---------------------------------------------------------
// operator+ will loop through the contents of two matrices
// and add the contents of each location together and return
// the results in a new matrix.
//---------------------------------------------------------
Matrix Matrix::operator+(const Matrix& rhs)
{
	if(rows==rhs.rows && columns==rhs.columns)
	{
		Matrix result;
		result.rows = rows;
		result.columns = columns;
		for(int i=0; i < rows; i++)
	    {
	    	for(int j=0; j < columns; j++)
	    	{
	    		result.arr[i][j] = arr[i][j] + rhs.arr[i][j];
	    	}
	    }
		return result;
	}
	else
	{
		cout << "Matrices could not be added because they are different sizes." << endl;
		cout << "Returning the calling matrix:" << endl;
		return *this;
	}
}

//---------------------------------------------------------
// operator+ will add the same complex number to every complex
// number of a matrix.
//---------------------------------------------------------
Matrix Matrix::operator+(const Complex& lhs)
{
	Matrix result;
	result.rows = rows;
	result.columns = columns;
	for(int i=0; i < rows; i++)
	{
		for(int j=0; j < columns; j++)
		{
			result.arr[i][j] = arr[i][j] + lhs;
		}  
	}
	return result;	
}

//---------------------------------------------------------
// operator+ will allow a matrix to be added to a complex number
//---------------------------------------------------------
Matrix operator+(Complex& rhs, const Matrix& lhs)
{
	Matrix result;
	result.rows = lhs.rows;
	result.columns = lhs.columns;
	for(int i=0; i < lhs.rows; i++)
	{
		for(int j=0; j < lhs.columns; j++)
		{
			result.arr[i][j] = lhs.arr[i][j] + rhs;
		}  
	}
	return result;	
}

//---------------------------------------------------------
// operator* will multiply two matrices together and return 
// the result
//---------------------------------------------------------
Matrix Matrix::operator*(const Matrix& rhs)
{
	if(columns==rhs.rows)
	{
		Matrix result;
		result.rows = rows;
		result.columns = rhs.columns;
		for(int i=0; i < result.rows; i++)
	    {
	    	for(int j=0; j < result.columns; j++)
	    	{
	    		Complex result2;
	    		for(int k=0; k<rhs.rows; k++) //matrix multiplaction algorithm begins here
	    		{	
	    			result2 = (result2 + (arr[i][k]*rhs.arr[k][j]));
	    		}
	    		result.arr[i][j]=result2;
	    	}
	    }
		return result;
	}
	else
	{
		cout << "Matrices could not be multiplied because they are not the correct sizes." << endl;
		cout << "Returning the calling matrix:" << endl;
		return *this;
	}
}

//---------------------------------------------------------
// operator* will multiply the same complex number by 
// every element of a matrix and return the result
//---------------------------------------------------------
Matrix Matrix::operator*(const Complex& rhs)
{
		Matrix result;
		result.rows = rows;
		result.columns = columns;
		for(int i=0; i < rows; i++)
	    {
	    	for(int j=0; j < columns; j++)
	    	{
	    		result.arr[i][j] = (arr[i][j]*rhs);
	    	}
	    }
		return result;
}

//---------------------------------------------------------
// operator* will multiply a matrix by the same complex number
//---------------------------------------------------------
Matrix operator*(Complex& rhs, const Matrix& lhs)
{
	Matrix result;
	result.rows = lhs.rows;
	result.columns = lhs.columns;
	for(int i=0; i < lhs.rows; i++)
	{
		for(int j=0; j < lhs.columns; j++)
		{
			result.arr[i][j] = (lhs.arr[i][j]*rhs);
		}
	}
	return result;	
}

//---------------------------------------------------------
// operator= will set two matrices equal to eachother 
// by looping through the contents of one array and setting
// every complex number equal to it in the other matrix.
//---------------------------------------------------------
Matrix Matrix::operator=(const Matrix& rhs)
{
    rows = rhs.rows;
    columns = rhs.columns;
    for(int i=0; i < rhs.rows; i++)
	    {
	    	for(int j=0; j < rhs.columns; j++)
	    	{
	    		arr[i][j] = rhs.arr[i][j];
	    	}
	    }
    return *this;
}

//---------------------------------------------------------
// operator= will set every complex number in a matrix equal
// to the same complex number.
//---------------------------------------------------------
Matrix Matrix::operator=(Complex& lhs)
{
    for(int i=0; i < rows; i++)
	    {
	    	for(int j=0; j < columns; j++)
	    	{
	    		arr[i][j] = lhs;
	    	}
	    }
    return *this;
}
