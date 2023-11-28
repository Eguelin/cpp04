/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:16:38 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Dog::Dog( void )
{
	std::cout << BLUE_T << "Dog default constructor called" << RESET << std::endl;

	this->_type = "Dog";
}

Dog::Dog( const Dog &src )
{
	std::cout << BLUE_T << "Dog copy constructor called" << RESET << std::endl;

	*this = src;
}

Dog::~Dog( void )
{
	std::cout << PURPLE_T << "Dog destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}
