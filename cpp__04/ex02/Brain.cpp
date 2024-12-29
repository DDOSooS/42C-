#include "./Brain.hpp"

Brain::Brain()
{
    std::cout << "\033[32m[Constructor]:\033[0m Brain Object is being Created \n";
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";
}

Brain::Brain(std::string (&ideas)[100]):_ideas(ideas)
{
    std::cout << "\033[32m[Constructor]:\033[0m Brain Object is being Created \n";
};

Brain::Brain(const Brain &copy)
{
    std::cout << "[Copy Constructor]: Brain Object is being Created \n";
    for (size_t i = 0; i < 100; i++)
    {
        _ideas[i] = copy.getIdea(i);
    }
}

Brain & Brain::operator=(const Brain &copy)
{
    std::cout << "[Copy Assignement Constructor]: Brain Object is being Created \n";
    if (this != &copy)
    {
        for (size_t i = 0; i < 100; i++)
        {
           _ideas[i] = copy.getIdea(i);
        }
    }
    return (*this);
}

const std::string& Brain::getIdea(unsigned int index) const
{
    static std::string empy_str;
    if (index >= 100)
        std::cout << "index is OUT OF RANGE [0 - 99]\n";
    else
        return (_ideas[index]);
    return (empy_str);
}

const std::string * Brain::getIdeas() const
{
    return (_ideas);
}

void Brain::setIdeas(std::string (&ideas)[100])
{
    for(int i; i < 100 ; i++)
        _ideas[i] = ideas[i];
}

void Brain::setIdea(std::string &idea, unsigned int index)
{
    if (index >= 100)
    {
        std::cout << "index is OUT OF RANGE [0 - 99]\n";
        return ;
    }
    _ideas[index] = idea;
}

Brain::~Brain()
{
    std::cout << "\033[31m[DeConstructor]:\033[0m Brain Object is being Destroyed \n";
}

