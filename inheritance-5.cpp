#include <iostream>
using namespace std;

// Inheritance explaination

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
    // string Name;  // ONLY for parent class method access
    int Age;
    string Company;

protected:
    string Name; // child class can also access this variable

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

// class   child : Parent
// class Developer : Employee

// Made parent class public to access parent methods for child class
class Developer : public Employee
{
public:
    string FavProgLang;

    void FixBug()
    {
        // use private to get property values using parent methods only
        cout << getName() << " is fixed bug in " << FavProgLang << " !!" << endl;

        // use protected to get parent property values directly without using getter and setter
        // eg : Name
        cout << Name << " is fixed bug in " << FavProgLang << " !!" << endl;
    }

    // Cnstructor child.
    // PARENT class property access in CHILD class
    Developer(string name, int age, string company, string favProgLang)
        : Employee(name, age, company)
    {

        // ONLY child class property initialiazation
        FavProgLang = favProgLang;
    }
};

// child class Teacher

class Teacher : public Employee
{
public:
    string Subject;
    void subjectTeacherName()
    {
        cout << Name << " is teaching " << Subject << endl;
    }

    Teacher(string name, int age, string company, string subject)
        : Employee(name, age, company)
    {
        Subject = subject;
    }
};
// always remember class ends with ";"

int main()
{
    Employee emp1 = Employee("Kaiwalya", 28, "INFOSYS");
    Developer d = Developer("KSK", 30, "GOOGLE", "C++");
    /* child object not able to access methods of parent class
    example:
    d.AskForPromotion();

    Because by Default parent class methods are private so make class public
    for child classs to access its members methods */

    // example
    // class Developer :public  Employee
    d.FixBug();
    d.AskForPromotion();

    Teacher t = Teacher("Jai", 45, "Ambani school", "English");
    t.AskForPromotion();
    t.subjectTeacherName();

    return 0;
}