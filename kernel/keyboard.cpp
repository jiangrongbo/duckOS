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

    Copyright (c) Byteduck 2016-2020. All rights reserved.
*/

#include <kernel/kstd/kstddef.h>
#include <kernel/kstd/kstdio.h>
#include <kernel/keyboard.h>

char kbd_us_map[256] = {
	0,
	'\033',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'0',
	'-',
	'=',
	0x08,
	'\t',
	'q',
	'w',
	'e',
	'r',
	't',
	'y',
	'u',
	'i',
	'o',
	'p',
	'[',
	']',
	'\n',
	0,
	'a',
	's',
	'd',
	'f',
	'g',
	'h',
	'j',
	'k',
	'l',
	';',
	'\'',
	'`',
	0,
	'\\',
	'z',
	'x',
	'c',
	'v',
	'b',
	'n',
	'm',
	',',
	'.',
	'/',
	0,
	'*',
	0,
	' ',
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	'-',
	0,
	0,
	0,
	'+',
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	'\\',
	0,
	0,
	0,
};

char kbd_us_shift_map[256] = {
	0,
	'\033',
	'!',
	'@',
	'#',
	'$',
	'%',
	'^',
	'&',
	'*',
	'(',
	')',
	'_',
	'+',
	0x08,
	'\t',
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'{',
	'}',
	'\n',
	0,
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	':',
	'\"',
	'~',
	0,
	'|',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',
	'<',
	'>',
	'?',
	0,
	'*',
	0,
	' ',
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	'-',
	0,
	0,
	0,
	'+',
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	'|',
	0,
	0,
	0,
};