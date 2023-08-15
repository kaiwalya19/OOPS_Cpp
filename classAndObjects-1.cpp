#include <iostream>
using namespace std;

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
};
int main()
{
    Employee emp1;
    emp1.Age = 20;
    emp1.Company = "INFOSYS";
    emp1.Name = "Kaiwalya";
    emp1.print();

    Employee emp2;
    emp2.Age = 28;
    emp2.Company = "GOOGLE";
    emp2.Name = "KK";
    emp2.print();

    Employee emp3;
    emp3.Age = 32;
    emp3.Company = "WIPRO";
    emp3.Name = "JJ";
    emp3.print();

    // instead initializing data multiple times ...use constructor

    return 0;
}