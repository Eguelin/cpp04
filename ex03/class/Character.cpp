/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:13:40 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 19:13:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Character::Character( void ): _name("default")
{
	std::cout << GREEN_T << "Character default constructor called" << DEFAULT_T << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	Floor::incrementNbCharacters();
}

Character::Character( const std::string &name ): _name(name)
{
	std::cout << GREEN_T << "Character constructor called" << DEFAULT_T << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character( const Character &src )
{
	std::cout << GREEN_T << "Character copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Character::~Character( void )
{
	std::cout << RED_T << "Character destructor called" << DEFAULT_T << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			this->_inventory[i]->setEquiped(false);
			Floor::pushMateria(this->_inventory[i]);
		}
	}

	Floor::decrementNbCharacters();
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Character	&Character::operator=( const Character &src )
{
	std::cout << YELLOW_T << "Character assignation operator called" << DEFAULT_T << std::endl;

	if (this == &src)
		return (*this);

	this->_name = src.getName();

	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&Character::getName( void ) const {return(this->_name);}

const AMateria		*const *Character::getInventory( void ) const {return(this->_inventory);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Character::equip( AMateria *m )
{
	if (!m | m->getEquiped())
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			continue;

		std::cout << this->_name << " equiped " << m->getType() << std::endl;

		Floor::takeMateria(m);
		this->_inventory[i] = m;
		m->setEquiped(true);

		return ;
	}
}

void	Character::unequip( int idx )
{
	if (idx < 0 || idx > 3)
		return ;

	if (this->_inventory[idx])
	{
		std::cout << this->_name << " unequiped " << this->_inventory[idx]->getType() << std::endl;

		this->_inventory[idx]->setEquiped(false);
		Floor::pushMateria(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
}

void	Character::use( int idx, ICharacter &target )
{
	if (idx < 0 || idx > 3)
		return ;

	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);

	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const ICharacter &src )
{
	o << "Name: " << src.getName() << std::endl;

	return (o);
}

std::ostream	&operator<<( std::ostream &o, const Character &src )
{
	o << "Name: " << src.getName() << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.getInventory()[i])
			o << "Inventory[" << i << "]: " << *src.getInventory()[i];
		else
			o << "Inventory[" << i << "]: NULL" << std::endl;
	}

	return (o);
}
