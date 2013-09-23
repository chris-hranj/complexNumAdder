// Name: Christopher Hranj
// Course: CSC 260
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Last modified on: 4/16/13
// Description: Driver class that prompts the user for input to create two matrices
//				and manipulates the arrays in various ways.
// Filename: driver.cpp

#include <fstream>
#include <iomanip>
#include <iostream>
#include "Matrix.h"

using namespace std;
int main()
{
	//file matrix input
	string inFileName;
	ifstream inStr;
	bool worked = true;
	cout << "Please input a matrix from a file." << endl;
		do
		{
			cout << "Enter name of file to read from: ";
			cin >> inFileName;
			inStr.open (inFileName.c_str());

			if (inStr.fail())
			{
				cerr << "Error opening file. Try again." << endl;
				inStr.clear();
				inStr.ignore(80, '\n');
				worked = false;
			}
			else
				worked = true;
		} 
		while (!worked); //continues to ask for filename until file is found
		int n, j;
		inStr >> n >> j;
		Matrix m1(n,j);
		inStr >> m1;
		inStr.close();
		cout << "The matrix just read in: " << endl << m1 << endl;
	
	//manual matrix input
	Matrix m2;
	cout<<"Please input a matrix manually." << endl;
		int rowInput;
		int columnInput;
		
		cout<< "Enter the number of rows:" << endl;
		cin >> rowInput;
		if(cin.fail())
		{
			cout << "Incorrect input. Matrix was not populated." << endl;
		}
		else
		{
			cout << "Enter the number of columns:"<<endl;
			cin >> columnInput;
			if(cin.fail())
			{
				cout << "Incorrect input. Matrix was not populated." << endl;
			}
			else
			{
				Matrix mElse(rowInput,columnInput);
				cout << "Begin entering values for complex numbers (do not include 'i'):" << endl;
				cin >> mElse;
				if(cin.fail())
				{
					cout << "Incorrect input. Matrix was not populated." << endl;
				}
				else
				{
					cout << "The matrix just entered: " << endl << mElse << endl;
					m2 = mElse;
				}
			}
		}
	
	//manual complex number input
	cout<<"Please enter a complex number." << endl;
		double real; double imag;
		cin >> real >> imag;
		Complex c1(real, imag);
		cout << "The complex just entered: " << endl << c1 << endl << endl;
	
	//performing operations on the matrices and complex number.
	cout << "Beginning operations on the input information:" << endl << endl;
	
	cout << "Attempting to add your two matrices together:" << endl;
	Matrix m3 = m1+m2; 
	cout << m3 << endl;
	
	cout << "Adding your complex number and the first matrix:" << endl ;
	Matrix m4 = m1+c1; 
	cout << m4 << endl;
	
	cout << "Adding the above matrix to the complex number:" << endl;
	Matrix m5 = c1+m4; 
	cout << m5 << endl;
	
	cout << "Attempting to multiply your two matrices together:" << endl;
	Matrix m6 = m1*m2; 
	cout << m6 << endl;
		
	cout << "Multiplying the first matrix by the complex number:" << endl;
	Matrix m7 = m6*c1; 
	cout << m7 << endl;
	
	cout << "Multiplying a complex number by the above resulting matrix:" << endl;
	Matrix m8 = c1*m7; 
	cout << m8 << endl;
	
	
	
	cout << "Program complete. Thank you for playing." << endl;
    return 0;
}
