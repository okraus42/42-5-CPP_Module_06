/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/25 13:42:48 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "colours.hpp"

//https://www.geeksforgeeks.org/cpp-polymorphism/


int	main(void)
{
	Data		*dataPtr;
	Data		*dataInterpreted;	
	uintptr_t	numPtr;

	dataPtr = new Data;
	dataPtr->number = 42;
	for (int i = 0; i < 25; ++i)
		(i == 24) ? dataPtr->word[i] = 0 : dataPtr->word[i] = 'a' + i;
	std::cout << "Original data ptr: " << dataPtr << std::endl;
	std::cout << "Orig char: " << dataPtr->word << std::endl;
	std::cout << "Orig int: " << dataPtr->number << std::endl;
	numPtr = Serializer::serialize(dataPtr);
	std::cout << "\nnumptr hexa: " << std::hex << numPtr << std::endl;
	dataInterpreted = Serializer::deserialize(numPtr);
	std::cout << "\nSerialized ptr: " << std::dec << dataInterpreted << std::endl;
	std::cout << "Interpreted char: " << dataInterpreted->word << std::endl;
	std::cout << "Interpreted int: "<< dataInterpreted->number << std::endl;
	delete dataPtr;
	return (0);
}
