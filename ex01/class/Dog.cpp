/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 17:45:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Dog::Dog( void ): Animal()
{
	std::cout << BLUE_T << "Dog default constructor called" << DEFAULT_T << std::endl;

	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog &src )
{
	std::cout << BLUE_T << "Dog copy constructor called" << DEFAULT_T << std::endl;

	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

Dog::~Dog( void )
{
	std::cout << PURPLE_T << "Dog destructor called" << DEFAULT_T << std::endl;

	delete this->_brain;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Dog		&Dog::operator=( const Dog &src )
{
	std::cout << YELLOW_T << "Dog operator= called" << DEFAULT_T << std::endl;

	if (this != &src)
	{
		this->_type = src._type;
		*this->_brain = *src._brain;
	}

	return (*this);
}

Animal	&Dog::operator=( const Animal &src )
{
	std::cout << YELLOW_T << "Dog::Animal operator= called" << DEFAULT_T << std::endl;
	if (this != &src)
	{
		this->_type = src.getType();

		if (!src.getBrain())
			return (*this);

		*this->_brain = *src.getBrain();
	}

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

Brain	*Dog::getBrain( void ) const {return (this->_brain);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Dog &src )
{
	o << "Dog type: " << src.getType() << std::endl;
	o << "Dog brain: " << src.getBrain() << std::endl;
	o << "Dog " << *src.getBrain();

	return (o);
}
