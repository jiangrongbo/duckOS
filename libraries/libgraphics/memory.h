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

#ifndef DUCKOS_LIBGRAPHICS_MEMORY_H
#define DUCKOS_LIBGRAPHICS_MEMORY_H

inline void* memcpy_uint32(uint32_t* d, uint32_t* s, size_t n) {
	void* od = d;
	asm volatile("rep movsl\n" : "+S"(s), "+D"(d), "+c"(n)::"memory");
	return od;
}

#endif //DUCKOS_LIBGRAPHICS_MEMORY_H
