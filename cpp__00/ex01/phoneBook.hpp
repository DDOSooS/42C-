#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Contact
{
    private:
        string m_firstName;
        string m_lastName;
        string m_nickName;
        string m_phoneNumber;
        string m_darkestSecret;

    public:

        Contact();

        Contact(string firsName, string lastName, string nickName, string phoneNumber, string darkestSecret);

        bool isEmpty() const;

        void setFirstName(string &firstName);
        string getFirstName();

        void setLastName(string &lastName);
        string getLastName();

        void setPhoneNumber(string &tPhoneNumber);
        string getPhoneNumber();

        void setNickName(string &nickName);
        string getNickName();

        void setDarkestSecret(string &darkestSecret);
        string getDarkestSecret();

    ~Contact(){};
};

class PhoneBook
{
    private :
        Contact m_contacts[8];

    public:
        void addConctact(Contact &contacts);

        Contact searchForContact(int index);

        void showContacts(Contact* contacts);
  
        Contact*    getContacts();
};

void displayContact(Contact contact);
string formatedPrinter(const std::string& value);
string intToString(int value);

#endif