#ifndef BRAIN_H
# define BRAIN_H

#include "iostream"
#include "string"

class Brain
{
    protected:
        std::string _ideas[100];
    public:
        Brain();
        Brain(Brain const &copy);
        ~Brain();
        Brain &operator=(Brain const &rhs);
        bool setIdea(std::string const idea, int i);
        std::string getIdea(int i)const;
};

#endif