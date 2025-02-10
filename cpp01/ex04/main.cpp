#include <iostream>
#include <string>
#include <fstream>


int ft_strlen(char *str)
{
    int     i;

    i = -1;
    while (str[++i]);
    return (i);    
}

void replaceStr(char **av)
{
    std::ifstream inFile(av[1]);
    size_t pos;
    size_t start;

    if (!inFile.is_open())
    {
        std::cout << "Could not Open " << av[1] << std::endl;
        return ;
    }
    std::ofstream outFile((av[1] + std::string(".replace")).c_str());
    std::string line;
    int s1_len = ft_strlen(av[2]);
    while (std::getline(inFile, line))
    {
        start = 0;
        pos = line.find(av[2], start);
        if ( pos != std::string::npos)
        {
            while (pos != std::string::npos)
            {
                outFile << line.substr(start, pos - start);
                outFile << av[3];
                start = pos + s1_len;
                pos = line.find(av[2], start);
            }
            if (start < line.size())
                outFile << line.substr(start, line.size() - start);
        }
        else
            outFile << line;
        outFile << "\n";
    }
    inFile.close();
    outFile.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "try Again with this Format: ./exec file s1 s2\n";
        return 1;
    }
    replaceStr(av);
    return 0;
}

