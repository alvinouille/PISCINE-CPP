#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include <string>
#include <iostream>

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_repertory[4];

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &copy);
        MateriaSource &operator=(MateriaSource const &rhs);
        ~MateriaSource();

        void learnMateria(AMateria *mat) override;
        AMateria* createMateria(std::string const &type) override;
};

#endif