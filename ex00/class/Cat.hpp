/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:35:49 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/29 18:11:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Cat: public Animal
{
	public:

		Cat( void );
		Cat( const Cat &src );
		~Cat( void );

		void	makeSound( void ) const;
};

#endif
