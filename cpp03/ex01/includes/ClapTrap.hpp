/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:21:48 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/15 19:36:24 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class ClapTrap{
	private:
		std::string _name;
		unsigned int _hp;
		unsigned int _energy;
		unsigned int _attack;

	public:
		ClapTrap(const std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
