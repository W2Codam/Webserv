/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DirectoryFactory.hpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/12 16:02:40 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/07/27 11:01:00 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DIRECTORY_FACTORY_HPP
# define DIRECTORY_FACTORY_HPP
# include "Exceptions.hpp"
# include <dirent.h>

namespace ft {
namespace DirectoryFactory
{
	/**
	 * @brief Constructs the html directory navigation based on the current path.
	 * 
	 * @param path The path to base the directory navigator of.
	 * @param outContent The resulting html content.
	 */
	void buildContentFromDir(const std::string& path, std::string& outContent);
}
}
#endif