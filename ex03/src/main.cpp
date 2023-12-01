/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:32:47 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 19:25:47 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void )
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	src->learnMateria(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

// int main( void )
// {
// 	AMateria	*ice = new Ice();
// 	AMateria	*ice2 = ice->clone();
// 	AMateria	*ice3 = ice->clone();
// 	AMateria	*cure = new Cure();
// 	AMateria	*cure2 = cure->clone();

// 	std::cout << "ice: " << ice << std::endl;
// 	std::cout << *ice;
// 	std::cout << "ice2: " << ice2 << std::endl;
// 	std::cout << *ice2;

// 	*cure = *ice;

// 	std::cout << "cure: " << cure << std::endl;
// 	std::cout << *cure;
// 	std::cout << "cure2: " << cure2 << std::endl;
// 	std::cout << *cure2;
// 	std::cout << std::endl;

// 	ICharacter	*max = new Character("Max");

// 	max->unequip(1);
// 	max->equip(ice);
// 	max->equip(ice);
// 	max->equip(cure);
// 	max->equip(ice2);
// 	max->equip(cure2);
// 	max->equip(ice3);
// 	max->unequip(1);
// 	max->unequip(1);
// 	max->use(1, *max);
// 	max->equip(ice3);
// 	max->use(0, *max);
// 	max->use(-1, *max);
// 	max->use(4, *max);

// 	std::cout << "max: " << max << std::endl;
// 	std::cout << *max;
// 	std::cout << std::endl;

// 	Character	mika("Mika");

// 	mika.unequip(0);
// 	mika.equip(ice);
// 	mika.equip(cure);
// 	mika.equip(ice2);
// 	mika.equip(cure2);
// 	mika.equip(ice3);

// 	mika.unequip(1);
// 	mika.unequip(1);
// 	mika.unequip(-1);
// 	mika.unequip(4);

// 	mika.use(0, *max);
// 	mika.use(1, *max);
// 	mika.use(-1, *max);
// 	mika.use(4, *max);

// 	mika.equip(ice3);

// 	std::cout << std::endl;

// 	Character mika2(mika);

// 	mika2.unequip(0);

// 	std::cout << mika;
// 	std::cout << mika2 << std::endl;

// 	delete ice;
// 	delete ice2;
// 	delete cure;
// 	delete cure2;
// 	delete max;

// 	return (0);
// }
