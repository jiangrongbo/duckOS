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

#ifndef DUCKOS_PAGETABLE_H
#define DUCKOS_PAGETABLE_H

#include <kernel/kstd/types.h>

class PageDirectory;
class PageTable {
public:
	typedef union Entry {
		struct __attribute((packed)) Data {
		public:
			bool present : 1;
			bool read_write : 1;
			bool user : 1;
			bool write_through : 1;
			bool cache_disabled : 1;
			bool acessed: 1;
			bool dirty : 1;
			bool zero : 1;
			bool global : 1;
			uint8_t unused : 3;
			uint32_t page_addr : 20;

			void set_address(size_t address);
			size_t get_address();
		} data;
		uint32_t value;
	} Entry;

	PageTable(size_t vaddr, PageDirectory* page_directory, bool alloc_table = true);
	PageTable();
	~PageTable();

	/**
	 * Returns the vaddr of the beginning of the block of memory corresponding to this page table.
	 * @return The table's virtual address.
	 */
	size_t vaddr();

	Entry*& entries();
	Entry& operator[](int index);

private:
	Entry* _entries = nullptr;
	size_t _vaddr = 0;
	PageDirectory* _page_directory = nullptr;
	bool _alloced_table = false;
};

#endif //DUCKOS_PAGETABLE_H
