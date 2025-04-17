/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:15:43 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/17 15:24:44 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap(const std::string name);
		~FragTrap(void);
		FragTrap(const FragTrap &src);
		FragTrap &operator=(const FragTrap &src);
		void	attack(const std::string &target);
		void	highFivesGuys(void);
};
