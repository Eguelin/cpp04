/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:35:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/28 19:28:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Cat::Cat( void )
{
	std::cout << BLUE_T << "Cat default constructor called" << DEFAULT_T << std::endl;

	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat &src )
{
	std::cout << BLUE_T << "Cat copy constructor called" << DEFAULT_T << std::endl;

	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

Cat::~Cat( void )
{
	std::cout << PURPLE_T << "Cat destructor called" << DEFAULT_T << std::endl;

	delete this->_brain;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Animal	&Cat::operator=( const Animal &src )
{
	std::cout << YELLOW_T << "Cat operator= called" << DEFAULT_T << std::endl;

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

Brain	*Cat::getBrain( void ) const {return (this->_brain);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}
