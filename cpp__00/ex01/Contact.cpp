#include "./Contact.hpp"

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

/*==============> setter & Getters <=============*/

void Contact::setFirstName(std::string &firstName)
{
    this->m_firstName = firstName;
};

std::string Contact::getFirstName()
{
    return m_firstName;
};


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

/* ================================================= */