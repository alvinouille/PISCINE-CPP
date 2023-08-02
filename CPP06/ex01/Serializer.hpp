#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct s_data
{
    int data;
    std::string name;
}               Data;

class Serializer
{
    public:
        Serializer();
        Serializer(Serializer const&copy);
        Serializer &operator=(Serializer const &rhs);
        ~Serializer();

        uintptr_t serialize(Data *ptr);
        Data *deserialize(uintptr_t raw);
};

#endif