/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 17:52:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Animal::Animal( void ): _type("Animal")
{
	std::cout << GREEN_T << "Animal default constructor called" << DEFAULT_T << std::endl;
}

Animal::Animal( const Animal &src )
{
	std::cout << GREEN_T << "Animal copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Animal::~Animal( void )
{
	std::cout << RED_T << "Animal destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                                   Getters                                  */
/* ************************************************************************** */

const std::string	&Animal::getType( void ) const {return (this->_type);}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Animal &src )
{
	o << "Type: " << src.getType() << std::endl;
	o << "Brain: ";
	if (src.getBrain())
	{
		o << src.getBrain() << std::endl;
		o << *src.getBrain();
	}

	return (o);
}
