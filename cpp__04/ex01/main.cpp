#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongCat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // const WrongAnimal* k = new WrongCat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();
    // k->makeSound();

    Animal *animal[4] ={new Dog(), new Cat(), new Dog(), new Cat()};

    for (size_t i = 0; i < 4; i++)
    {
        animal[i]->makeSound();
    }
    for (size_t i = 0; i < 4; i++)
    {
        delete animal[i];
    }
    

    // delete meta;
    // delete j;
    // delete i;
    // delete k;
    return (0);
}


