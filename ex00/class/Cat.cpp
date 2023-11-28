/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:35:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:16:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Cat::Cat( void )
{
	std::cout << BLUE_T << "Cat default constructor called" << RESET << std::endl;

	this->_type = "Cat";
}

Cat::Cat( const Cat &src )
{
	std::cout << BLUE_T << "Cat copy constructor called" << RESET << std::endl;

	*this = src;
}

Cat::~Cat( void )
{
	std::cout << PURPLE_T << "Cat destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Cat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}
