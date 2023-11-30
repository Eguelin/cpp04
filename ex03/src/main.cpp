/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:32:47 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 19:35:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int main( void )
{
	AMateria	*ice = new Ice();
	AMateria	*ice2 = ice->clone();
	AMateria	*ice3 = ice->clone();
	AMateria	*cure = new Cure();
	AMateria	*cure2 = cure->clone();

	std::cout << "ice: " << ice << std::endl;
	std::cout << *ice;
	std::cout << "ice2: " << ice2 << std::endl;
	std::cout << *ice2;

	std::cout << "cure: " << cure << std::endl;
	std::cout << *cure;
	std::cout << "cure2: " << cure2 << std::endl;
	std::cout << *cure2;

	ICharacter	*max = new Character("Max");

	max->equip(ice);
	max->equip(ice);
	max->equip(cure);
	max->equip(ice2);
	max->equip(cure2);
	max->equip(ice3);
	max->unequip(1);
	max->use(1, *max);
	max->equip(ice3);
	max->use(0, *max);
	max->use(-1, *max);
	max->use(4, *max);

	std::cout << "max: " << max << std::endl;
	std::cout << *max;

	Character	mika("Mika");

	mika.equip(ice);
	mika.equip(cure);
	mika.equip(ice2);
	mika.equip(cure2);

	Character mika2(mika);

	mika.unequip(0);
	mika.unequip(-1);
	mika.unequip(4);

	mika.use(0, *max);
	mika.use(1, *max);
	mika.use(-1, *max);
	mika.use(4, *max);

	std::cout << mika;
	std::cout << mika2;

	delete ice;
	delete ice2;
	delete cure;
	delete cure2;
	delete max;

	return (0);
}

// ex03 in progress
