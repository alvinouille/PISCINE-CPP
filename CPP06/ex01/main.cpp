#include "Serializer.hpp"

int main()
{
    Serializer ser;
    Data *src = new Data;
    Data *dest;

    src->name = "Yo";
    src->data = 2;
    dest = ser.deserialize(ser.serialize(src));
    std::cout << "src->name = " << src->name << ", src->data = " << src->data << std::endl;
    std::cout << "dest->name = " << dest->name << ", dest->data = " << dest->data << std::endl;
    std::cout << "Adresse src : " << src << std::endl;
    std::cout << "Adresse dest : " << dest << std::endl;
}