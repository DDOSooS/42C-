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

Contact::Contact(std::string firsName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
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

void Contact::setFirstName(std::string &firstName)
{
    this->m_firstName = firstName;
};

std::string Contact::getFirstName()
{
    return m_firstName;
};

Contact*    PhoneBook::getContacts()
{
    return  m_contacts;
}

void Contact::setLastName(std::string &lastName)
{
    this->m_lastName = lastName;
}

std::string Contact::getLastName()
{
    return m_lastName;
}

void Contact::setPhoneNumber(std::string &tPhoneNumber)
{
    this->m_phoneNumber = tPhoneNumber;
}

std::string Contact::getPhoneNumber()
{
    return m_phoneNumber;
}

void Contact::setNickName(std::string &nickName)
{
    this->m_nickName = nickName;
}

std::string Contact::getNickName()
{
    return m_nickName;
}

void Contact::setDarkestSecret(std::string &darkestSecret)
{
    this->m_darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret()
{
    return m_darkestSecret;
}

std::string intToString(int value)
{
    std::string result;
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
        std::cout << " Contact is being added Succesfully :)\n";
        return ;
    }
    while (++i < 8)
    {
        if (m_contacts[i].isEmpty())
        {
            m_contacts[i] = contacts;
            std::cout << " Contact is being added Succesfully :)\n";
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
    if (!std::cin)
        std::cin.clear();
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

bool isInteger(const std::string& str)
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
        result = std::string(10 - size, ' ') + value;
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

std::string getFiledValue(const char *field)
{
    std::string value;

    std::cout << " === >   Enter Your " << field << " < ===\n";
    while (true)
    {
        if (!getline(std::cin, value) || std::cin.fail())  
        {
            std::cout << "Error reading input. Exiting...\n";
            exit(1);  
        }
        if (!value.empty())
            break; 
        std::cout << "This field mustn't be empty\n";
        std::cout << " === >   Enter Your " << field << " < ===\n";
    }
    return value;
}

void saveNewContact(PhoneBook &phone)
{
    std::string fName, lName, nName, dSecret, pNumber;
    Contact newContact;
    
    if (std::cin.eof())
        return ;
    std::cout << "=====> Start saving Contact <=====\n";
    fName = getFiledValue("First Name");
    lName = getFiledValue("Last Name");
    nName = getFiledValue("Nick Name");
    pNumber = getFiledValue("Phone Number");
    dSecret = getFiledValue("darkestSecret");
    if (std::cin.eof())
        return;
    newContact = Contact(fName, lName, nName, pNumber, dSecret);
    phone.addConctact(newContact);
    std::cout << "===== Contact has being succesfully Saved =====\n";
}

int stringToInt(const std::string& str)
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
    std::string indexPrompt;

    std::cout << "=====> Start Searching For Contact <=====\n";
    phoneBook.showContacts(phoneBook.getContacts());
    std::cout << "try to Enter the index of the Contact that You are Searching For\n";
    getline(std::cin, indexPrompt);
    if (std::cin.eof())
    {
        std::cout << "\nEOF detected. Exiting...\n";
        exit(EXIT_FAILURE);
    }
    if (! isInteger(indexPrompt))
    {
        std::cout << "TRY NEXT TIME WITH A VALID NUMBER : EX: 1 2 3 5 \n";
        return ;
    }
    index = stringToInt(indexPrompt);
    if (index < 0 || index > 7 || phoneBook.getContacts()[index].isEmpty() )
        std::cout << "TRY NEXT TIME WITH A VALID INDEX \n";
    else
        displayContact(phoneBook.getContacts()[index]);
    std::cout << "=====> The end of  Searching For Contact <=====\n";
    return ;
}

int main()
{
    PhoneBook   phoneBook;
    std::string      command;
    
    while(1 && !std::cin.eof())
    {   
        std::cout << "Enter a command : (ADD | SEARCH | EXIT)\n"; 
        if (!getline(std::cin, command))
        {
            if (std::cin.eof())
            {
                std::cout << "\nEOF detected. Exiting...\n";
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
                std::cout << "Search for a Contact \n";
                searchForContact(phoneBook);
            }
            else
                std::cout << " !!!  try with a valid command : ADD | SEARCH | EXIT !!! \n";
        }
    }
    return 0;
}