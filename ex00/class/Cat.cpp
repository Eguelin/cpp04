/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:35:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/28 12:55:23 by eguelin          ###   ########lyon.fr   */
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
}

Cat::Cat( const Cat &src )
{
	std::cout << BLUE_T << "Cat copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Cat::~Cat( void )
{
	std::cout << PURPLE_T << "Cat destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}
