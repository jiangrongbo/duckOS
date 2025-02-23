/*
    This file is part of duckOS.

    duckOS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    duckOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with duckOS.  If not, see <https://www.gnu.org/licenses/>.

    Copyright (c) Byteduck 2016-2021. All rights reserved.
*/

#ifndef DUCKOS_LIBDUCK_CONFIGFILE_H
#define DUCKOS_LIBDUCK_CONFIGFILE_H

#include <string>
#include <map>
#include <fstream>
#include "Result.hpp"

namespace Duck {
	class Config {
	public:
		std::map<std::string, std::string>& operator[](const std::string& name);
		std::map<std::string, std::string>& section(const std::string& name);
		std::map<std::string, std::string>& defaults();
		bool has_section(const std::string& name);

		static ResultRet<Config> read_from(const std::string& filename);
		static ResultRet<Config> read_from(std::istream& stream);

	private:
		Config() = default;

		static Result read_from(std::istream& stream, Config& config);

		std::map<std::string, std::map<std::string, std::string>> _values;
	};
}

#endif //DUCKOS_LIBDUCK_CONFIGFILE_H
