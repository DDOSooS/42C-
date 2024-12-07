#include <iostream>
#include <cctype>


int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; ++i)
        {
            for (int j = 0; av[i][j] != '\0'; ++j)
            {
                std::cout << (char)(toupper(av[i][j]));
            }
        }
        std::cout << "\n";
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    return 0;
}
