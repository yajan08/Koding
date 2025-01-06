#include <iostream>

using namespace std;

class Employee
{
	string Ename;
	int EmpID;

public:

	Employee()
	{
		Ename = "ABC";
		EmpID = 0;
	}
	
	Employee(string name, int id)
	{
		Ename = name;
		EmpID = id;
	}
	
	void displayInfo()
	{
		cout << "\nEmployee ID: " << EmpID << "\nEmployee Name: " << Ename;

	}
	
	void earnings();
};

class SalariedEmployee : public Employee
{
	double weeklySalary;
	
public:

	SalariedEmployee()
	{
		weeklySalary = 0;
	}
	
	SalariedEmployee(string name, int id, double weekly) : Employee(name, id)
	{
		weeklySalary = weekly;
	}
	
	void earnings()
	{
		cout << "\nWeekly Salary: " << weeklySalary << endl;
	}
	
	void displayInfo()
	{
		Employee :: displayInfo();
		cout << "\nEmployee type: Salaried";
		earnings();
	}
};

class HourlyEmployee : public Employee
{
	double wage, hours, hourlySalary;
	
public:
	
	HourlyEmployee()
	{
		wage = 0;
		hours = 0;
	}
	
	HourlyEmployee(string name, int id, double w, double hrs) : Employee(name, id)
	{
		wage = w;
		hours = hrs;
	}
	
	void earnings()
	{
		if (hours < 40)
			hourlySalary = hours * wage;
		else
			hourlySalary = (40 * wage) + ((hours - 40) * wage * 1.5);
			
		cout << "\nHourly Salary: " << hourlySalary << endl;
	}
	
	void displayInfo()
	{
		Employee :: displayInfo();
		cout << "\nEmployee type: Hourly";
		earnings();
	}
};

class CommissionEmployee : public Employee
{
	double grossSales, commissionRate, commissionSalary;
	
public:
	
	CommissionEmployee()
	{
		grossSales = 0;
		commissionRate = 0;
	}
	
	CommissionEmployee(string name, int id, double gross, double rate) : Employee(name, id)
	{
		grossSales = gross;
		commissionRate = rate;
	}
	
	void earnings()
	{
		commissionSalary = grossSales * commissionRate;
		cout << "\nCommission Salary: " << commissionSalary << endl;
	}
	
	void displayInfo()
	{
		Employee :: displayInfo();
		cout << "\nEmployee type: Commission";
		earnings();
	}
};

int main()
{
	SalariedEmployee A("ABC", 10, 5000);
	
	HourlyEmployee B("AAA", 20, 300, 50);
	
	CommissionEmployee C("BBB", 30, 400, 60);
	
	SalariedEmployee D;
	HourlyEmployee E;
	CommissionEmployee F;
	
	cout << "\nObjects created using Parametrized Constructor:" << endl;
	
	A.displayInfo();
	B.displayInfo();
	C.displayInfo();
	
	cout << "\nObjects created using Default Constructor:" << endl;
	
	D.displayInfo();
	E.displayInfo();
	F.displayInfo();
	
	cout << endl;
	
	return 0;
}
