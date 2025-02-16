#include "LibraryFunctions.h"
#include "Transaction.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string> //header files and standard library
using namespace std; //standardize everything
//first function
void LibraryFunctions::addBook(vector<Book>& books) { //takes reference to the vector books
    string title, author, isbn, genre;
    int year;
    bool isAvailable = true; //alr initialzed for true status
    cout << "Plz, enter the book's title: ";
    cin >> ws;
    getline(cin, title);  // Use getline for multi worded strings
    cout << "Now, enter the author: ";
    getline(cin, author);
    cout << "Nice choice " << title << " by " << author << " ,thats a good read!" << endl;
    // Add error handling for ISBN
    bool validISBN = false;
    while (!validISBN) {
        cout << "Enter ISBN (10-13 digits): "; 
        getline(cin, isbn);

        if (isbn.length() >= 10 && isbn.length() <= 13) {
            validISBN = true;
        }
        else {
            cout << "invalid ISBN, plz enter an ISBN that is 10 to 13 digits long." << endl;
        }
    }
    // Error handling for the publication year
    bool validYear = false;
    while (!validYear) {
        cout << "Enter the publication year: ";
        cin >> year;

        if (year >= 1 && year <= 2025) {
            validYear = true;
        }
        else {
            cout << "invalid year, plz enter a year before 2025." << endl;
        }
    }
    //
    const string genres[] = { "Fiction", "Non-Fiction", "Mystery", "Sci-Fi", "Fantasy", "Biography", "History", "Children","Bible"};//predefined array list for genre 
    bool validGenre = false;

    cout << "Available genres: " << endl;
    for (const auto& g : genres) {
        cout << "- " << g << endl;//spaces out the options
    }

    while (!validGenre) {
        cout << "Now enter the genre: ";
        cin >> ws;
        getline(cin, genre);

        // checks the genre is in the list of available genres
        for (const auto& g : genres) {
            if (genre == g) {
                validGenre = true;
                break;
            }
        }
        if (!validGenre) {
            cout << "invalid genre, plz choose from the available genres." << endl;
        }
    }


    books.emplace_back(title, author, isbn, year, genre, isAvailable);
    cout << "Thanks, " << title << " was added successfully." << endl;
}
//------------------------------------------------------------------------
void LibraryFunctions::addMember(vector<Member>& members) { //another LF function but with refrence to member object
    string name, contact;
    int memberId;
    bool validContact = false;

    cout << "Enter the member's name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Welcome " << name << "!" << endl;

    do {
        cout << "Choose member ID (001-999): ";
        cin >> memberId;
        if (memberId < 1 || memberId > 999) {
            cout << "invalid member ID, plz try again with a three digit number 1-999." << endl;
        }
    } while (memberId < 1 || memberId > 999);

    cin.ignore(); //ignores unnecessary/buffer

    while (!validContact) {
        cout << "Enter contact (must contain @gmail.com): ";
        getline(cin, contact);

        if (contact.find("@gmail.com") != string::npos) {
            validContact = true;
        }
        else {
            cout << "Invalid contact. Please provide a contact containing @gmail.com." << endl;
        }
    }

    members.emplace_back(name, memberId, contact);
    cout << "You're successfully added." << endl;
}
//-----------------------------------------------------------------
string addOneMonth(const string& date) {
    // Split the date string into day, month, and year
    int day, month, year;
    char dash; // To consume the dash characters
    stringstream ss(date);
    ss >> month >> dash >> day >> dash >> year;

    // Increment the month
    month += 1; 

    // Handle the overflow for the month
    if (month > 12) {
        month = 1;  // Reset to January
        year += 1;  // Increment the year
    }

    // Format the new date string
    stringstream newDate;
    newDate << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day << "-" << year;
    return newDate.str();
}
//-------------------------------------------------------------------------------------------------------------------
void LibraryFunctions::issueBook(vector<Transaction>& transactions, vector<Book>& books, vector<Member>& members) {
    string isbn, issueDate;
    bool memberFound = false;
    bool bookFound = false;
    string bookTitle;
    string memberName;
    int memberId;
    cout << "Enter the book's ISBN, to be issued: ";
    getline(cin, isbn);
    cout << "Enter your member ID: ";
    cin >> memberId;
    cin.ignore();
    // Check if the member exists
    for (auto& member : members) {
        if (member.getMemberId() == memberId) {
            memberFound = true;
            memberName = member.getName();
            break;
        }
    }
    if (!memberFound) {
        cout << "Your ID not found in system." << endl;
        return;
    }
    cout << "Enter issue date (month-day-year): ";
    getline(cin, issueDate);


    // Check if the book exists and is available
    for (auto& book : books) {
        if (book.getISBN() == isbn && book.getAvailabilityStatus()) {
            transactions.emplace_back(isbn, memberId, issueDate, "");
            book.setAvailabilityStatus(false);
            bookTitle = book.getTitle();
            bookFound = true;
            break;
        }
    }

    if (bookFound) {
        cout << "Here is \"" << bookTitle << "\", enjoy your book! plz return it by " << addOneMonth(issueDate) << endl;
    }
    else {
        cout << memberName << ", this book is not available or the ISBN is incorrect." << endl;
    }
}
//implementation of LibraryFunctions::returnBook-------------------------------------------------------------------------
void LibraryFunctions::returnBook(vector<Transaction>& transactions, vector<Book>& books) {
    string isbn, returnDate, bookTitle;
    bool transactionFound = false;

    cout << "Enter the book's ISBN to return: ";
    getline(cin, isbn);
    cout << "Enter return date (day-month-year): ";
    getline(cin, returnDate);

    // finds the transaction
    for (auto& transaction : transactions) {
        if (transaction.getBookISBN() == isbn && transaction.getReturnDate().empty()) {
            transaction.setReturnDate(returnDate);  // Set the return date-> 
            transactionFound = true;

            // find/update its availability status
            for (auto& book : books) {
                if (book.getISBN() == isbn) {
                    book.setAvailabilityStatus(true);
                    bookTitle = book.getTitle();
                    cout << bookTitle << " returned successfully." << endl;
                    return;
                }
            }
        }
    }
    if (!transactionFound) {
        cout << "Return failed. Please check the ISBN and try again." << endl;
    }
}
