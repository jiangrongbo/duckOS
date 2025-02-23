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

#include "InodeFile.h"
#include "Inode.h"

InodeFile::InodeFile(kstd::shared_ptr<Inode> inode): _inode(inode) {
}

bool InodeFile::is_inode() {
	return true;
}

kstd::shared_ptr<Inode> InodeFile::inode() {
	return _inode;
}

ssize_t InodeFile::read(FileDescriptor &fd, size_t offset, uint8_t *buffer, size_t count) {
	if(_inode->metadata().exists() && _inode->metadata().is_directory()) return -EISDIR;
	return _inode->read(offset, count, buffer, &fd);;
}

ssize_t InodeFile::read_dir_entry(FileDescriptor &fd, size_t offset, DirectoryEntry *buffer) {
	if(_inode->metadata().exists() && !_inode->metadata().is_directory()) return -ENOTDIR;
	return _inode->read_dir_entry(offset, buffer, &fd);
}

ssize_t InodeFile::write(FileDescriptor &fd, size_t offset, const uint8_t* buffer, size_t count) {
	if(_inode->metadata().exists() && _inode->metadata().is_directory()) return -EISDIR;
	return _inode->write(offset, count, buffer, &fd);
}

void InodeFile::open(FileDescriptor& fd, int options) {
	_inode->open(fd, options);
}

void InodeFile::close(FileDescriptor& fd) {
	_inode->close(fd);
}

bool InodeFile::can_read(const FileDescriptor& fd) {
	return _inode->can_read(fd);
}

bool InodeFile::can_write(const FileDescriptor& fd) {
	return _inode->can_write(fd);
}

