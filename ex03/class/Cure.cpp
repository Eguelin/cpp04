/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:04:02 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 12:57:18 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Cure::Cure( void ): AMateria("cure")
{
	std::cout << BLUE_T << "Cure default constructor called" << DEFAULT_T << std::endl;
}

Cure::Cure( const Cure &src ): AMateria("cure")
{
	std::cout << BLUE_T << "Cure copy constructor called" << DEFAULT_T << std::endl;

	(void)src;
}

Cure::~Cure( void )
{
	std::cout << PURPLE_T << "Cure destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

AMateria	*Cure::clone( void ) const
{
	return(new Cure(*this));
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
