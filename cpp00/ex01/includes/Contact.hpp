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
# include <iostream>
# include <string>

class Contact{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string dark_secret;

	public:
		Contact();
		~Contact();

};

#endif
