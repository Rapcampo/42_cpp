/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:56:57 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/26 17:00:34 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define D_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"

#define I_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"

#define W_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."

#define E_MSG "This is unacceptable! I want to speak to the manager now."

class Harl{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
		int		levelDecoder(std::string level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};
