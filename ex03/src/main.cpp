/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:32:47 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 14:05:00 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Floor	gFloor;

int main( void )
{
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");
	AMateria	*tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	src->learnMateria(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}

// int main( void )
// {
// 	ICharacter	*bob = new Character("bob");
// 	ICharacter	*bob2 = new Character("bob2");
// 	AMateria	*ice = new Ice();
// 	AMateria	*ice2 = ice->clone();
// 	AMateria	*ice3 = ice->clone();
// 	AMateria	*cure = new Cure();
// 	AMateria	*cure2 = cure->clone();

// 	std::cout << std::endl;
// 	std::cout << "ice: " << ice << std::endl;
// 	std::cout << *ice;
// 	std::cout << "ice2: " << ice2 << std::endl;
// 	std::cout << *ice2;

// 	*cure = *ice;

// 	std::cout << "cure: " << cure << std::endl;
// 	std::cout << *cure;
// 	std::cout << "cure2: " << cure2 << std::endl;
// 	std::cout << *cure2;
// 	std::cout << "ice3: " << ice3 << std::endl;
// 	std::cout << *ice3;
// 	std::cout << std::endl;

// 	bob->equip(ice);
// 	bob->equip(ice2);
// 	bob->equip(ice3);
// 	bob->equip(cure);
// 	bob->equip(cure2);

// 	std::cout << *bob;

// 	bob->use(0, *bob);
// 	bob->use(0, *bob);
// 	bob->use(-1, *bob);
// 	bob->use(10, *bob);

// 	bob->unequip(1);
// 	bob->unequip(1);
// 	bob->unequip(-1);

// 	bob->use(1, *bob);

// 	bob->equip(cure2);

// 	std::cout << std::endl;

// 	delete bob;
// 	delete bob2;
// 	delete ice2;
// 	delete ice3;
// 	delete cure;
// 	delete cure2;

// 	return (0);
// }
