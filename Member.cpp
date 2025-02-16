#include "Member.h"
using namespace std;

Member::Member() : name(""), memberId(0), contact("") {}

Member::Member(string newname, int newmemberId, string newcontact)
    : name(newname), memberId(newmemberId), contact(newcontact) {}

string Member::getName() const { 
    return name; 
}
int Member::getMemberId() const { 
    return memberId; 
}
string Member::getContact() const { 
    return contact; 
}

void Member::setName(string newname) {
    name = newname; 
}
void Member::setMemberId(int newmemberId) { 
    memberId = newmemberId; 
}
void Member::setContact(string newcontact) { 
    contact = newcontact; 
}