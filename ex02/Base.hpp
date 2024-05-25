/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/25 13:54:04 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		virtual ~Base(void);

		static Base	*generate(void);
		static void	identify(Base* base);
		static void	identify(Base& base);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif