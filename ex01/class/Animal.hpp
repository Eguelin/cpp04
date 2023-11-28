/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/28 19:17:33 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define DEFAULT_T "\033[0m"
# define RED_T "\033[31m"
# define GREEN_T "\033[32m"
# define YELLOW_T "\033[33m"

class Animal
{
	public:

		Animal( void );
		Animal( const Animal &src );
		virtual ~Animal( void );

		virtual Animal	&operator=( const Animal &src );

		const std::string	&getType( void ) const;
		virtual Brain		*getBrain( void ) const;

		virtual void	makeSound( void ) const;

	protected:

		std::string	_type;
};

std::ostream	&operator<<( std::ostream &o, const Animal &src );

#endif
