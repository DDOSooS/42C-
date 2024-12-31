#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

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


#endif 