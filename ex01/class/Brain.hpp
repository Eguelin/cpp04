/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:35:54 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/30 11:48:51 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

# define DEFAULT_T "\033[0m"
# define RED_T "\033[31m"
# define YELLOW_T "\033[33m"
# define BLUE_T "\033[34m"
# define PURPLE_T "\033[35m"

class Brain
{
	public:

		Brain( void );
		Brain( const Brain &src );
		~Brain( void );

		Brain	&operator=( const Brain &src );

		const std::string	&getIdea( int index ) const;
		void				setIdea( int index, const std::string &idea );

	private:

	std::string	_ideas[100];
};

std::ostream	&operator<<( std::ostream &o, const Brain &src );

#endif
