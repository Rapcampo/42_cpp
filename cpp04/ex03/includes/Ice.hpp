/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:25:19 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 18:25:29 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria{
	public:
		Ice();
		~Ice();
		Ice(const Ice &src);
		Ice &operator=(const Ice &src);
		AMateria *clone() const;
		void use(ICharacter &target);
};
