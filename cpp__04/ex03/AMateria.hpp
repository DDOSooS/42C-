#ifndef AMETRIA_HPP
#define AMETRIA_HPP

#include <string>
#include <iostream>

class AMateria
{
    protected:
        std::string _type;
        // [...]
    public:
        AMateria(std::string const & type);
        ~AMateria();
        // [...]
        std::string const & getType() const; 
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
}
#endif