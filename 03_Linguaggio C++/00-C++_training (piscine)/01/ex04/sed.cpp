/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:47:04 by arrigo            #+#    #+#             */
/*   Updated: 2021/08/24 15:17:40 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

Sed::Sed()
{}

Sed::~Sed()
{}

void Sed::replace(std::string const filename, std::string const search, std::string const replace)
{
	if (filename.empty() || search.empty() || replace.empty())
		throw "Empty argument";
	std::ifstream ifs;
	ifs.open (filename.c_str(), std::ios_base::in);
	if (!ifs.is_open())
		throw "Error: input file";
	std::ofstream ofs;
	ofs.exceptions ( std::ifstream::failbit | std::ifstream::badbit);
	std::string outfile = filename + ".replace";
	ofs.open(outfile.c_str(), std::ios_base::out | std::ios_base::trunc);
	std::string line;
	size_t pos;
	while (std::getline(ifs, line))
	{
		pos = 0;
		while ((pos = line.find(search, pos)) < line.size())
		{
			std::string new_line;
			new_line.assign(line);
			new_line.resize(pos);
			new_line.append(replace);
			new_line.append(line.substr(pos + search.size(),line.size()));
			line.assign(new_line);
			pos += replace.size();
		}
		ofs << line << std::endl;
	}
}
