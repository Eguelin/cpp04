/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 13:42:35 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

/* ************************************************************************** */
/*                                 Destructors                                */
/* ************************************************************************** */

Floor::Floor( void ): _materia(NULL), _prev(NULL), _next(NULL)
{
	std::cout << GREEN_T << "Floor default constructor called" << DEFAULT_T << std::endl;

	if (!Floor::_isInit)
	{
		Floor::_isInit = true;
		this->_isPrimary = true;
	}
	else
		this->_isPrimary = false;
}

Floor::~Floor( void )
{
	std::cout << RED_T << "Floor destructor called" << DEFAULT_T << std::endl;

	if (this->_isPrimary)
		Floor::clearFloor();
	else if (this->_materia)
		delete this->_materia;
}

/* ************************************************************************** */
/*                       Public static member functions                       */
/* ************************************************************************** */

void	Floor::pushMateria( AMateria *materia )
{
	Floor	*tmp = Floor::_first;

	if (!Floor::_isInit || !materia || materia->getEquiped())
		return ;

	if (!Floor::_first)
		Floor::_first = new Floor(materia);
	else
	{
		while (tmp)
		{
			if (materia == tmp->_materia)
				return ;

			tmp = tmp->_next;
		}

		tmp = Floor::_first;
		Floor::_first = new Floor(materia);
		Floor::_first->_next = tmp;
		tmp->_prev = Floor::_first;
	}
}

void	Floor::takeMateria( AMateria *materia )
{
	Floor	*tmp = Floor::_first;

	if (!Floor::_isInit || !materia)
		return ;

	while (tmp)
	{
		if (materia == tmp->_materia)
		{
			if (tmp == Floor::_first)
				Floor::_first = tmp->_next;
			if (tmp->_prev)
				tmp->_prev->_next = tmp->_next;
			if (tmp->_next)
				tmp->_next->_prev = tmp->_prev;
			tmp->_materia = NULL;

			delete tmp;

			return ;
		}

		tmp = tmp->_next;
	}
}

void	Floor::clearFloor( void )
{
	Floor	*tmp;

	while (Floor::_first)
	{
		tmp = Floor::_first;
		Floor::_first = Floor::_first->_next;

		delete tmp;
	}
}

/* ************************************************************************** */
/*                             Private constructor                            */
/* ************************************************************************** */

Floor::Floor( AMateria *materia ): _isPrimary(false), _materia(materia), _prev(NULL), _next(NULL)
{
	std::cout << GREEN_T << "Floor parametric constructor called" << DEFAULT_T << std::endl;
}

Floor::Floor( const Floor &src )
{
	(void)src;
}

/* ************************************************************************** */
/*                          Private operator overload                         */
/* ************************************************************************** */

Floor	&Floor::operator=( const Floor &src )
{
	(void)src;

	return (*this);
}

/* ************************************************************************** */
/*                       Private static member variables                      */
/* ************************************************************************** */

bool	Floor::_isInit = false;
Floor	*Floor::_first = NULL;
