#include <string>
#include <iostream>


int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string &stringREF = str;
    std::string *stringPTR = &str;

    std::cout << "  ------ [variable addresses] --------\n";
    std::cout << "str : " << &str << std::endl;
    std::cout << "strREF : " << &stringREF << std::endl;
    std::cout << "strPTR : " << stringPTR << std::endl;

    std::cout << "  ------ [variable Values ] --------\n";
    std::cout << "str : " << str << std::endl;
    std::cout << "strREF : " << stringREF << std::endl;
    std::cout << "strPTR : " << *stringPTR << std::endl;
    return 0;
}