/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/24 14:23:00 by okraus           ###   ########.fr       */
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
	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return (true);
	if (literal.length() < 2)
		return (false);
	// what about +.f ??;
	float		f;
	int			period;
	std::string	start = "+-0123456789";
	std::string	numbers = "0123456789";

	period = 0;
	for (size_t p = 0; p < literal.length(); ++p)
	{
		if (literal[p] == '.')
			++period;
	}
	if (period != 1 || literal[literal.length() - 1] != 'f')
		return (false);
	if (start.find(literal[0]) != std::string::npos)
	{
		for (size_t i = 1; i < literal.length() - 1; ++i)
		{
			if (numbers.find(literal[i]) == std::string::npos
				&& (literal[i] != '.' && numbers.find(literal[i - 1]) != std::string::npos))
				return (false);
		}
		f = atof(literal.c_str());
		std::cout << "test f is: " << f << "\n";
		if (f == std::numeric_limits<float>::infinity() //not wrking for inf check
			|| -f == std::numeric_limits<float>::infinity()
			|| f != f) //odd property of nans)
			return (false);
		return (true);
	}
	return (false);
}

static void	printFromFloat(float f)
{
	std::cout << "real f is: " << f << "\n";
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

static bool	isDouble(std::string literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (true);
	if (literal.length() < 2)
		return (false);
	// what about +.f ??;
	double		d;
	int			period;
	std::string	start = "+-0123456789";
	std::string	numbers = "0123456789";

	period = 0;
	for (size_t p = 0; p < literal.length(); ++p)
	{
		if (literal[p] == '.')
			++period;
	}
	if (period != 1)
		return (false);
	if (start.find(literal[0]) != std::string::npos)
	{
		for (size_t i = 1; i < literal.length() - 1; ++i)
		{
			if (numbers.find(literal[i]) == std::string::npos
				&& (literal[i] != '.' && numbers.find(literal[i - 1]) != std::string::npos))
				return (false);
		}
		d = atof(literal.c_str());
		std::cout << "test d is: " << d << "\n";
		if (d == std::numeric_limits<double>::infinity() //not wrking for inf check
			|| -d == std::numeric_limits<double>::infinity()
			|| d != d) //odd property of nans)
			return (false);
		return (true);
	}
	return (false);
}

static void	printFromDouble(double d)
{
	std::cout << "real d is: " << d << "\n";
	std::cout << "char: ";
	if (d >= 0 && d < 256 && floor(d) == d && isprint(d))
		std::cout << "\'" << (static_cast<char>(d)) << "\'" << std::endl;
	else if (d < 256 && floor(d) == d)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (d >= INT_MIN && d <= INT_MAX)
		std::cout << (static_cast<int>(d)) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (d == std::numeric_limits<double>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "float: +" << (static_cast<float>(d)) << "f" << std::endl;
	else if ((static_cast<float>(d)) == std::numeric_limits<float>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "float: " << "impossible" << std::endl;
	else if ((static_cast<float>(d)) == floor((static_cast<float>(d))))
		std::cout << std::fixed << std::setprecision(1) << "float: " << (static_cast<float>(d)) << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(7) << "float: " << (static_cast<float>(d)) << "f" << std::endl;
	if (d == std::numeric_limits<double>::infinity())
		std::cout << std::fixed << std::setprecision(1) << "double: +" << d << std::endl;
	else if (d == floor(d))
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	else
		std::cout << std::fixed << std::setprecision(15) << "double: " << d << std::endl;
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
	else if (isDouble(literal))
		printFromDouble(atof(literal.c_str()));
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
	// bool test = std::string("abc") == "abc";
	// std::cout << "test \"" << (test) <<  "\"" << std::endl;
	
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
