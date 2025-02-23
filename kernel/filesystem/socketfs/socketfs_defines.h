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

#ifndef DUCKOS_SOCKETFS_DEFINES_H
#define DUCKOS_SOCKETFS_DEFINES_H

#define SOCKETFS_MAX_BUFFER_SIZE 16384
#define SOCKETFS_TYPE_MSG 0
#define SOCKETFS_RECIPIENT_HOST 0
#define SOCKETFS_TYPE_BROADCAST -1
#define SOCKETFS_TYPE_MSG_CONNECT -2
#define SOCKETFS_TYPE_MSG_DISCONNECT -3

typedef unsigned int sockid_t;

#endif //DUCKOS_SOCKETFS_DEFINES_H
