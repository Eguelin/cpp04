/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:35:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/28 19:27:50 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Cat: public Animal
{
	public:

		Cat( void );
		Cat( const Cat &src );
		~Cat( void );

		Animal	&operator=( const Animal &src );

		Brain	*getBrain( void ) const;

		void	makeSound( void ) const;

	private:

		Brain	*_brain;
};

#endif
