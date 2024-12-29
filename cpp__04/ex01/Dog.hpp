#pragma once 
#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog & operator=(const Dog &copy);
        Brain *getBrain()const;
        void setBrain(Brain *brain);
        virtual ~Dog();
        void makeSound() const;

};

#endif