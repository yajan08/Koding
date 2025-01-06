#include <iostream>

using namespace std;

class Complex
{
	float real, imaginary;
	
public:
	
	Complex()
	{
		real = 0;
		imaginary = 0;
	}
	
	void setComplex()
	{
		cout << endl << "Enter real part: ";
		cin >> real;
		cout << "Enter imaginary part: ";
		cin >> imaginary;
	}
	
	void printComplex()
	{
		cout << real;
		if (imaginary == -1)
			cout << " - i" << endl;
		else if (imaginary < 0)
			cout << " - i" << -imaginary << endl;
		else if (imaginary == 1)
			cout << " + i" << endl;
		else if (imaginary > 0)
			cout << " + i" << imaginary << endl;
		else
			cout << endl;
	}
	
	Complex operator + (Complex cmp1)
	{
		Complex cmpl;
		cmpl.real = real + cmp1.real;
		cmpl.imaginary = imaginary + cmp1.imaginary;
		return cmpl;
	}
	
	Complex operator * (Complex c1)
	{
		Complex cmpl;
		float a = real, b = imaginary, c = c1.real, d = c1.imaginary;
	    cmpl.real = (a * c) - (b * d);
	    cmpl.imaginary = (a * d) + (b * c);
		return cmpl;
	}
	
	friend Complex operator - (Complex c1, Complex c2);
	friend Complex operator / (Complex c1, Complex c2);
};

Complex operator - (Complex c1, Complex c2)
{
	Complex cmpl;
	cmpl.real = c1.real - c2.real;
	cmpl.imaginary = c1.imaginary - c2.imaginary;
	return cmpl;
}

Complex operator / (Complex c1, Complex c2)
{
	Complex cmpl;
	float a = c1.real, b = c1.imaginary, c = c2.real, d = c2.imaginary;
	cmpl.real = ((a * c) + (b * d)) / ((c * c) + (d * d));
	cmpl.imaginary = ((b * c) - (a * d)) / ((c * c) + (d * d));
	return cmpl;
}

int main()
{
	Complex c1, c2, c3;
	int choice;
	
	do {
		cout << endl << "Choose an operation on complex numbers:\n1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Exit\n\nYour choice: ";
		cin >> choice;
		
		switch (choice) {
		case 1:
			cout << endl << "Enter first number:";
			c1.setComplex();
			cout << endl << "Enter second number:";
			c2.setComplex();
			c3 = c1 + c2;
			cout << endl << "C1 = ";
			c1.printComplex();
			cout << "C2 = ";
			c2.printComplex();
			cout << endl << "C3 = C1 + C2 = ";
			c3.printComplex();
			break;
		case 2:
			cout << endl << "Enter first number:";
			c1.setComplex();
			cout << endl << "Enter second number:";
			c2.setComplex();
			c3 = c1 - c2;
			cout << endl << "C1 = ";
			c1.printComplex();
			cout << "C2 = ";
			c2.printComplex();
			cout << endl << "C3 = C1 - C2 = ";
			c3.printComplex();
			break;
		case 3:
			cout << endl << "Enter first number:";
			c1.setComplex();
			cout << endl << "Enter second number:";
			c2.setComplex();
			c3 = c1 * c2;
			cout << endl << "C1 = ";
			c1.printComplex();
			cout << "C2 = ";
			c2.printComplex();
			cout << endl << "C3 = C1 * C2 = ";
			c3.printComplex();
			break;
		case 4:
			cout << endl << "Enter first number:";
			c1.setComplex();
			cout << endl << "Enter second number:";
			c2.setComplex();
			c3 = c1 / c2;
			cout << endl << "C1 = ";
			c1.printComplex();
			cout << "C2 = ";
			c2.printComplex();
			cout << endl << "C3 = C1 / C2 = ";
			c3.printComplex();
			break;
		case 5:
			cout << endl << "You have chosen to exit.\nBye bye!" << endl << endl;
			return 0;
		default:
			cout << endl << "Invalid input. Try again!" << endl;
		}
	} while (choice != 5);
}
