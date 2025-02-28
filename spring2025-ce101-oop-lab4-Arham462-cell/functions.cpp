#include "functions.h"

int Book::bookCount = 0;
Book duplicateBook(const Book& original) 
{
    return Book(original);
}
 