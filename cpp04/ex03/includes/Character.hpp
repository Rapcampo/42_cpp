/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:46:51 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/24 17:51:57 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter{
	private:
		int _inv[4];
		const std::string _name;

	public:
		Character(const std::string name);
		~Character();
		Character(const Character &src);
		Character &operator=(const Character &src);
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
