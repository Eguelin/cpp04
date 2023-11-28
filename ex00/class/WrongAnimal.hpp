/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:25:55 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/27 17:25:18 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RESET "\033[0m"
# define RED_T "\033[31m"
# define GREEN_T "\033[32m"

class WrongAnimal
{
	public:

		WrongAnimal( void );
		WrongAnimal( const WrongAnimal &src );
		virtual ~WrongAnimal( void );

		WrongAnimal	&operator=( const WrongAnimal &src );

		const std::string	&getType( void ) const;

		void	makeSound( void ) const;

	protected:

		std::string	_type;
};

std::ostream	&operator<<( std::ostream &o, const WrongAnimal &src );

#endif
