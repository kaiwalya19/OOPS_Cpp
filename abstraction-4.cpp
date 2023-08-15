#include <iostream>
using namespace std;

// Abstract class
// contract class
class AbstractEmployee
{
    // virtual function which compulsary class to implement this method in it.
    // whoever class sign this contract will have to implement this below method (must)

    virtual void AskForPromotion() = 0;
};

// Employee : AbstractEmployee

class Employee : AbstractEmployee
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

    // Abstract class method implementation is must for whoever class will contract with abstract class.
    void AskForPromotion()
    {
        if (Age > 25)
            cout << "you are eligible for promotion !!" << endl;
        else
            cout << "sorry you are not eligible!!" << endl;
    }
};
int main()
{
    Employee emp1 = Employee("Kaiwalya", 28, "INFOSYS");
    Employee emp2 = Employee("KK", 25, "GOOGLE");
    Employee emp3 = Employee("JJ", 20, "WIPRO");

    emp1.AskForPromotion();
    emp3.AskForPromotion();

    return 0;
}