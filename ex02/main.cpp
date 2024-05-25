/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/25 13:59:50 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "colours.hpp"

//https://www.geeksforgeeks.org/cpp-polymorphism/


int	main(void)
{
	Base	*base;

	base = Base::generate();
	std::cout << std::endl << "Generating base" << std::endl;
	Base::identify(base);
	Base::identify(base);
	delete base;
	return (0);
}
