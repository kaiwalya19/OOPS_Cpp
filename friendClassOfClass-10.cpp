#include <iostream>
using namespace std;

// friend class of class
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
    // friend class Print
    friend class Print;
};

class Print
{
public:
    void printStudent(string name, string roll)
    {

        cout << name << endl;
        cout << roll << endl;
    }
};

int main()
{

    Student s = Student("kk", "19");

    Print p;

    p.printStudent(s.name, s.rollno);

    return 0;
}