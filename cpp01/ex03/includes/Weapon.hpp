/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:01:18 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/20 23:04:57 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class Weapon{
	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);
		std::string getType() const;
		void	setType(std::string type);
	private:
		std::string _type;
};
