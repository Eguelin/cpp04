/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:35:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:25:56 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

WrongCat::WrongCat( void )
{
	std::cout << BLUE_T << "WrongCat default constructor called" << RESET << std::endl;

	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &src )
{
	std::cout << BLUE_T << "WrongCat copy constructor called" << RESET << std::endl;

	*this = src;
}

WrongCat::~WrongCat( void )
{
	std::cout << PURPLE_T << "WrongCat destructor called" << RESET << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	WrongCat::makeSound( void ) const
{
	std::cout << "Miaou" << std::endl;
}
