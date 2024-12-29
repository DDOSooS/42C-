#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongCat.hpp"

int main()
{
    // AbstractAnimal ani= new AbstractAnimal();
    // const AbstractAnimal* j = new Dog();
    // const AbstractAnimal* i = new Cat();
    // const WrongAbstractAnimal* k = new WrongCat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();
    // k->makeSound();

    AbstractAnimal *AbstractAnimal[4] ={new Dog(), new Cat(), new Dog(), new Cat()};

    for (size_t i = 0; i < 4; i++)
    {
        AbstractAnimal[i]->makeSound();
    }
    for (size_t i = 0; i < 4; i++)
    {
        delete AbstractAnimal[i];
    }
    

    // delete meta;
    // delete j;
    // delete i;
    // delete k;
    return (0);
}


