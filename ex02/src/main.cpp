/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:54:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 11:51:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* meta[6];

		for (int i = 0; i < 6; i++)
		{
			if (i % 2 == 0)
				meta[i] = new Dog();
			else
				meta[i] = new Cat();
		}

		for (int i = 0; i < 6; i++)
			delete meta[i];
	}
	std::cout << std::endl;
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		const Dog dog2;
		const Cat cat2;

		std::cout << *dog << std::endl;
		std::cout << *cat << std::endl;
		std::cout << dog2 << std::endl;
		std::cout << cat2;

		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		Cat cat;
		Cat cat2;

		cat2.getBrain()->setIdea(0, "PK");
		cat = cat2;
		cat2.getBrain()->setIdea(0, "Idea0");

		std::cout << cat << std::endl;
		std::cout << cat2 << std::endl;

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
		cat.getBrain()->setIdea(0, "Idea0");

		std::cout << cat << std::endl;
		std::cout << cat2 << std::endl;

		std::cout << "Sound: ";
		cat.makeSound();
		std::cout << "Sound: ";
		cat2.makeSound();
	}
	std::cout << std::endl;
	{
		Dog dog;

		dog.getBrain()->setIdea(0, "PK");
		dog.getBrain()->setIdea(-1, "PK");
		dog.getBrain()->setIdea(100, "PK");

		std::cout << dog.getBrain()->getIdea(0) << std::endl;
		std::cout << dog.getBrain()->getIdea(-1) << std::endl;
		std::cout << dog.getBrain()->getIdea(100) << std::endl;
	}
	std::cout << std::endl;
	{
		const Animal* dog = new Dog();
		Animal* cat = new Cat();

		*cat = *dog;

		std::cout << "Type: " << dog->getType() << std::endl;
		std::cout << "Type: " << cat->getType() << std::endl;

		std::cout << "Sound: ";
		cat->makeSound();
		std::cout << "Sound: ";
		dog->makeSound();

		delete cat;
		delete dog;
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
