/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:17:50 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 16:51:26 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

# define DEFAULT_T "\033[0m"
# define RED_T "\033[31m"
# define GREEN_T "\033[32m"
# define YELLOW_T "\033[33m"

class AMateria
{
	public:

		AMateria( const AMateria &src );
		AMateria( const std::string &type );
		virtual ~AMateria( void );

		AMateria	&operator=( const AMateria &src );

		const std::string	&getType( void ) const;

		virtual AMateria	*clone( void ) const = 0;
		virtual void		use( ICharacter &target );

	protected:

		std::string	_type;

	private:

		AMateria( void );
};

std::ostream	&operator<<( std::ostream &o, const AMateria &src );

#endif
