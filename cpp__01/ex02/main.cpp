#include <iostream>
using namespace std;

int main()
{
    string str = "HI THIS IS BRAIN";
    string *stringPTR = &str;
    string &stringREF = str;

    cout    << "===> address memory of [str : " << &str << "]  [stringPTR: " <<  stringPTR 
            << "]  [StringREF :" << &stringREF << "]" << endl << endl;
    cout    << "===> Value of [str : " << str << "]  [stringPTR: " <<  *stringPTR 
        << "] [StringREF :" << stringREF << "]"<< endl;
    
    return (0);
}