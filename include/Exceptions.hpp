/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Exceptions.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 18:05:00 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/06/13 17:56:10 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# include "Common.hpp"
# include <exception>
FT_BEGIN

// Simple strerror exception wrapper.
struct GenericErrnoExecption : public std::exception
{
	const char* what() const throw() override {
        return (strerror(errno));
	}
};

// File cannot be located.
struct FileNotFoundExecption : public std::exception
{
	const char* what() const throw() override {
        return ("File could not be located");
	}
};

/**
 * Print the exception and exit the application.
 * 
 * @param[in] Exception The exception to print.
 * @param[in] Code The exit code.
 */
[[noreturn]] void exceptionExit(const std::exception& e, int32_t code);

FT_END
#endif