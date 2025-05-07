/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:16:15 by rapcampo          #+#    #+#             */
/*   Updated: 2025/05/02 18:16:48 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"
 
//#ifdef DEBUG
int main(){
	MSG(RED "\n\n*** DEBUG BUILD ***\n\n" RST);

	MSG("\n SUBJECT TESTS");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	MSG("\e[1;31m\n\n EXTRA TESTS \n\e[0m");

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	AMateria *tmp2;
	tmp2 = src->createMateria("Lice");
	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	delete bob;
	delete me;
	delete src;
	return 0;
}

//#else

/*int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}
#endif*/
