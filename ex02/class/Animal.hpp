/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 11:50:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

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

		Animal	&operator=( const Animal &src );

		const std::string	&getType( void ) const;

		virtual void	makeSound( void ) const = 0;

	protected:

		std::string	_type;
};

std::ostream	&operator<<( std::ostream &o, const Animal &src );

#endif
