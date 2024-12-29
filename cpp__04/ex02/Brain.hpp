#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(std::string (&ideas)[100]);
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        ~Brain();
        /* =========>  Setters  <=========*/
        void setIdeas(std::string (&ideas)[100]);
        void setIdea(std::string &idea, unsigned int index);
        /* =========>  Getters  <=========*/
        const std::string * getIdeas() const;
        const std::string& getIdea(unsigned int index) const;

};

#endif