#include <iostream>
using namespace std;

/*
Destructor  7 RULES [ IMP ]

1) Destructor always starts with "~".
2) Destructor and constructor do not have any return type.
3) Name of the constructor and destructor is the same as the class name.
4) Destructor does not require any input parameter.
5) Destructor is a member function of the class.
6) Destructor needs to be placed is always a public member.
7) Multiple constructors are possible in one class, but Destructor should be only one.
***********************************************************************************
8) Compiler is very smart. if no pointers used in class, then it will call
destructor automatically (no need to mention in class). but if pointer are used in class then destructor is must.
To avoid memory leaks.
************************************************************************************
9) Destructor called like stack [FILO]
************************************************************************************
try to understand using breakpoints

 */

class Book
{
public:
    string Title;
    string Author;

    Book(string title, string author)
    {
        Title = title;
        Author = author;
        cout << "\nwe are in constructor" << endl;
    }

    ~Book()
    {
        cout << "\nwe are in destructor" << endl;
    }
};

int main()
{
    Book b1 = Book("let us c++", "Yeshwant Kanitkar");
    Book b2 = Book("Automic habits", "James clear");
    return 0;
}