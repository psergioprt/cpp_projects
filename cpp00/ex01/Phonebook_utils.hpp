/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:40:30 by pauldos-          #+#    #+#             */
/*   Updated: 2025/03/31 21:29:03 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP
# define PHONEBOOK_UTILS_HPP

#include <iostream>
#include "Contact.hpp"

std::string	insert_padding(int n);
std::string	resize_str(std::string str, unsigned max);
int	display_search_menu(Contact contacts[8]);

#endif
