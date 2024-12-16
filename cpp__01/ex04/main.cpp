#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int ac, char **av)
{
    if (ac != 4 || av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
    {
        cout << "try Again with this Format: <fileName> <s1> <s2>\n";
        return (1);
    }
    fstream new_file; 
    new_file.open(av[1],ios::out);  
    if(!new_file) 
    {
        cout<<"File creation failed\n";
    }
    else
    {
        cout<<"New file created\n";
        new_file<<"Learning File handling\n";
        new_file.close(); 
    }   
    return (0);
}

