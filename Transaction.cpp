#include "Transaction.h"

Transaction::Transaction() : bookISBN(""), memberId(0), issueDate(""), returnDate("") {}

Transaction::Transaction(string bookISBN, int memberId, string issueDate, string returnDate)
    : bookISBN(bookISBN), memberId(memberId), issueDate(issueDate), returnDate(returnDate) {}


string Transaction::getBookISBN() const { 
    return bookISBN; 
}
int Transaction::getMemberId() const { 
    return memberId; 
}
string Transaction::getIssueDate() const { 
    return issueDate; 
}
string Transaction::getReturnDate() const {
    return returnDate;
}

void Transaction::setBookISBN(string newbookISBN) { 
    bookISBN = newbookISBN; 
}
void Transaction::setMemberId(int newmemberId) { 
    memberId = newmemberId; 
}
void Transaction::setIssueDate(string newissueDate) { 
    issueDate = newissueDate; 
}
void Transaction::setReturnDate(const string& newreturnDate) {
    returnDate = newreturnDate;
}

