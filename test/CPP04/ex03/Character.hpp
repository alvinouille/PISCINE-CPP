#include <string>
#include <iostream>

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        int _index;
    public:
        Character();
        Character(std::string const name);
        Character(Character const &copy);
        Character &operator=(Character const &rhs);
        ~Character();

        std::string const & getName() const override;
        void equip(AMateria* m) override;
        void unequip(int idx) override;
        void use(int idx, ICharacter& target) override;
}