/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/23 18:27:01 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colours.hpp"

ScalarConverter::ScalarConverter(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the ScalarConverter class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the ScalarConverter class called.";
	ft_uncolorize();
	std::cout << std::endl;

	*this = copy;
}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy assignment of the ScalarConverter class called.";
	ft_uncolorize();
	std::cout << std::endl;

	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the ScalarConverter class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

// Methods

static void	printInvalid(void)
{
	std::cerr << ERROR_COLOUR << "Error: Wrong input."
		<< NO_COLOUR << std::endl
		<< ERROR_COLOUR << "Please provide a valid literal." 
		<< NO_COLOUR << std::endl;
}

static void	printFromChar(char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "\'" << c << "\'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "int: " << (static_cast<int>(c)) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << (static_cast<float>(c)) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << (static_cast<double>(c)) << std::endl;
}

static bool	isInt(std::string literal)
{
	long long	l;
	std::string	start = "+-0123456789";
	std::string	numbers = "0123456789";

	if (literal.length() < 12)
	{
		if (start.find(literal[0]) != std::string::npos)
		{
			for (size_t i = 1; i < literal.length(); ++i)
			{
				if (numbers.find(literal[i]) == std::string::npos)
					return (false);
			}
			l = atol(literal.c_str());
			if (l >= INT_MIN && l <= INT_MAX)
				return (true);
		}
	}
	return (false);
}

static void	printFromInt(int i)
{
	std::cout << "char: ";
	if (i >= 0 && i < 256 && isprint(i))
		std::cout << "\'" << (static_cast<char>(i)) << "\'" << std::endl;
	else if (i < 256)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << (static_cast<float>(i)) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << (static_cast<double>(i)) << std::endl;
}

static bool	isFloat(std::string literal)
{
	// double		d;
	// std::string	start = "+-0123456789";
	// std::string	numbers = "0123456789";

	
	// if (literal.length() < 12)
	// {
	// 	if (start.find(literal[0]) != std::string::npos)
	// 	{
	// 		for (size_t i = 1; i < literal.length(); ++i)
	// 		{
	// 			if (numbers.find(literal[i]) == std::string::npos)
	// 				return (false);
	// 		}
	// 		l = atol(literal.c_str());
	// 		if (l >= INT_MIN && l <= INT_MAX)
	// 			return (true);
	// 	}
	// }
	// return (false);
	(void)literal;
	return (true);
}

static void	printFromFloat(float f)
{
	std::cout << "char: ";
	if (f >= 0 && f < 256 && floor(f) == f && isprint(f))
		std::cout << "\'" << (static_cast<char>(f)) << "\'" << std::endl;
	else if (f < 256 && floor(f) == f)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (static_cast<double>(f) >= INT_MIN && static_cast<double>(f) <= INT_MAX)
		std::cout << (static_cast<int>(f)) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (f == std::numeric_limits<float>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "float: +" << f << "f" << std::endl;
	else if (f == floor(f))
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(7) << "float: " << f << "f" << std::endl;
	if (f == std::numeric_limits<float>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "double: +" << (static_cast<double>(f)) << std::endl;
	else if (f == floor(f))
		std::cout << std::fixed << std::setprecision(1) << "double: " << (static_cast<double>(f)) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(15) << "double: " << (static_cast<double>(f)) << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	std::cout << "test \"" << literal << "\"" << std::endl << std::endl;

	// identify and convert from chars
	if (!literal.length())
	{
		printInvalid();
		return ;
	}
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == literal[0])
		printFromChar(literal[1]);
	else if (literal.length() == 1 && !isdigit(literal[0]))
		printFromChar(literal[0]);
	// identify and convert from integers
	else if (isInt(literal))
		printFromInt(atoi(literal.c_str()));
	// identify and convert from floats
	else if (isFloat(literal))
		printFromFloat(atof(literal.c_str()));
	// identify and convert from doubles

	//nanfdsa
	//inff
	//+indsaga


	else
		printInvalid();
	//try
		// is it char
		// is it int
		// is it float
		// is it double
		// is it invalid


	// dvalue = atof(literal.c_str());
	bool test = std::string("abc") == "abc";
	std::cout << "test \"" << (test) <<  "\"" << std::endl;
	
	// fvalue = dvalue;

	// std::cout <<  std::setprecision (15) << "dvalue \"" << dvalue <<  "\"" << std::endl;
	// std::cout << "fvalue \"" << fvalue <<  "\"" << std::endl;
	// dvalue *= -1;
	// fvalue = dvalue;

	// std::cout << "dvalue \"" << dvalue <<  "\"" << std::endl;
	// std::cout << "fvalue \"" << fvalue <<  "\"" << std::endl;
	// std::stringstream s;
	// double integral;
	// integral = dvalue;
	// if (std::modf(dvalue, &integral) == 0)
	// 	s << std::fixed << std::setprecision(1) << integral;
	// else
	// 	s << std::fixed << std::setprecision(10) << dvalue;
	// std::cout << "dvalue as string \"" << s.str() <<  "\"" << std::endl;
	//get value (double)
	//print char
	//print int
	//print float
	//print double

	//catch
	//not a valid string
}
