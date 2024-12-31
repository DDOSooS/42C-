#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#include "./Contact.hpp"

class PhoneBook
{
    private :
        Contact m_contacts[8];

    public:
        void addConctact(Contact &contacts);

        Contact getContact(int index);

        void showContacts(Contact* contacts);
  
        Contact*    getContacts();
};

void displayContact(Contact contact);
std::string formatedPrinter(const std::string& value);
std::string intToString(int value);
void saveNewContact(PhoneBook &phone);
void searchForContact(PhoneBook &phoneBook);
bool isPrintable(std::string &field);
#endif