// HMProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include "LibraryFunctions.h"

using namespace std;


int main() {
    vector<Book> books;
    vector<Member> members;
    vector<Transaction> transactions;
     
    LibraryFunctions libraryFunctions;

    int choice;
    do {
        cout << endl;
        cout << "Welcome, to Temesgen's Library Management System" << endl;
        cout << "1. for Add Book" << endl;
        cout << "2. for Add Member" << endl;
        cout << "3. for Check Out Book" << endl;
        cout << "4. for Return Book" << endl;
        cout << "5. for Done and Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "-----------------------------------------------" << endl;

        switch (choice) {
        case 1:
            libraryFunctions.addBook(books);
            break;
        case 2:
            libraryFunctions.addMember(members);
            break;
        case 3:
            libraryFunctions.issueBook(transactions, books, members);
            break;
        case 4:
            libraryFunctions.returnBook(transactions, books);
            break;
        case 5:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "Not an option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
