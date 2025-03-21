/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:24:09 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:24:24 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB{
	public:
		~HumanB();
		HumanB(std::string _name, Weapon &_wpn);
		void attack();
	private:
		std::string _name;
		Weapon &_wpn;
};
