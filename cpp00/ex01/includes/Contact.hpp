/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:17 by rapcampo          #+#    #+#             */
/*   Updated: 2025/03/06 18:06:49 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact{
	private:
		std::string fn;
		std::string ln;
		std::string nn;
		std::string pn;
		std::string ds;

	public:
		//constructors
		Contact();
		~Contact();
		Contact(std::string fn, std::string ln, std::string nn,
				std::string pn, std::string ds);

		//getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};
#endif
