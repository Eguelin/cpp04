/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/08 13:29:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

WrongAnimal::WrongAnimal( void ): _type("WrongAnimal")
{
	std::cout << GREEN_T << "WrongAnimal default constructor called" << DEFAULT_T << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src )
{
	std::cout << GREEN_T << "WrongAnimal copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << RED_T << "WrongAnimal destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &src )
{
	std::cout << YELLOW_T << "WrongAnimal assignation operator called" << DEFAULT_T << std::endl;

	this->_type = src._type;

	return (*this);
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&WrongAnimal::getType( void ) const {return (this->_type);}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const WrongAnimal &src )
{
	o << "Type: " << src.getType() << std::endl;
	return (o);
}
