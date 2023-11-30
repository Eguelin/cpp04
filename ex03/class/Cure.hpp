/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:04:02 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 18:33:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Cure: public AMateria
{
	public:

		Cure( void );
		Cure( const Cure &src );
		~Cure( void );

		Cure	&operator=( const Cure &src );

		AMateria*	clone( void ) const;
		void		use( ICharacter &target );

	private:

};

#endif
