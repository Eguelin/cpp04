/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 19:09:44 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

/* ************************************************************************** */
/*                                 Destructors                                */
/* ************************************************************************** */

Floor::~Floor( void )
{
	delete this->_materia;
}

/* ************************************************************************** */
/*                              Operator overload                             */
/* ************************************************************************** */

Floor	&Floor::operator=( const Floor &src )
{
	(void)src;

	return (*this);
}

/* ************************************************************************** */
/*                       Public static member functions                       */
/* ************************************************************************** */

void	Floor::incrementNbCharacters( void )
{
	Floor::_nbCharacters++;
}

void	Floor::decrementNbCharacters( void )
{
	if (Floor::_nbCharacters)
	{
		Floor::_nbCharacters--;
		if (!Floor::_nbCharacters && !Floor::_nbMateriaSources)
			Floor::clearFloor();
	}
}

void	Floor::incrementNbMateriaSources( void )
{
	Floor::_nbMateriaSources++;
}

void	Floor::decrementNbMateriaSources( void )
{
	if (Floor::_nbMateriaSources)
	{
		Floor::_nbMateriaSources--;
		if (!Floor::_nbCharacters && !Floor::_nbMateriaSources)
			Floor::clearFloor();
	}
}

void	Floor::pushMateria( AMateria *materia )
{
	Floor	*tmp = Floor::_first;

	if (!materia | materia->getEquiped())
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

	if (!materia)
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

Floor::Floor( void )
{
}

Floor::Floor( AMateria *materia ) : _materia(materia), _prev(NULL), _next(NULL)
{
}

Floor::Floor( const Floor &src )
{
	(void)src;
}

/* ************************************************************************** */
/*                       Private static member variables                      */
/* ************************************************************************** */

int		Floor::_nbCharacters = 0;
int		Floor::_nbMateriaSources = 0;
Floor	*Floor::_first = NULL;
