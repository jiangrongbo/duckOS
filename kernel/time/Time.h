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

#ifndef DUCKOS_TIME_H
#define DUCKOS_TIME_H

#include <kernel/kstd/kstddef.h>
#include <kernel/kstd/unix_types.h>

class Time {
public:
	Time();
	Time(long sec, long usec);
	explicit Time(timespec spec);
	static Time now();

	timespec to_timespec() const;
	long sec() const;
	long usec() const;

	Time operator+ (const Time& other) const;
	Time operator- (const Time& other) const;
	bool operator> (const Time& other) const;
	bool operator>= (const Time& other) const;
	bool operator< (const Time& other) const;
	bool operator<= (const Time& other) const;
	bool operator== (const Time& other) const;

private:
	int64_t _sec;
	long _usec;
};

#endif //DUCKOS_TIME_H
