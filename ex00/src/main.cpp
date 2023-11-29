/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:54:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 17:58:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		Animal* meta = new Animal();
		Animal* dog = new Dog();
		Animal* cat = new Cat();
		Animal meta2;
		Dog dog2;
		Cat cat2;

		std::cout << *meta;
		std::cout << *dog;
		std::cout << *cat;
		std::cout << meta2;
		std::cout << dog2;
		std::cout << cat2;

		delete meta;
		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		Dog dog;
		Dog dog2;

		dog2 = dog;

		std::cout << "Type: " << dog.getType() << std::endl;
		std::cout << "Type: " << dog2.getType() << std::endl;

		std::cout << "Sound: ";
		dog2.makeSound();
		std::cout << "Sound: ";
		dog.makeSound();
	}
	std::cout << std::endl;
	{
		Cat cat;
		Cat cat2(cat);

		std::cout << "Type: " << cat.getType() << std::endl;
		std::cout << "Type: " << cat2.getType() << std::endl;

		std::cout << "Sound: ";
		cat.makeSound();
		std::cout << "Sound: ";
		cat2.makeSound();
	}
	std::cout << std::endl;
	{
		Animal* meta = new Animal();
		Animal* dog = new Dog();
		Animal* cat = new Cat();

		*cat = *dog;

		std::cout << "Type: " << meta->getType() << std::endl;
		std::cout << "Type: " << dog->getType() << std::endl;
		std::cout << "Type: " << cat->getType() << std::endl;

		std::cout << "Sound: ";
		cat->makeSound();
		std::cout << "Sound: ";
		dog->makeSound();
		std::cout << "Sound: ";
		meta->makeSound();

		delete meta;
		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		Animal* dog = new Dog();
		Animal	meta;

		*dog = meta;

		std::cout << "Type: " << meta.getType() << std::endl;
		std::cout << "Type: " << dog->getType() << std::endl;

		std::cout << "Sound: ";
		dog->makeSound();
		std::cout << "Sound: ";
		meta.makeSound();

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
