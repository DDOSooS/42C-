#include "./header.hpp"

#include <iostream>
#include <string>

bool isInteger(const string& str)
{
    if (str.empty())
        return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
    { 
        i++;
    }

    for (; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

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
    std::cout << "||firstName |  lastName|  nickName||\n";
    std::cout << "|| ============================== ||\n";
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

int stringToInt(const std::string& str) {
    int result = 0;
    bool negative = false;
    size_t i = 0;

    // Handle optional sign
    if (str[0] == '-') {
        negative = true;
        i++;
    }
    else if (str[0] == '+') {
        i++;
    }

    // Convert string to integer
    for (; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') {
            // Invalid character
            throw std::invalid_argument("Invalid number format");
        }
        result = result * 10 + (str[i] - '0');
    }

    return negative ? -result : result;
}

void searchForContact(PhoneBook &phoneBook)
{
    int index;
    string indexPrompt;

    cout << "=====> Start Searching For Contact <=====\n";
    phoneBook.showContacts(phoneBook.getContacts());
    cout << "try to Enter the index of the Contact that You are Searching For\n";
    getline(cin, indexPrompt);
    if (! isInteger(indexPrompt))
    {
        cout << "TRY NEXT TIME WITH A VALID NUMBER : EX: 1 2 3 5 \n";
        return ;
    }
    index = stringToInt(indexPrompt);
    if (index < 0 || index > 7 || phoneBook.getContacts()[index].isEmpty() )
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
            else if (!command.compare("SEARCH"))
            {
                cout << "Search for a Contact \n";
                searchForContact(phoneBook);
            }
            else
                cout << " !!!  try with a valid command : ADD | SEARCH | EXIT !!! \n";
        }
    }
    return 0;
}