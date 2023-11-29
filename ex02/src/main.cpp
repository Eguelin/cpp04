/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:54:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 17:57:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		Animal* dog = new Dog();
		Animal* cat = new Cat();
		Dog dog2;
		Cat cat2;

		std::cout << *dog << std::endl;
		std::cout << *cat << std::endl;
		std::cout << dog2 << std::endl;
		std::cout << cat2;

		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		Dog dog;
		Cat cat;

		dog.getBrain()->setIdea(0, "PK");
		cat = dog;
		dog.getBrain()->setIdea(0, "Idea 0");

		std::cout << "Type: " << dog.getType() << std::endl;
		std::cout << "Type: " << cat.getType() << std::endl;

		std::cout << "Brain: " << dog.getBrain() << std::endl;
		std::cout << "Brain: " << cat.getBrain() << std::endl;

		std::cout << "Idea: " << (*dog.getBrain()).getIdea(0) << std::endl;
		std::cout << "Idea: " << (*cat.getBrain()).getIdea(0) << std::endl;

		std::cout << "Sound: ";
		cat.makeSound();
		std::cout << "Sound: ";
		dog.makeSound();
	}
	std::cout << std::endl;
	{
		Cat cat;
		Cat cat2;

		cat2.getBrain()->setIdea(0, "PK");
		cat = cat2;
		cat2.getBrain()->setIdea(0, "Idea 0");

		std::cout << "Type: " << cat.getType() << std::endl;
		std::cout << "Type: " << cat2.getType() << std::endl;

		std::cout << "Brain: " << cat.getBrain() << std::endl;
		std::cout << "Brain: " << cat2.getBrain() << std::endl;

		std::cout << "Idea: " << (*cat.getBrain()).getIdea(0) << std::endl;
		std::cout << "Idea: " << (*cat2.getBrain()).getIdea(0) << std::endl;

		std::cout << "Sound: ";
		cat.makeSound();
		std::cout << "Sound: ";
		cat2.makeSound();
	}
	std::cout << std::endl;
	{
		Cat cat;

		cat.getBrain()->setIdea(0, "PK");
		Cat cat2(cat);
		cat.getBrain()->setIdea(0, "Idea 0");

		std::cout << "Type: " << cat.getType() << std::endl;
		std::cout << "Type: " << cat2.getType() << std::endl;

		std::cout << "Brain: " << cat.getBrain() << std::endl;
		std::cout << "Brain: " << cat2.getBrain() << std::endl;

		std::cout << "Idea: " << (*cat.getBrain()).getIdea(0) << std::endl;
		std::cout << "Idea: " << (*cat2.getBrain()).getIdea(0) << std::endl;

		std::cout << "Sound: ";
		cat.makeSound();
		std::cout << "Sound: ";
		cat2.makeSound();
	}
	std::cout << std::endl;
	{
		Animal* dog = new Dog();
		Animal* cat = new Cat();

		dog->getBrain()->setIdea(0, "PK");
		*cat = *dog;
		dog->getBrain()->setIdea(0, "Idea 0");

		std::cout << "Type: " << dog->getType() << std::endl;
		std::cout << "Type: " << cat->getType() << std::endl;


		std::cout << "Brain: " << dog->getBrain() << std::endl;
		std::cout << "Brain: " << cat->getBrain() << std::endl;

		std::cout << "Idea: " << (*dog->getBrain()).getIdea(0) << std::endl;
		std::cout << "Idea: " << (*cat->getBrain()).getIdea(0) << std::endl;

		std::cout << "Sound: ";
		cat->makeSound();
		std::cout << "Sound: ";
		dog->makeSound();

		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		Animal* cat = new Cat();
		Animal* cat2 = new Cat();

		cat->getBrain()->setIdea(0, "PK");
		*cat2 = *cat;
		cat->getBrain()->setIdea(0, "Idea 0");

		std::cout << "Type: " << cat->getType() << std::endl;
		std::cout << "Type: " << cat2->getType() << std::endl;

		std::cout << "Brain: " << cat->getBrain() << std::endl;
		std::cout << "Brain: " << cat2->getBrain() << std::endl;

		std::cout << "Idea: " << (*cat->getBrain()).getIdea(0) << std::endl;
		std::cout << "Idea: " << (*cat2->getBrain()).getIdea(0) << std::endl;

		std::cout << "Sound: ";
		cat2->makeSound();
		std::cout << "Sound: ";
		cat->makeSound();

		delete cat;
		delete cat2;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* wrong_cat = new WrongCat();

		const WrongAnimal meta2(*wrong_cat);

		std::cout << "Type: " << wrong_cat->getType() << std::endl;
		std::cout << "Type: " << meta->getType() << std::endl;
		std::cout << "Type: " << meta2.getType() << std::endl;

		std::cout << "Sound: ";
		wrong_cat->makeSound();
		std::cout << "Sound: ";
		meta->makeSound();
		std::cout << "Sound: ";
		meta2.makeSound();

		delete meta;
		delete wrong_cat;
	}
	return (0);
}
