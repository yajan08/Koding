#include <iostream>
#include <string>

using namespace std;

class Hotel {
	string cust_name, city, room_type;
	int cust_id, age, d;
	double income;
	
public:
	
	Hotel()
	{
		cust_name = "ABC";
		cust_id = 0;
		city = "Pune";
		room_type = "Deluxe";
		income = 50000;
		age = 30;
		d = 0;
	}
	
	void accept()
	{
		cout << endl << "Enter Customer id: ";
		cin >> cust_id;
		cout << "Enter Customer name: ";
		cin >> cust_name;
	}
	
	void getage()
	{
		try {
			cout << "Enter age: ";
			cin >> age;
			
			if (age < 18 || age > 50)
				throw(age);
			else
				d++;
		}
		
		catch(int i) {
			cout << "Age is not between 18 and 50." << endl;
		}
	}
	
	void getincome()
	{
		try {
			cout << "Enter income: ";
			cin >> income;
			
			if (income < 50000 || income > 100000)
				throw(income);
			else
				d++;
		}
		
		catch(double i) {
			cout << "Income is not between 50000 and 100000." << endl;
		}
	}
	
	void getcity()
	{
		try {
			cout << "Enter city: ";
			cin >> city;
			
			if (city != "Pune" && city != "Mumbai")
				throw(city);
			else
				d++;
		}
		
		catch(string s) {
			cout << "City is not Pune or Mumbai." << endl;
		}
	}
	
	void getroom_type()
	{
		try {
			cout << "Enter room type: ";
			cin >> room_type;
			
			if (room_type != "Deluxe" && room_type != "SuperDeluxe")
				throw(room_type);
			else
				d++;
		}
		
		catch(string s) {
			cout << "Room type is not Deluxe or SuperDeluxe." << endl;
		}
	}
	
	void display()
	{
		if (d == 4) {
			cout << endl << "All details are correct." << endl;
			cout << endl << "Customer ID: " << cust_id;
			cout << endl << "Name: " << cust_name;
			cout << endl << "Age: " << age;
			cout << endl << "Income: " << income;
			cout << endl << "City: " << city;
			cout << endl << "Room type: " << room_type << endl;
		} else
			cout << endl << "Entered details do not fulfill our criteria." << endl;
	}
};

int main()
{
	Hotel customer;
	cout << endl << "Enter customer details:" << endl;
	customer.accept();
	customer.getage();
	customer.getincome();
	customer.getcity();
	customer.getroom_type();
	customer.display();
	cout << endl;
	return 0;
}
