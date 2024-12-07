#include "./header.hpp"

#include <iostream>
#include <string>

std::string formatedPrinter(const std::string& value)
{
    int size = value.length();
    std::string result;

    if (size >= 10) {
        result = value.substr(0, 9) + ".";
    } else {
        result = string(10 - size, ' ') + value;
    }
    return result;
}

void displayContact(Contact contact)
{
    std::cout << "||firstName|  lastName|  nickName||\n";
    std::cout << "|| ========================================= ||\n";
    std::cout << "||" 
        << formatedPrinter(contact.getFirstName()) << "|" 
        << formatedPrinter(contact.getLastName()) << "|" 
        << formatedPrinter(contact.getNickName()) << "||\n";
}

string getFiledValue(const char *field)
{
    string  value;
    cout << " === >   Enter Your "<<  field  <<"< ===\n";
    while(getline(cin, value))
    {
        if (!value.empty())
            break;
        cout << "this fiels mustn't be empty\n";
        cout << " === >   Enter Your "<<  field  <<"< ===\n";
    }
    return value;
}

void saveNewContact(PhoneBook &phone)
{
    string fName, lName, nName, dSecret, pNumber;
    Contact newContact;

    cout << "=====> Start saving Contact <=====\n";
    fName = getFiledValue("First Name");
    lName = getFiledValue("Last Name");
    nName = getFiledValue("Nick Name");
    pNumber = getFiledValue("Phone Number");
    dSecret = getFiledValue("darkestSecret");
    newContact = Contact(fName, lName, nName, pNumber, dSecret);
    phone.addConctact(newContact);
    cout << "===== Contact has being succesfully Saved =====\n";
}

void searchForContact(PhoneBook &phoneBook)
{
    int index;
    string indexPrompt;

    cout << "=====> Start Searching For Contact <=====\n";
    phoneBook.showContacts(phoneBook.getContacts());
    cout << "try to Enter the index of the Contact that You are Searching For\n";
    getline(cin, indexPrompt);
    index = stoi(indexPrompt);
    if (index < 0 || index > 7 || phoneBook.getContacts()[index].isEmpty())
        cout << "TRY NEXT TIME WITH A VALID INDEX \n";
    else
        displayContact(phoneBook.getContacts()[index]);
    cout << "=====> The end of  Searching For Contact <=====\n";
    return ;
}


int main()
{
    PhoneBook   phoneBook;
    string      command;
    while(1)
    {
        getline(cin, command);
        if (!command.compare("EXIT"))    
            break;
        if (! command.empty())
        {
            if (!command.compare("ADD"))
                saveNewContact(phoneBook);
            else if (!command.compare("SS"))
            {
                cout << "Search for a Contact \n";
                searchForContact(phoneBook);
            }
        }
    }
    return 0;
}