/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:16 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 18:11:12 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Dog: public Animal
{
	public:

		Dog( void );
		Dog( const Dog &src );
		~Dog( void );

		void	makeSound( void ) const;
};

#endif
