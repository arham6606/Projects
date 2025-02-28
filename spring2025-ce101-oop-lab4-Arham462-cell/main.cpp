#include "functions.h"

//int Book::bookCount = 0;

int main()
{
    // creating the objects of classes
    cout << "Current Book Count: " << Book::getBookCount() << endl;
    Book b1;
    b1.setTitle("Makers");
    b1.setAuthor("Arham");
    b1.setPages(500);
    cout << "Current Book Count: " << Book::getBookCount() << endl;
    Book b2 = b1;

    // displaying the data
    cout << "Book Name: " << b2.getTitle() << endl;
    cout << "Author Name: " << b2.getAuthor() << endl;
    cout << "Number of Pages: " << b2.getPages() << endl;
    cout << "Current Book Count: " << Book::getBookCount() << endl;
    // this condition is for book pages check
    if (b2.isThickBook())
    {
        cout << "The Book has more than 500 pages" << endl;
    }
    else
    {
        cout << "The Book has less than 500 pages" << endl;
    }

    cout << "Current Book Count: " << Book::getBookCount() << endl;

    // function calling
    cout<<"Below data is the copy of original"<<endl;
    Book b3 = duplicateBook(b2);
    cout<<b3.getAuthor()<<endl;
    cout<<b3.getBookCount()<<endl;
    cout<<b3.getPages()<<endl;
    cout<<b3.getTitle()<<endl;
}