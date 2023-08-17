#include <iostream>
using namespace std;

// Virtual Function use case
// if function is virtual in parent class
// then child class can use then even if function is not present in child class
// for eg. in Student class print() function in commented but still its working and calling
// from parent class School.

class School
{
public:
    string SchoolName;
    string location;
    string ranking;

    virtual void print()
    {
        cout << " School Name is : " << SchoolName << endl;
        cout << " School location is : " << location << endl;
        cout << " School ranking is : " << ranking << endl;
    }
};

class Teacher : public School
{
public:
    string TeacherName;
    string mobileNo;

    void print()
    {
        cout << " Teacher Name is : " << TeacherName << endl;
        cout << " Teacher mobile no is : " << mobileNo << endl;
    }
};

class Student : public School
{
public:
    string StudName;
    string rollNo;

    // void print()
    // {
    //     cout << "\nStudent name is : " << StudName << endl;
    //     cout << "\nStudent roll no is : " << rollNo << endl;
    // }
};

int main()
{

    School *s1 = new Teacher();
    School *s2 = new Student();

    s1->print();
    s2->print();
    cout << "\n"
         << endl;
    // school obj array
    School *s[2] = {s1, s2};

    for (int i = 0; i < 2; i++)
    {
        s[i]->print();
    }

    return 0;
}