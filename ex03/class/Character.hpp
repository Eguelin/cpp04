/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:13:40 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 19:21:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class Character: public ICharacter
{
	public:

		Character( void );
		Character( const std::string &name );
		Character( const Character &src );
		~Character( void );

		Character	&operator=( const Character &src );

		const std::string	&getName( void ) const;
		const AMateria		* const *getInventory( void ) const;

		void	equip( AMateria *m );
		void	unequip( int idx );
		void	use( int idx, ICharacter &target );

	private:

		std::string	_name;
		AMateria	*_inventory[4];
};

std::ostream	&operator<<( std::ostream &o, const ICharacter &src );
std::ostream	&operator<<( std::ostream &o, const Character &src );

#endif
