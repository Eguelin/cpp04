/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/08 13:29:20 by eguelin          ###   ########lyon.fr   */
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
/*                              Operator overload                             */
/* ************************************************************************** */

Animal	&Animal::operator=( const Animal &src )
{
	std::cout << YELLOW_T << "Animal assignation operator called" << DEFAULT_T << std::endl;

	this->_type = src._type;

	return (*this);
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

	return (o);
}
