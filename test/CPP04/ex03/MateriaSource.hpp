#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_repertory[4];

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &copy);
        MateriaSource &operator=(MateriaSource const &rhs);
        ~MateriaSource();

        void learnMateria(AMateria *mat);
        AMateria* createMateria(std::string const &type);
};

#endif