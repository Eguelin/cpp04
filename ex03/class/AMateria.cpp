/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:50 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 18:54:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

AMateria::AMateria( void )
{
}

AMateria::AMateria( const AMateria &src )
{
	(void)src;
}

AMateria::AMateria( const std::string &type ): _type(type), _equiped(false)
{
	std::cout << GREEN_T << "AMateria constructor called" << DEFAULT_T << std::endl;

	Floor::pushMateria(this);
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

	(void)src;

	return (*this);
}

/* ************************************************************************** */
/*                              Getters & Setters                             */
/* ************************************************************************** */

const std::string	&AMateria::getType( void ) const {return (this->_type);}

bool	AMateria::getEquiped( void ) const {return (this->_equiped);}

void	AMateria::setEquiped( bool equiped ) {this->_equiped = equiped;}

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
