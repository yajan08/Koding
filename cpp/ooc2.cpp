#include <iostream>

using namespace std;

float marksPerc(float marks)
{
    return marks / 6;
}

class Student
{
private:
    string dob, aadhaar, address, tele;

public:
    string name, bloodg;
    char div;
    int roll;
    float marks;
    static int count;

    friend float marksPerc(float marks);

    void displayInfo()
    {
        cout << name << "\t\t" << roll << "\t\t" << div << "\t\t" << marksPerc(marks) << "\t\t" << dob;
        cout << "\t" << aadhaar << "\t" << bloodg << "\t\t" << address << "\t\t\t" << tele << endl;
    }

    static void displayCount()
    {
        cout << "Number of students added: " << count << endl;
    }

    Student()
    {
        name = "ABC";
        roll = 1;
        div = 'A';
        marks = 240;
        dob = "01-01-1990";
        aadhaar = "000000000000";
        bloodg = "A+";
        address = "Pune";
        tele = "0000000000";
        cout << "Student " << name << " added by Default Constructor" << endl;
        count++;
    }

    Student(string nm, int rl, char dv, float mrk, string DoB, string adhr, string bld, string add, string tel)
    {
        name = nm;
        roll = rl;
        div = dv;
        marks = mrk;
        dob = DoB;
        aadhaar = adhr;
        bloodg = bld;
        address = add;
        tele = tel;
        cout << "Student " << name << " added by Parametrized Contructor" << endl;
        count++;
    }

    Student(Student &p)
    {
        name = p.name;
        roll = p.roll;
        div = p.div;
        marks = p.marks;
        dob = p.dob;
        aadhaar = p.aadhaar;
        bloodg = p.bloodg;
        address = p.address;
        tele = p.tele;
        cout << "Student " << name << " added by Copy Constructor" << endl;
        count++;
    }

    ~Student()
    {
        cout << "Removed Student " << name << endl;
    }
};

int Student::count;

int main()
{
    Student s1;                                                                                // Default Constructor Implicit Call
    Student s2("ktk", 38, 'E', 560, "06-04-2004", "839384928492", "O+", "Pune", "7293749384"); // Parametrized Constructor Implicit Call
    Student s3(s2);                                                                            // Copy Constructor Call
    cout << endl << "Welcome to Student Information Systems" << endl << endl;

    cout << endl << "----------------------------- Student Information -----------------------------" << endl << endl;
    Student::displayCount();
    cout << endl << "Name\t\tRoll no.\tDivision\tMarks %\t\tDoB\t\tAadhaar number\tBlood group\tContact address\t\tTelephone no." << endl;

    s1.displayInfo();
    s2.displayInfo();
    s3.displayInfo();

    cout << endl << endl << "Thank you for using Student Information Systems. Have a nice day!" << endl << endl;

    return 0;
}                                                                                               // Destructor called automatically
