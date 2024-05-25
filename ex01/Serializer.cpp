/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/25 13:38:54 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "colours.hpp"

Serializer::Serializer(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Serializer class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

Serializer::Serializer(const Serializer& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the Serializer class called.";
	ft_uncolorize();
	std::cout << std::endl;

	*this = copy;
}

Serializer	&Serializer::operator = (const Serializer &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy assignment of the Serializer class called.";
	ft_uncolorize();
	std::cout << std::endl;

	(void)src;
	return (*this);
}

Serializer::~Serializer(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the Serializer class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

// Methods
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}