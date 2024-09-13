#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    //*AAnimal is now abstract class, so the error will happen
    //*if we will try to create an instance of the class itself
    // AAnimal animal;
    //*
  AAnimal* animals[4];

   for (size_t i = 0; i < 4; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << "-------------------------\n";
        
   }
   for (size_t i = 0; i < 4; i++) {
       delete animals[i];
   }
    std::cout << "-----------------------------\n";
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    delete j;//should not create a leak
    delete i;
    // std::cout << "------------DOG-----------------\n";
    // Dog dog;
    // dog.makeSound();
    // Dog otherDog;

    // dog = otherDog;
    // std::cout << "-----------------------------\n";
    // dog.getIdeaByIdx(11);
    // dog.setIdeaByIdx("my very good idea", 11);
    // dog.getIdeaByIdx(11);
    // std::cout << "-----------------------------\n";
    // std::cout << "------------CAT-----------------\n";
    // Cat cat;
    // cat.makeSound();
    // Cat otherCat;

    // cat = otherCat;
    // std::cout << "-----------------------------\n";
    // cat.getIdeaByIdx(22);
    // cat.setIdeaByIdx("cats are the best", 22);
    // cat.getIdeaByIdx(22);
    // std::cout << "-----------------------------\n";
return 0;
}