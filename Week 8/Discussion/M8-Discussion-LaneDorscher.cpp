#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Address
{
private:
    string street;
    string city;
    string state;
    string zip;

public:
    Address() {}

    Address(string street, string city, string state, string zip)
        : street(street), city(city), state(state), zip(zip) {
    }

    string GetFullAddress() const
    {
        return street + ", " + city + ", " + state + " " + zip;
    }
};

class Student
{
    private string firstName;
    private string lastName;
    private float gpa;
    private Address mailingAddr;

public:
    Student(string fName, string lName, float g, Address addr)
        : firstName(fName), lastName(lName), mailingAddr(addr)
    {
        SetGpa(g);
    }

    void SetGpa(float g)
    {
        if (g < 0.0) g = 0.0;
        if (g > 4.0) g = 4.0;
        gpa = g;
    }

    string GetFirstName() const { return firstName; }
    string GetLastName() const { return lastName; }
    float GetGpa() const { return gpa; }
    Address GetAddress() const { return mailingAddr; }

    void Print() const
    {
        cout << left << setw(12) << firstName
            << setw(12) << lastName
            << setw(6) << fixed << setprecision(2) << gpa
            << mailingAddr.GetFullAddress()
            << endl;
    }
};

int main()
{
    Student[] students = {
        Student("John", "Doe", 3.6, Address("123 Main St", "Omaha", "NE", "68102"));
        Student("Jane", "Smith", 3.9, Address("456 Oak Ave", "Lincoln", "NE", "68508"));
        Student("Mike", "Brown", 2.8, Address("789 Pine Rd", "Bellevue", "NE", "68005"));
    };

    // create record header
    cout << left << setw(12) << "First Name"
        << setw(12) << "Last Name"
        << setw(6) << "GPA"
        << "Address" << endl;
    cout << string(70, '-') << endl;

    //print student records
    for (Student s : students)
        s.Print();

    return 0;
}