/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:15:49 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/17 19:16:36 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

# define CALL "BraiiiiiiinnnzzzZ..."

class Zombie{
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);

		void	annouce(void);
		Zombie* newZombie(std::string name);
		void	randomChump(std::string name);
	private:
		std::string _name;
};
