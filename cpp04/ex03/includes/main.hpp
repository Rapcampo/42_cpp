/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:16:58 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 18:17:57 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

//colour prints

# define RST "\e[0m"
# define ULI "\e[4m"
# define BLN "\e[5m"
# define BLK "\e[1;30m"
# define RED "\e[1;31m"
# define GRN "\e[1;32m"
# define YLW "\e[1;33m"
# define BLU "\e[1;34m"
# define PRP "\e[1;35m"
# define CYN "\e[1;36m"
# define WHT "\e[1;37m"
# define CLR "\e[0;39m"

//debugging directives
//# define DEBUG

# ifdef DEBUG
#	define MSG(str) std::cout << str << std::endl;
# else
#	 define MSG(str);
# endif

