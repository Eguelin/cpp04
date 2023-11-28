/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:54:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:23:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "Type: " << j->getType() << std::endl;
		std::cout << "Type: " << i->getType() << std::endl;
		std::cout << "Type: " << meta->getType() << std::endl;

		std::cout << "Sound: ";
		i->makeSound();
		std::cout << "Sound: ";
		j->makeSound();
		std::cout << "Sound: ";
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << "Type: " << i->getType() << std::endl;
		std::cout << "Type: " << meta->getType() << std::endl;

		std::cout << "Sound: ";
		i->makeSound();
		std::cout << "Sound: ";
		meta->makeSound();

		delete meta;
		delete i;
	}
	return (0);
}
