
#include <iostream>
using namespace std;

/*
Copy of constructors

Rules
1) should be present in public
2) same name as class name
3) no return type

When copy constructor is invoked (used)?

1)  To create new objects based on already created object.
2)  both are same
    "Book book3(book2);" <==> "Book book3=book2;"
3)  When  we are passing  object to function by value,
    then copy constructor willbe  used.
    eg: void PrintBook(Book book)

4)  When  we are returning object by value,
    then copy constructor willbe  used.
 */

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
        Rates = new float[RatesCounter];
        Rates[0] = 5;
        Rates[1] = 4;
    }

    ~Book()
    {
        delete[] Rates;
        Rates = nullptr;
    }

    /* WRONG WAY
     Book(Book original)
     {
         Title = original.Title;
         Author = original.Author;
         Rates = original.Rates;
         RatesCounter = original.RatesCounter;
     } */

    // const : so no one can change data in address original
    // &     : to pass by reference
    Book(const Book &original)
    {
        Title = original.Title;
        Author = original.Author;
        RatesCounter = original.RatesCounter;

        /* wrong way : issue is here we are  refering
        same memory address of constructor to copy constructor data.
        once it got deleted we will not be able to access data
        as it not belong to our application. we are trying to access
        some other application data  here.

        Rates = original.Rates;
        */

        /* Correct way : is to get new memory address for copy constructor
        because once destructor called, constructor data will be erased and not accessible
        so we can not refer to same constructor memory address for copy constructor data.

        We must need to create new memory address for copy constructor.
        */

        Rates = new float[RatesCounter];
        for (int i = 0; i < RatesCounter; i++)
        {
            Rates[i] = original.Rates[i];
        }
    }
};

void PrintBook(Book book)
{
    cout << "printing a book details!!" << endl;
    cout << "title : " << book.Title << endl;
    cout << "author : " << book.Author << endl;
}

int main()
{

    Book book1("Millionaire Fastlane", "M.J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek F.");

    /*  both are same
    "Book book3(book2);" == "Book book3=book2;"
    */

    // Book book3(book2);
    Book book3 = book2;

    // passing Book class object in outside fucntion PrintBook()
    PrintBook(book1);
    PrintBook(book2);
    PrintBook(book3);

    return 0;
}