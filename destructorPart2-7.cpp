
#include <iostream>
using namespace std;

// Destructor with pointers
// We release memory in class destructor
// Destructor is mandatory in case pointers are used in class.

class Book
{
public:
    string Title;
    string Author;
    float *Rates;
    int RatesCounter;

    Book(string title, string author)
    {
        Title = title;
        Author = author;

        RatesCounter = 2;
        Rates = new float[RatesCounter]; // "new" IMP TO MENTION TO GET NEW MEMORY.
        Rates[0] = 5;
        Rates[1] = 4;
    }

    ~Book()
    {
        delete[] Rates;  // "[]" IMP TO WRITE TO DELETE ALL ELEMENTS IN ARRAY
        Rates = nullptr; // IMP
    }
};

int main()
{

    Book book1("Millionaire Fastlane", "M.J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek F.");

    return 0;
}