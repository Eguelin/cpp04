/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:07:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 19:13:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

MateriaSource::MateriaSource( void )
{
	std::cout << GREEN_T << "MateriaSource default constructor called" << DEFAULT_T << std::endl;

	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;

	Floor::incrementNbMateriaSources();
}

MateriaSource::MateriaSource( const MateriaSource &src )
{
	std::cout << GREEN_T << "MateriaSource copy constructor called" << DEFAULT_T << std::endl;

	*this = src;

	Floor::incrementNbMateriaSources();
}

MateriaSource::~MateriaSource( void )
{
	std::cout << RED_T << "MateriaSource destructor called" << DEFAULT_T << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			this->_inventory[i]->setEquiped(false);
			Floor::pushMateria(this->_inventory[i]);
		}
	}

	Floor::decrementNbMateriaSources();
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

MateriaSource	&MateriaSource::operator=( const MateriaSource &src )
{
	std::cout << YELLOW_T << "MateriaSource assignation operator called" << DEFAULT_T << std::endl;

	if (this == &src)
		return (*this);

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

const AMateria		*const *MateriaSource::getInventory( void ) const {return(this->_inventory);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	MateriaSource::learnMateria( AMateria *m )
{
	if (!m | m->getEquiped())
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			continue;

		std::cout << "MateriaSource learn materia: " << m->getType() << std::endl;

		Floor::takeMateria(m);
		this->_inventory[i] = m;
		m->setEquiped(true);

		return ;
	}
}

AMateria*	MateriaSource::createMateria( const std::string &type )
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i]->getType() != type)
			continue;

		std::cout << "MateriaSource create materia: " << this->_inventory[i]->getType() << std::endl;

		return (this->_inventory[i]->clone());
	}

	return (NULL);
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const MateriaSource &src )
{
	o << "MateriaSource" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.getInventory()[i])
			o << "Inventory[" << i << "]: " << *src.getInventory()[i];
		else
			o << "Inventory[" << i << "]: NULL" << std::endl;
	}

	return (o);
}
