/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:50 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 17:32:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

AMateria::AMateria( void ): _type("default")
{
	std::cout << GREEN_T << "AMateria default constructor called" << DEFAULT_T << std::endl;
}

AMateria::AMateria( const AMateria &src )
{
	std::cout << GREEN_T << "AMateria copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

AMateria::AMateria( const std::string &type ): _type(type)
{
	std::cout << GREEN_T << "AMateria constructor called" << DEFAULT_T << std::endl;
}

AMateria::~AMateria( void )
{
	std::cout << RED_T << "AMateria destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

AMateria	&AMateria::operator=( const AMateria &src )
{
	std::cout << YELLOW_T << "AMateria assignation operator called" << DEFAULT_T << std::endl;

	if (this != &src)
		this->_type = src.getType();

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&AMateria::getType( void ) const {return (this->_type);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	AMateria::use( ICharacter &target )
{
	(void)target;
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const AMateria &src )
{
	o << "Type: " << src.getType() << std::endl;

	return (o);
}
