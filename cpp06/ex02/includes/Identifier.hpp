/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:46:40 by rapcampo          #+#    #+#             */
/*   Updated: 2025/07/02 23:49:22 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>


class Base{
	public:
		virtual ~Base();
};

Base *generate(void);
void identify(Base &p);
void identify(Base *p);

class A : public Base {};
class B : public Base {};
class C : public Base {};
