/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:33:08 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/07 22:03:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include <iomanip>

# define MAX_CONTACTS 8

class PhoneBook{
	private:
		Contact contact[MAX_CONTACTS];
		int entries;
	public:
		PhoneBook();
		~PhoneBook();

		//setter
		void	addContact(std::string fn, std::string ln, std::string nn,
				std::string pn, std::string ds);
		//getter
		void	getInfo() const;
};

#endif
