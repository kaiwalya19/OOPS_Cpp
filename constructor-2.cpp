#include <iostream>
using namespace std;

// initializing data using constructor

class Employee
{
public:
    string Name;
    int Age;
    string Company;

    void print()
    {
        cout << "Name : " << Name << ", age : " << Age << " ,company : " << Company << endl;
    }

    // private:
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

    // instead initializing data multiple times ...use constructor

    return 0;
}