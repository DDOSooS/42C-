#include <iostream>
#include <fstream>
#include <string>

int ft_strlen(const char *str)
{
    int counter;

    counter = -1;
    while (str[++counter]);
    return (counter);
}

bool isFileEmpty(std::fstream &file)
{
    return file.peek() == std::fstream::traits_type::eof();
}

void replaceOccurrence(char *fileName, std::string *lines, const char *s1, const char *s2, int fileCount)
{
    std::ofstream file(fileName, std::ios::out);

    if (!file.is_open())
    {
        std::cout << "Couldn't open the file\n";
        return;
    }
    for(int i = 0; i < fileCount; i++)
    {   
        std::string currentLine = lines[i];
        size_t oldIndex = 0;
        size_t res = currentLine.find(s1);
        while (res != std::string::npos)
        {
            file << currentLine.substr(oldIndex, res - oldIndex);
            file << s2;
            oldIndex = res + ft_strlen(s1);
            res = currentLine.find(s1, oldIndex);
        }
        if (oldIndex < currentLine.size())
            file << currentLine.substr(oldIndex);
        file << std::endl;
    }
    file.close();
}

void getLines(const char *fileName, std::string *lines)
{
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string line;
        int i = 0;
        while (std::getline(file, line))
        {
            lines[i++] = line;
        }
        file.close();
    }
    else
        std::cerr << "Error opening file: " << fileName << "\n";
}

int countLines(const char *fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << fileName << "\n";
        return 0;
    }
    int counter = 0;
    std::string line;
    while (std::getline(file, line))
        counter++;
    file.close();
    return counter;
}

int checkFile(const char *fileName)
{
    std::fstream new_file(fileName, std::ios::in);
    if (!new_file)
    {
        std::cerr << "File creation failed\n";
        return 0;
    }
    if (isFileEmpty(new_file))
    {
        std::cout << "File is empty\n";
        new_file.close();
        return 0;
    }
    new_file.close();
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cout << "Try again with this format: <program> <fileName> <S1> <S2>\n";
        return 1;
    }
    const char *fileName = argv[1];
    if (! checkFile(fileName))
        return (0);
    int lineCount = countLines(fileName);
    std::string *lines = new std::string[lineCount];
    getLines(fileName, lines);
    replaceOccurrence(argv[1],lines, argv[2], argv[3], lineCount);
    delete[] lines;
    return 0;
}
