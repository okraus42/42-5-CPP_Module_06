/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/23 18:10:48 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP
# include <iostream>
# include <string>
# include <climits>
# include <limits>
# include <cmath>
# include <cfloat>
# include <iomanip>
# include <stdlib.h>

class ScalarConverter
{
	public:
		static void	convert(std::string literal);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter &operator=(const ScalarConverter& c);
		~ScalarConverter(void);
};

#endif