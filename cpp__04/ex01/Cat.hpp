#pragma once 
#ifndef CAT_HPP
#define CAT_HPP
#include "./Brain.hpp"

#include "./Animal.hpp"
class Cat : public Animal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat & operator=(const Cat &copy);
        Brain *getBrain()const;
        void setBrain(Brain *brain);
        virtual ~Cat();
        void makeSound() const;
};

#endif