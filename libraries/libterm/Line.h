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

#ifndef DUCKOS_LINE_H
#define DUCKOS_LINE_H

#include "types.h"

namespace Term {
	class Line {
	public:
		explicit Line(int size);
		Line();

		Character& at(int index);
		Character& operator[](int index);
		int length();
		void resize(int new_size);
		void fill(Character fill_char);
		void clear(Attribute attr);

	private:
		Vector<Character> chars;
	};
}


#endif //DUCKOS_LINE_H
