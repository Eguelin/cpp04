/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/02 13:36:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include <iostream>

# define DEFAULT_T "\033[0m"
# define RED_T "\033[31m"
# define GREEN_T "\033[32m"
# define YELLOW_T "\033[33m"

class AMateria;

class Floor
{
	public:

		Floor( void );
		~Floor( void );

		static void	pushMateria( AMateria *materia );
		static void	takeMateria( AMateria *materia );

		static void	clearFloor( void );

	private:

		static bool		_isInit;
		static Floor	*_first;

		bool	_isPrimary;

		AMateria	*_materia;

		Floor	*_prev;
		Floor	*_next;

		Floor( AMateria *materia );
		Floor( const Floor &src );

		Floor	&operator=( const Floor &src );
};

# include "AMateria.hpp"

#endif
