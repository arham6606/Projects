#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;
#include <string>

class Book
{
private:
    // properties
    string title;
    string author;
    int pages;

    static int bookCount;

public:
    // default construtor
    Book()
    {
        title = "";
        author = "";
        pages = 0;
        bookCount++;
    }

    // parameterized constructor
    Book(string title1, string author1, int pages1)
    {
        title = title1;
        author = author1;
        pages = pages1;
        bookCount++;
    }

    // copy constructor
    Book(const Book &copy)
    {
        title = copy.title;
        author = copy.author;
        pages = copy.pages;
        bookCount++;
    }

    // destructor
    ~Book()
    {
        cout << "Destructior is called" << endl;
        bookCount--;
    }

    // member function
    inline bool isThickBook()
    {
        if (this->pages > 500)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // member function
    void setTitle(string t)
    {
        title = t;
    }

    // member function
    void setAuthor(string a)
    {
        author = a;
    }

    // member function
    void setPages(int p)
    {
        pages = p;
    }

    // member function
    string getTitle()
    {
        return title;
    }

    // member function
    string getAuthor()
    {
        return author;
    }

    // member function
    int getPages()
    {
        return pages;
    }

    // member function
    static int getBookCount()
    {
        return bookCount;
    }
};

// function declaration
Book duplicateBook(const Book& original);

#endif
