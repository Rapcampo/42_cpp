/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:37:10 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/22 18:39:03 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

class Animal{
	protected:
		std::string type;

	public:
		Animal();
		~Animal();
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		void makeSound() const;
		std::string getType() const;
		void setType(const std::string type);
};
