#include <iostream>

using namespace std;

float marksPerc(float marks)
{
    return marks/6;
}

class Student
{
public:
    string name, bloodg;
    char div;
    int roll;
    float marks;
    static int count;

    friend float marksPerc(float marks);
    void acceptInfo()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter division: ";
        cin >> div;
        cout << "Enter total marks of 6 subjects: ";
        cin >> marks;
        cout << "Enter DOB: ";
        cin >> dob;
        cout << "Enter Aadhaar number: ";
        cin >> aadhaar;
        cout << "Enter blood group: ";
        cin >> bloodg;
        cout << "Enter contact address: ";
        cin >> address;
        cout << "Enter telephone number: ";
        cin >> tele;
        cout << endl;
    }

    void displayInfo()
    {
        cout << name << "\t\t" << roll << "\t\t" << div << "\t\t" << marksPerc(marks) << "\t\t" << dob;
        cout << "\t" << aadhaar << "\t" << bloodg << "\t\t" << address << "\t\t\t" << tele << endl;
    }

    static void displayCount()
    {
        cout << "Number of students added: " << count << endl;
    }

private:
    string dob, aadhaar, address, tele;
};

int Student::count;

int main()
{
    Student s[100];
    char cont = 'y';
    cout << endl << "Welcome to Student Information Systems" << endl << endl << "Start by adding a student:" << endl << endl;

    do
    {
        cout << "Enter details for Student " << ++Student::count << ":" << endl;
        s[Student::count - 1].acceptInfo();
        Student::displayCount();
        cout << "Would you like to another student? (Y/n): ";
        cin >> cont;
        cout << endl;
    } while (cont != 'n' && cont != 'N');
    
    cout << endl << "----------------------------- Student Information -----------------------------" << endl << endl;
    Student::displayCount();
    cout << endl << "Name\t\tRoll no.\tDivision\tMarks %\t\tDoB\t\tAadhaar number\tBlood group\tContact address\t\tTelephone no." << endl;

    for (int i = 0; i < Student::count; i++)
    {
        s[i].displayInfo();
    }

    cout << endl << endl << "Thank you for using Student Information Systems. Have a nice day!" << endl << endl;

    return 0;
}
