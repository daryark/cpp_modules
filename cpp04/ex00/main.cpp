#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const Dog dog;
std::cout << dog.getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
dog.makeSound();
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
return 0;
}