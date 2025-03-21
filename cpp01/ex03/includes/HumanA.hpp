/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:10:45 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:24:55 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA{
	public:
		~HumanA();
		HumanA(std::string, Weapon &);
		void attack();
	private:
		std::string _name;
		Weapon &_wpn;
};
