#include "Book.h"
using namespace std;
Book::Book() : title(""), author(""), isbn(""), publicationYear(0), genre(""), isAvailable(true) {}

Book::Book(string newtitle, string newauthor, string newisbn, int newyear, string newgenre, bool newisAvailable)
    : title(newtitle), author(newauthor), isbn(newisbn), publicationYear(newyear), genre(newgenre), isAvailable(newisAvailable) {}

string Book::getTitle() const { 
    return title; 
}
string Book::getAuthor() const { 
    return author; 
}
string Book::getISBN() const { 
    return isbn; 
}
int Book::getPublicationYear() const { 
    return publicationYear; 
}
string Book::getGenre() const { 
    return genre; 
}
bool Book::getAvailabilityStatus() const { 
    return isAvailable; 
}

void Book::setTitle(string newtitle) { 
    title = newtitle; 
}
void Book::setAuthor(string newauthor) { 
    author = newauthor; 
}
void Book::setISBN(string newisbn) { 
    isbn = newisbn; 
}
void Book::setPublicationYear(int newyear) { 
    publicationYear = newyear; 
}
void Book::setGenre(string newgenre) { 
    genre = newgenre; 
}
void Book::setAvailabilityStatus(bool newisAvailable) {
    isAvailable = newisAvailable;
}
