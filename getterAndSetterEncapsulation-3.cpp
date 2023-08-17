#include <iostream>
using namespace std;

// initializing data using constructor

class Employee
{
    // public:
private:
    string Name;
    int Age;
    string Company;

public:
    // Functions for setting values and getting values (always keep data (values) private)
    // Always access private data using public get and set class methods

    // Setter methods for all private data variables
    void setName(string name)
    {
        Name = name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    void setAge(int age)
    {
        Age = age;
    }

    // Getter methods for all private data variables
    string getName()
    {
        return Name;
    }
    string getCompany()
    {
        return Company;
    }
    int getAge()
    {
        return Age;
    }

    // print data
    void print()
    {
        cout << "Name : " << Name << ", age : " << Age << " ,company : " << Company << endl;
    }

    // constructor for Employee class (public)
    //  private:
    Employee(string name, int age, string company)
    {
        Name = name;
        Age = age;
        Company = company;
    }
};
int main()
{
    Employee emp1 = Employee("Kaiwalya", 20, "INFOSYS");
    /* emp1.Age = 20;
    emp1.Company = "INFOSYS";
    emp1.Name = "Kaiwalya"; */
    emp1.print();

    Employee emp2 = Employee("KK", 28, "GOOGLE");
    /* emp2.Age = 28;
    emp2.Company = "GOOGLE";
    emp2.Name = "KK"; */
    emp2.print();

    Employee emp3 = Employee("JJ", 32, "WIPRO");
    /* emp3.Age = 32;
    emp3.Company = "WIPRO";
    emp3.Name = "JJ"; */
    emp3.print();

    emp3.setAge(50);
    emp3.setCompany("ORACLE");
    cout << "\nPrinting data using getter and setter" << endl;
    cout << "Employee " << emp3.getName() << " is " << emp3.getAge() << " years old\n"
         << endl;

    return 0;
}