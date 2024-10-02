#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << i->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << meta->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
// std::cout << "---------------------------------------" << std::endl;
// Dog dog;
// Animal* animal = &dog;
// Dog* dogAgain = static_cast<Dog*>(animal);
// animal->makeSound();
// dogAgain->makeSound();
// std::cout << animal->getType() << " " << std::endl;
// std::cout << dogAgain->getType() << " " << std::endl;
// dog.onlyDogCanDo();
// // animal->onlyDogCanDo();
// dogAgain->onlyDogCanDo();
// std::cout << "---------------------------------------" << std::endl;
delete j;
delete i;
delete meta;
const WrongAnimal* wAnimal = new WrongAnimal();
const WrongAnimal* wCat = new WrongCat();
std::cout << wCat->getType() << " " << std::endl;
std::cout << wAnimal->getType() << " " << std::endl;
wCat->makeSound();
wAnimal->makeSound();
delete wAnimal;
delete wCat;
return 0;
}