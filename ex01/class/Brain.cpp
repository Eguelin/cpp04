/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:35:54 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/28 19:23:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Brain::Brain( void )
{
	std::stringstream ss;

	std::cout << BLUE_T << "Brain default constructor called" << DEFAULT_T << std::endl;

	for (int i = 0; i < 100; i++)
	{
		ss << i;
		this->_ideas[i] = "idea_" + ss.str();
		ss.str("");
	}
}

Brain::Brain( const Brain &src )
{
	std::cout << BLUE_T << "Brain copy constructor called" << DEFAULT_T << std::endl;

	*this = src;
}

Brain::~Brain( void )
{
	std::cout << PURPLE_T << "Brain destructor called" << DEFAULT_T << std::endl;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Brain	&Brain::operator=( const Brain &src )
{
	std::cout << YELLOW_T << "Brain operator= called" << DEFAULT_T << std::endl;

	if (this != &src)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];

	return (*this);
}

/* ************************************************************************** */
/*                              Getters & Setters                             */
/* ************************************************************************** */

const std::string	&Brain::getIdea( int index ) const
{
	if (index < 0 || index >= 100)
		std::cerr << RED_T << "Error: index out of range" << DEFAULT_T << std::endl;

	return (this->_ideas[index]);
}

void	Brain::setIdea( int index, const std::string &idea )
{
	if (index < 0 || index >= 100)
		std::cerr << RED_T << "Error: index out of range" << DEFAULT_T << std::endl;

	this->_ideas[index] = idea;
}

/* ************************************************************************** */
/*                               Print overload                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &o, const Brain &src )
{
	for (int i = 0; i < 100; i++)
		o << "ideas: " << src.getIdea(i) << std::endl;

	return (o);
}
