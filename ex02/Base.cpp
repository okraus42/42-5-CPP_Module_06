/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/25 14:12:29 by okraus           ###   ########.fr       */
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
	{
		A *ptr = new A();
		ft_colorize(reinterpret_cast<uintptr_t>(ptr));
		std::cout << "GENERATING A";
		ft_uncolorize();
		std::cout << std::endl;
		return(ptr);
	}
	else if (r == 1)
	{
		B *ptr = new B();
		ft_colorize(reinterpret_cast<uintptr_t>(ptr));
		std::cout << "GENERATING B";
		ft_uncolorize();
		std::cout << std::endl;
		return(ptr);
	}
	else if (r == 2)
	{
		C *ptr = new C();
		ft_colorize(reinterpret_cast<uintptr_t>(ptr));
		std::cout << "GENERATING C";
		ft_uncolorize();
		std::cout << std::endl;
		return (ptr);
	}
	else
	{
		std::cerr << ERROR_COLOUR << "Generation failed" << NO_COLOUR << std::endl;
		return (NULL);
	}
}

void	Base::identify(Base* base)
{
	if (dynamic_cast<A*>(base))
	{
		ft_colorize(reinterpret_cast<uintptr_t>(base));
		std::cout << "A ptr";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else if (dynamic_cast<B*>(base))
	{
		ft_colorize(reinterpret_cast<uintptr_t>(base));
		std::cout << "B ptr";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else if (dynamic_cast<C*>(base))
	{
		ft_colorize(reinterpret_cast<uintptr_t>(base));
		std::cout << "C ptr";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else
	{
		std::cerr << ERROR_COLOUR << "Unknown" << NO_COLOUR << std::endl;
	}
}

void	Base::identify(Base& base)
{
	if (dynamic_cast<A*>(&base))
	{
		ft_colorize(reinterpret_cast<uintptr_t>(&base));
		std::cout << "A ref";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else if (dynamic_cast<B*>(&base))
	{
		ft_colorize(reinterpret_cast<uintptr_t>(&base));
		std::cout << "B ref";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else if (dynamic_cast<C*>(&base))
	{
		ft_colorize(reinterpret_cast<uintptr_t>(&base));
		std::cout << "C ref";
		ft_uncolorize();
		std::cout << std::endl;
	}
	else
	{
		std::cerr << ERROR_COLOUR << "Unknown" << NO_COLOUR << std::endl;
	}
}
