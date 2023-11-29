/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 17:27:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Dog: public Animal
{
	public:

		Dog( void );
		Dog( const Dog &src );
		~Dog( void );

		Dog		&operator=( const Dog &src );

		virtual Animal	&operator=( const Animal &src );

		Brain	*getBrain( void ) const;

		void	makeSound( void ) const;

	private:

		Brain	*_brain;
};

std::ostream	&operator<<( std::ostream &o, const Dog &src );

#endif
