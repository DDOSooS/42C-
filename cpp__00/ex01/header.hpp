#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>

using namespace std;

std::string formatedPrinter(const std::string& value);
std::string intToString(int value) {
    std::string result;
    bool isNegative = value < 0;
    
    if (value == 0) return "0";
    
    if (isNegative) value = -value;
    
    while (value > 0) {
        result = static_cast<char>('0' + (value % 10)) + result;
        value /= 10;
    }
    
    if (isNegative) result = "-" + result;
    
    return result;
}

class Contact
{
    private:
        string m_firstName;
        string m_lastName;
        string m_nickName;
        string m_phoneNumber;
        string m_darkestSecret;
    public:

        Contact()
        {
            this->m_firstName = "";
            this->m_lastName = "";
            this->m_nickName = "";
            this->m_phoneNumber = "";
            this->m_darkestSecret = "";
        };

    Contact(string firsName, string lastName, string nickName, string phoneNumber, string darkestSecret)
    {
        this->m_firstName = firsName;
        this->m_lastName = lastName;
        this->m_nickName = nickName;
        this->m_phoneNumber = phoneNumber;
        this->m_darkestSecret = darkestSecret;
    };

    public:

        bool isEmpty() const {
            return (m_firstName.empty());
        }

        void setFirstName(string &firstName)
        {
            this->m_firstName = firstName;
        };

        string getFirstName()
        {
            return m_firstName;
        };

        void setLastName(string &lastName)
        {
            this->m_lastName = lastName;
        }

        string getLastName()
        {
            return m_lastName;
        }

        void setPhoneNumber(string &tPhoneNumber)
        {
            this->m_phoneNumber = tPhoneNumber;
        }

        string getPhoneNumber()
        {
            return m_phoneNumber;
        }

        void setNickName(string &nickName)
        {
            this->m_nickName = nickName;
        }

        string getNickName()
        {
            return m_nickName;
        }

        void setDarkestSecret(string &darkestSecret)
        {
            this->m_darkestSecret = darkestSecret;
        }

        string getDarkestSecret()
        {
            return m_darkestSecret;
        }

    ~Contact(){};
};

class PhoneBook
{
    public:
        Contact m_contacts[8];

    
    // PhoneBook (Contact &contacts)
    // {
    //     this->m_contacts = contacts;
    // };

    public :
        void addConctact(Contact &contacts)
        {
            int i;

            i = -1;
            while (++i < 8)
            {
                if (m_contacts[i].isEmpty())
                {
                    m_contacts[i] = contacts;
                    cout << " Contact is being added Succesfully :)\n";
                    return;
                }
            }
            m_contacts[7] = contacts;
            cout << " Contact is being added Succesfully :)\n";
            return ;
        };

        Contact searchForContact(int index)
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

        void showContacts(Contact* contacts)
        {
            std::cout << "||     index| firstName|  lastName|  nickName||\n";
            std::cout << "|| ========================================= ||\n";
            for (int i = 0; i < 8; ++i) {
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

  

        public :
            Contact *getContacts()
            {
                return m_contacts;
            }

            
};


void displayContact(Contact contact);


#endif