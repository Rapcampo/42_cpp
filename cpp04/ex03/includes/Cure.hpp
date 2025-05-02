/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:20:16 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 18:25:15 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : virtual public AMateria{
	public:
		Cure();
		~Cure();
		Cure(const Cure &src);
		Cure &operator=(const Cure &src);
		std::string const &getType() const;	
		Cure *clone() const;
		void use(ICharacter &target);
};
