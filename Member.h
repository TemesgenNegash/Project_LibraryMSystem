#pragma once
#include <string>
using namespace std;

class Member {
public:
    Member();
    Member(string newname, int nwmemberId, string newcontact);

    string getName() const;
    int getMemberId() const;
    string getContact() const;

    void setName(string newname);
    void setMemberId(int newmemberId);
    void setContact(string newcontact);

private:
    string name;
    int memberId;
    string contact;
};

