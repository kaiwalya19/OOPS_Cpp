#include <iostream>
using namespace std;

// Polymorphism explaination

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

    // Polymorphism  parent class
    // void Work1()  --->please go at the end to get info
    void Work1()
    {
        cout << Name << " is checking mails and doing the work!!" << endl;
        cout << "we are in parent Employee class\n"
             << endl;
    }

    virtual void Work2()
    {
        cout << Name << " is checking mails and doing the work!!" << endl;
        cout << "we are in parent Employee class\n"
             << endl;
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

    // Polymorphism
    // Work1() in child class Developer
    void Work1()
    {
        cout << Name << " is checking code and debuging !!" << endl;
        cout << "we are in child -> Developer class\n"
             << endl;
    }

    // Work2() in child class Developer
    virtual void Work2()
    {
        cout << Name << " is checking code and debuging !!" << endl;
        cout << "we are in child -> Developer class\n"
             << endl;
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

    // Polymorphism
    // void Work1() in child class Teacher
    void Work1()
    {
        cout << Name << " is teaching to students!!" << endl;
        cout << "we are in child Teacher class\n"
             << endl;
    }

    // virtual void Work2() in child class Teacher
    virtual void Work2()
    {
        cout << Name << " is teaching to students!!" << endl;
        cout << "we are in child Teacher class\n"
             << endl;
    }
};
// always remember class ends with ";"

int main()
{
    // Employee emp1 = Employee("Kaiwalya", 28, "INFOSYS");
    Developer d = Developer("KSK", 30, "GOOGLE", "C++");
    Teacher t = Teacher("Jai", 45, "Ambani school", "English");

    // Now we want "Work1()" method for perticular child class--> Developer
    t.Work1();
    d.Work1();

    cout << "\n\n\nPolymorphism" << endl;
    /* The most common use of polymorphism is when a
    parent class refering to a child class object
    eg.:
    Employee *e= &d; ---> this
    Employee *e= &emp1 ; --->  and not this
    */
    Employee *e1 = &d; // developer obj address
    Employee *e2 = &t; // teacher obj address
    cout << "\nWork1() method" << endl;
    e1->Work1(); // same result
    e2->Work1(); // same result

    /* Why not different result for below lines?

    e1->Work1();  // same result with parent class=> "void Work1()"
    e2->Work1();  // same result with parent class=> "void Work1()"

    Answer --> you have to make Work1() function virtual to get different result to make it
    as per child class methods
    */

    cout << "\nWork2() method" << endl;
    e1->Work2(); // different result with parent class=> "virtual void Work2()"
    e2->Work2(); // differnt result with parent class=> "virtual void Work2()"

    return 0;
}