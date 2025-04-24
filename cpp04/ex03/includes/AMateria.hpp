/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:34:24 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/24 17:39:23 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ICharacter.hpp"
# include <string>

class AMateria{
	protected:
		std::string _type;
	
	public:
		AMateria(std::string const &type);
		~AMateria();
		AMateria(const AMateria &src);
		AMateria &operator=(const AMateria &src);
		std::string const & getType() const; //returns the materia type
		virtual AMateria *clone() const = 0;
		virtual void use (ICharacter &target);
};
