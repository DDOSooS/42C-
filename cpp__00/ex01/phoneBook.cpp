#include "./phoneBook.hpp"

#include <iostream>
#include <string>

Contact::Contact()
{
    this->m_firstName = "";
    this->m_lastName = "";
    this->m_nickName = "";
    this->m_phoneNumber = "";
    this->m_darkestSecret = "";
};

Contact::Contact(string firsName, string lastName, string nickName, string phoneNumber, string darkestSecret)
{
    this->m_firstName = firsName;
    this->m_lastName = lastName;
    this->m_nickName = nickName;
    this->m_phoneNumber = phoneNumber;
    this->m_darkestSecret = darkestSecret;
};

bool Contact::isEmpty() const
{
    return (m_firstName.empty());
}

void Contact::setFirstName(string &firstName)
{
    this->m_firstName = firstName;
};

string Contact::getFirstName()
{
    return m_firstName;
};

Contact*    PhoneBook::getContacts()
{
    return  m_contacts;
}

void Contact::setLastName(string &lastName)
{
    this->m_lastName = lastName;
}

string Contact::getLastName()
{
    return m_lastName;
}

void Contact::setPhoneNumber(string &tPhoneNumber)
{
    this->m_phoneNumber = tPhoneNumber;
}

string Contact::getPhoneNumber()
{
    return m_phoneNumber;
}

void Contact::setNickName(string &nickName)
{
    this->m_nickName = nickName;
}

string Contact::getNickName()
{
    return m_nickName;
}

void Contact::setDarkestSecret(string &darkestSecret)
{
    this->m_darkestSecret = darkestSecret;
}

string Contact::getDarkestSecret()
{
    return m_darkestSecret;
}



string intToString(int value)
{
    string result;
    bool isNegative = value < 0;

    if (value == 0)
        return "0";
    if (isNegative)
        value = -value;
    while (value > 0)
    {
        result = (char)('0' + (value % 10)) + result;
        value /= 10;
    }
    if (isNegative)
        result = "-" + result;
    return result;
}

 void   PhoneBook::addConctact(Contact &contacts)
{
    int i;

    i = -1;
    if (!m_contacts[7].isEmpty())
    {
        while (++i < 7)
        {
            m_contacts[i] = m_contacts[i + 1];
        }
        m_contacts[7] = contacts;
        cout << " Contact is being added Succesfully :)\n";
        return ;
    }
    while (++i < 8)
    {
        if (m_contacts[i].isEmpty())
        {
            m_contacts[i] = contacts;
            cout << " Contact is being added Succesfully :)\n";
            return;
        }
    }
};


Contact PhoneBook::searchForContact(int index)
{
    int i;

    i = -1;
    while (++i < 8)
    {
        if (i == index)
            return (m_contacts[index]);
    }
    return Contact();
}

void  PhoneBook::showContacts(Contact* contacts)
{
    if (!cin)
        cin.clear();
    std::cout << "||     index| firstName|  lastName|  nickName||\n";
    std::cout << "|| ========================================= ||\n";
    for (int i = 0; i < 8; ++i)
    {
        if (!contacts[i].isEmpty()) 
        {
            std::cout << "||" 
                    << formatedPrinter(intToString(i)) <<  "|" 
                    << formatedPrinter(contacts[i].getFirstName()) << "|" 
                    << formatedPrinter(contacts[i].getLastName()) << "|" 
                    << formatedPrinter(contacts[i].getNickName()) << "||\n";
        }
    }
    std::cout << "|| ========================================= ||\n";
}

bool isInteger(const string& str)
{
    if (str.empty())
        return false;
    size_t i;
    i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
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

    if (size >= 10)
    {
        result = value.substr(0, 9) + ".";
    }
    else
    {
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
    string value;

    cout << " === >   Enter Your " << field << " < ===\n";
    while (true)
    {
        if (!getline(cin, value) || cin.fail())  
        {
            cout << "Error reading input. Exiting...\n";
            exit(1);  
        }
        if (!value.empty())
            break; 
        cout << "This field mustn't be empty\n";
        cout << " === >   Enter Your " << field << " < ===\n";
    }
    return value;
}

void saveNewContact(PhoneBook &phone)
{
    string fName, lName, nName, dSecret, pNumber;
    Contact newContact;
    
    if (cin.eof())
        return ;
    cout << "=====> Start saving Contact <=====\n";
    fName = getFiledValue("First Name");
    lName = getFiledValue("Last Name");
    nName = getFiledValue("Nick Name");
    pNumber = getFiledValue("Phone Number");
    dSecret = getFiledValue("darkestSecret");
    
    if (cin.eof())
        return;
    newContact = Contact(fName, lName, nName, pNumber, dSecret);
    phone.addConctact(newContact);
    cout << "===== Contact has being succesfully Saved =====\n";
}

int stringToInt(const string& str)
{
    int result = 0;
    bool negative = false;
    size_t i = 0;

    if (str[0] == '-')
    {
        negative = true;
        i++;
    }
    else if (str[0] == '+')
        i++;
    for (; i < str.length(); ++i)
        result = result * 10 + (str[i] - '0');
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
    if (cin.eof())
    {
        cout << "\nEOF detected. Exiting...\n";
        exit(EXIT_FAILURE);
    }
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
    
    while(1 && !cin.eof())
    {   
        cout << "Enter a command : (ADD | SEARCH | EXIT)\n"; 
        if (!getline(cin, command))
        {
            if (cin.eof())
            {
                cout << "\nEOF detected. Exiting...\n";
                break;
            }
        }
        if (!command.empty() && (!command.compare("EXIT")))    
            break;
        if (!command.empty() && (!command.empty()))
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