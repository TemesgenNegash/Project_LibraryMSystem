#pragma once
#include <string>
using namespace std;
class Transaction
{
public:
    Transaction();
    Transaction(string bookISBN, int memberId, string issueDate, string returnDate);

    string getBookISBN() const;
    int getMemberId() const;
    string getIssueDate() const;
    string getReturnDate() const;  // Add this line

    void setBookISBN(string newbookISBN);
    void setMemberId(int newmemberId);
    void setIssueDate(string newissueDate);
    void setReturnDate(const string& newreturnDate);  // Add this line

private:
    string bookISBN;
    int memberId;
    string issueDate;
    string returnDate;
};

