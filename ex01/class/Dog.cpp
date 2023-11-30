/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 11:25:01 by eguelin          ###   ########lyon.fr   */
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
	o << "Type: " << src.getType() << std::endl;
	o << "Brain: " << src.getBrain() << std::endl;
	o << *src.getBrain();

	return (o);
}
