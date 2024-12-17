#include "Harl.hpp"

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Try Again with : ./prog <COMPLINING_LEVEL>" << std::endl;
        return (0);
    }
    Harl harl;

    harl.complain(argv[1]);
    return (0);
}