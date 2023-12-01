/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 19:02:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include <iostream>

class AMateria;

class Floor
{
	public:

		~Floor( void );

		static void	incrementNbCharacters( void );
		static void	decrementNbCharacters( void );
		static void	incrementNbMateriaSources( void );
		static void	decrementNbMateriaSources( void );

		static void	pushMateria( AMateria *materia );
		static void	takeMateria( AMateria *materia );

		static void	clearFloor( void );

	private:

		static int		_nbCharacters;
		static int		_nbMateriaSources;
		static Floor	*_first;

		AMateria	*_materia;

		Floor	*_prev;
		Floor	*_next;

		Floor( void );
		Floor( AMateria *materia );
		Floor( const Floor &src );

		Floor	&operator=( const Floor &src );
};

# include "AMateria.hpp"

#endif
