#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Contact
{
    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_nickName;
        std::string m_phoneNumber;
        std::string m_darkestSecret;

    public:

        Contact();

        Contact(std::string firsName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

        bool isEmpty() const;

        void setFirstName(std::string &firstName);
        std::string getFirstName();

        void setLastName(std::string &lastName);
        std::string getLastName();

        void setPhoneNumber(std::string &tPhoneNumber);
        std::string getPhoneNumber();

        void setNickName(std::string &nickName);
        std::string getNickName();

        void setDarkestSecret(std::string &darkestSecret);
        std::string getDarkestSecret();

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
std::string formatedPrinter(const std::string& value);
std::string intToString(int value);

#endif