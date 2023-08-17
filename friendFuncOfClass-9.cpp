#include <iostream>
using namespace std;

// friend function of class
class Student
{
public:
    string name;
    string rollno;

    Student(string Name, string Roll)
    {
        name = Name;
        rollno = Roll;
    }

    friend void printStudent(string, string);
};

void printStudent(string name, string roll)
{

    cout << name << endl;
    cout << roll << endl;
}

int main()
{

    Student s = Student("kk", "19");

    printStudent(s.name, s.rollno);

    return 0;
}