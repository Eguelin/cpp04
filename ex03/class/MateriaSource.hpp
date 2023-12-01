/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:07:52 by eguelin           #+#    #+#             */
/*   Updated: 2023/12/01 18:52:54 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:

		MateriaSource( void );
		MateriaSource( const MateriaSource &src );
		~MateriaSource( void );

		MateriaSource	&operator=( const MateriaSource &src );

		const AMateria		*const *getInventory( void ) const;

		void		learnMateria( AMateria *m );
		AMateria*	createMateria( const std::string &type );

	private:

		AMateria	*_inventory[4];

};

std::ostream	&operator<<( std::ostream &o, const MateriaSource &src );

#endif
