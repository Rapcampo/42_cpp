/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:49:35 by rapcampo          #+#    #+#             */
/*   Updated: 2025/04/22 18:49:46 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		~Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		void makeSound() const;
		std::string getType() const;
};
