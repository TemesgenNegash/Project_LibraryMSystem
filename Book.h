#pragma once
#include <string>
using namespace std;

class Book {
public:
    Book();
    Book(string newtitle, string newauthor, string newisbn, int newyear, string newgenre, bool newisAvailable);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    int getPublicationYear() const;
    string getGenre() const;
    bool getAvailabilityStatus() const;

    void setTitle(string newtitle);
    void setAuthor(string newauthor);
    void setISBN(string newisbn);
    void setPublicationYear(int newyear);
    void setGenre(string newgenre);
    void setAvailabilityStatus(bool newisAvailable);

private:
    string title;
    string author;
    string isbn;
    int publicationYear;
    string genre;
    bool isAvailable;
};

