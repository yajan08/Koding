#include <iostream>
#include <string>
#include <list>
#include <iomanip>

using namespace std;

class items
{
public:

	list<int> item_code;
	list<string> item_name;
	list<int> item_qty;
	list<float> item_cost;
	
	list<int>::iterator itr_code;
	list<string>::iterator itr_name;
	list<int>::iterator itr_qty;
	list<float>::iterator itr_cost;
	
	void get_itemlist();
	void display_itemall();
	void searchlist();
};

void items::get_itemlist()
{
	int count, code, qty;
	string name;
	float cost;
	cout << endl << "Enter the number of item records for Inventory: ";
	cin >> count;
	
	for (int i = 1; i <= count; i++) {		
		cout << endl << "Enter item code: ";
		cin >> code;
		item_code.push_back(code);
		
		cout << "Enter item name: ";
		cin >> name;
		item_name.push_back(name);
		
		cout << "Enter item quantity: ";
		cin >> qty;
		item_qty.push_back(qty);
		
		cout << "Enter item cost: ";
		cin >> cost;
		item_cost.push_back(cost);
	}
	
	cout << endl << count << " items have been added successfully." << endl;
}

void items::display_itemall() {
	itr_code = item_code.begin();
	itr_name = item_name.begin();
	itr_qty = item_qty.begin();
	itr_cost = item_cost.begin();
	
	cout << endl << "Displaying all items:" << endl << endl << "Item Code\tName\t\tQuantity\tCost" << endl;
	while (itr_code != item_code.end()) {
		cout << "    " << *itr_code << "\t\t" << *itr_name << "\t\t" << *itr_qty << "\t\t" << *itr_cost << endl;
		itr_code++;
		itr_name++;
		itr_qty++;
		itr_cost++;
	}
}

void items::searchlist()
{
	int key, qty;
	float cost;
	cout << endl << "Enter item code to be searched: ";
	cin >> key;
	
	itr_code = item_code.begin();
	itr_name = item_name.begin();
	itr_qty = item_qty.begin();
	itr_cost = item_cost.begin();
	
	while (itr_code != item_code.end()) {
		if (key == *itr_code) {
			cout << "Item code: " << *itr_code << endl;
			cout << "Item name: " << *itr_name << endl;
			cout << "Item quantity: " << *itr_qty << endl;
			cout << "Item cost: " << *itr_cost << endl;
			break;
		}
		itr_code++;
		itr_name++;
		itr_qty++;
		itr_cost++;
	}
	
	if (itr_code == item_code.end()) {
		cout << endl << "Item with the given code could not be found!" << endl << endl;
		return;
	}
	
	cout << endl << "Enter purchase quantity: ";
	cin >> qty;
	
	if (qty > *itr_qty)
		cout << endl << "Insufficient quantity." << endl;
	else {
		cost = *itr_cost * (float)qty;
		*itr_qty -= qty;
		cout << "Remaining quantity: " << *itr_qty << endl;
		cout << endl << "Purchase cost: " << cost << endl;
	}
}

int main()
{
	items obj;
	int choice;
	
	cout << endl << "---------------------------------------------------------------------------------------------------";
	cout << endl << "                                    Inventory Management System                                    ";
	cout << endl << "---------------------------------------------------------------------------------------------------" << endl;
	
	while (1) {
		cout << endl
			 << "Choose operation:" << endl 
			 << "1 - Add items" << endl 
			 << "2 - Display all items" << endl 
			 << "3 - Search for an item code" << endl 
			 << "4 - Exit" << endl 
			 << endl 
			 << "Your choice: ";
		cin >> choice;
		
		switch (choice) {
		case 1:
			obj.get_itemlist();
			break;
			
		case 2:
			if (obj.item_code.size() == 0) {
				cout << endl << "No records to display." << endl << endl;
			}
			else
				obj.display_itemall();
			break;
			
		case 3:
			obj.searchlist();
			break;
			
		case 4:
			cout << endl << "You have chosen to exit." << endl << "Bye bye." << endl << endl;
			return 0;
			
		default:
			cout << endl << "Invalid input! Try again." << endl;
		}
	}
}
