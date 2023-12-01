/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:03:32 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 12:56:44 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Ice: public AMateria
{
	public:

		Ice( void );
		Ice( const Ice &src );
		~Ice( void );

		AMateria*	clone( void ) const;
		void		use( ICharacter &target );
};

#endif
