#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
	{
		std::cout << std::endl << "<<< TEST CREATING A MATERIA, EQUIP & USE >>>" << std::endl << std::endl;
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		tmp = src->createMateria("frites");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		delete bob;
		delete me;
	}
	
	{
		std::cout << std::endl << "<<< TEST DEEP COPY AND UNEQUIP >>>" << std::endl << std::endl;
		Character *you = new Character("you");
		AMateria *tmp1;
		tmp1 = src->createMateria("cure");
		you->equip(tmp1);
		tmp1 = src->createMateria("cure");
		you->equip(tmp1);
		Character *copy = new Character(*you); //deep copy
		// *copy = *you; //other way to do it
		std::cout << "Now 'you' has cure(0) and cure(1) and so does 'copy', for example : " << std::endl;
		you->use(0, *copy);
		you->use(1, *copy);
		copy->use(0, *you);
		copy->use(1, *you);

		AMateria *around;
		tmp1 = src->createMateria("ice");
		around = copy->returnMateria(-10);
		copy->unequip(-10);
		around = copy->returnMateria(0); //to avoid leaks
		copy->unequip(0);
		if (around)
			delete around;
		copy->equip(tmp1);
		std::cout << "Now 'you' has cure(0) and cure(1) and 'copy' has ice(0), cure(1), for example : " << std::endl;
		you->use(0, *copy);
		you->use(1, *copy);
		copy->use(0, *you);
		copy->use(1, *you);
		delete you;
		delete copy;
	}

	delete src;
    return 0;
}