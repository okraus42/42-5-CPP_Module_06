/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/25 13:55:52 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colours.hpp"

Base::~Base(void)
{
	return ;
}

Base	*Base::generate(void)
{
	int		r;

	srand(time(0));
	r = rand() % 3;
	if (r == 0)
		return(new A());
	else if (r == 1)
		return(new B());
	else if (r == 2)
		return (new C());
	else
	{
		std::cerr << "Generation failed" << std::endl;
		return (NULL);
	}
}

void	Base::identify(Base* base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "A ptr" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B ptr" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C ptr" << std::endl;
	else
		std::cerr << "Unknown" << std::endl;
}

void	Base::identify(Base& base)
{
	if (dynamic_cast<A*>(&base))
		std::cout << "A ref" << std::endl;
	else if (dynamic_cast<B*>(&base))
		std::cout << "B ref" << std::endl;
	else if (dynamic_cast<C*>(&base))
		std::cout << "C ref" << std::endl;
	else
		std::cerr << "Unknown" << std::endl;
}
