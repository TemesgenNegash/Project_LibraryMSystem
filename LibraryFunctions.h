#pragma once
#include <vector>
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
using namespace std;
class LibraryFunctions {
public:
	void addBook(vector<Book>& books);
	void addMember(vector<Member>& members);
	void issueBook(vector<Transaction>& transactions, vector<Book>& books, vector<Member>& members);
	void returnBook(vector<Transaction>& transactions, vector<Book>& books); // Add this line
};
	//Member* findMember(vector<Member>& members, int memberId);
	//Book* findBook(vector<Book>& books, const string& isbn);
	//-------------------------------------------------------------------------------------------------------------------
	//void updateBookAvailability(std::vector<Book>& books, const std::string& isbn, bool isAvailable);
	//void removeBookFromMemberHistory(std::vector<Member>& members, int memberId, const std::string& isbn);
	//void returnBook(std::vector<Transaction>& transactions, std::vector<Book>& books, std::vector<Member>& members);
	//bool isOverdue(const string& dueDate);
    //void saveData(const vector<Book>& books, const vector<Member>& members, const vector<Transaction>& transactions);
    //void loadData(vector<Book>& books, vector<Member>& members, vector<Transaction>& transactions);


