#include "./Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "try to run the program with : ./exec [MESSAGE] \n";
        return 1;
    }
    Harl h;
    h.complain(av[1]);
    return 0;
}