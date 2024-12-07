#include "./header.hpp"


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

    fName = getFiledValue("First Name");
    lName = getFiledValue("Last Name");
    nName = getFiledValue("Nick Name");
    pNumber = getFiledValue("Phone Number");
    dSecret = getFiledValue("darkestSecret");
    newContact = Contact(fName, lName, nName, pNumber, dSecret);
    phone.addConctact(newContact);
    // phone.showContacts(phone.getContacts());
    cout << "===== Contact has being succesfully Saved =====\n";
}

void searchForContact(PhoneBook &phoneBook)
{

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
                searchForContact(phoneBook);
        }
    }
    return 0;
}