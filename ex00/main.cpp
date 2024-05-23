/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/23 15:40:11 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"
#include "colours.hpp"

//https://www.geeksforgeeks.org/cpp-polymorphism/

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::convert(std::string(argv[1]));
	else
		std::cerr << ERROR_COLOUR << "Error: Wrong number of arguments."
		<< NO_COLOUR << std::endl
		<< ERROR_COLOUR << "Please provide a literal." 
		<< NO_COLOUR << std::endl;
	return (0);
}
