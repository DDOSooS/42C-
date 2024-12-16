#include "./Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_depsit):_amount(initial_depsit)
{
    this->_accountIndex = Account::_nbAccounts;
    this->_nbWithdrawals = 0;
    this->_nbDeposits = 0;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_depsit;

    _displayTimestamp();
        std::cout    << " index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "created\n";
}

Account::~Account()
{
    _displayTimestamp();
        std::cout    << " index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "closed\n";
}

int	Account::getNbAccounts()
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (Account::_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit )
{
    int old_amount;

    old_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    Account::_totalAmount += deposit;
    _displayTimestamp();
    std::cout    << " index:" << this->_accountIndex << ";"
            << "p_amount:" << old_amount << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << this->_amount << ";"
            << "nb_deposits:" << this->_nbDeposits << "\n";
}

bool    Account::makeWithdrawal(int withdrawal)
{
    int old_amount;

    old_amount = this->_amount;
    if (withdrawal > this->_amount)
    {
        _displayTimestamp();
        std::cout    << " index:" << this->_accountIndex << ";"
                << "p_amount:" << this->_amount << ";"
                << "withdrawal:refused" << "\n";
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    Account::_totalAmount -=  withdrawal;
    _displayTimestamp();
    std::cout    << " index:" << this->_accountIndex << ";"
            << "p_amount:" << old_amount << ";"
            << "withdrawal:" << withdrawal << ";"
            << "amount:" << this->_amount << ";"
            << "nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void    Account::_displayTimestamp()
{
    time_t currentTime = time(NULL);
    tm* localTime = localtime(&currentTime);
    std::cout    << "[" << 1900 + localTime->tm_year << localTime->tm_mon << localTime->tm_mday
            << "-" << localTime->tm_hour << localTime->tm_min << localTime->tm_sec
            << "]";
}

void    Account::displayAccountsInfos() 
{
    Account::_displayTimestamp();
    std::cout    << " accounts:" << Account::_nbAccounts << ";"
            << "total:" << Account::_totalAmount << ";"
            << "deposits:" << Account::_totalNbDeposits << ";"
            << "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout    << " index:" << this->_accountIndex << ";"
            << "amount:" << this->_amount << ";"
            << "deposits:" << this->_nbDeposits << ";"
            << "withdrawals:" << this->_nbWithdrawals << "\n";
}

