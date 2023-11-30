/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:03:32 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 18:31:24 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Ice::Ice( void ): AMateria("ice")
{
	std::cout << BLUE_T << "Ice default constructor called" << DEFAULT_T << std::endl;
}

Ice::Ice( const Ice &src ): AMateria("ice")
{
	std::cout << BLUE_T << "Ice copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Ice::~Ice( void )
{
	std::cout << PURPLE_T << "Ice destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Ice	&Ice::operator=( const Ice &src )
{
	std::cout << YELLOW_T << "Ice assignation operator called" << DEFAULT_T << std::endl;

	if (this != &src)
		this->_type = src.getType();

	return (*this);
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

AMateria	*Ice::clone( void ) const
{
	return(new Ice(*this));
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
