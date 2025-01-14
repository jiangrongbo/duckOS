# duckOS
### A hobby operating system

A hobby UNIX-like OS with a graphical window manager for x86 computers.

![Toolchain](https://github.com/byteduck/duckOS/workflows/Toolchain/badge.svg)
![Kernel](https://github.com/byteduck/duckOS/workflows/Kernel/badge.svg)
![duckOS](https://github.com/byteduck/duckOS/workflows/duckOS/badge.svg)

![Screenshot](docs/screenshot-2021-09-11.png)

### What's working
- Booting off of the primary master IDE (PATA) hard drive on both emulators and real hardware (tested on a Dell Optiplex 320 with a Pentium D)
- PATA DMA or PIO access (force PIO by using the `use_pio` grub kernel argument)
- A virtual filesystem with device files (`/dev/hda`, `/dev/zero`, `/dev/random`, `/dev/fb`, `/dev/tty`, etc)
  - The root filesystem is ext2, and is writeable
- Filesystem caching (the cache size can be changed by changing `MAX_FILESYSTEM_CACHE_SIZE` in `FileBasedFilesystem.h`)
- Dynamic linking with shared libraries
- A Bochs/Qemu/VirtualBox/Multiboot video driver (640x480x32bpp)
- A window manager / compositor called pond
- Various GUI applications
- More!
 
### Services

The code for these can be found in [services](services/).

- init (/bin/init): The init system for duckOS.
- pond (/bin/pond): The (very-WIP) window manager / compositor for duckOS.

### GUI Programs

The code for these can be found in [programs](/programs)

- Terminal (/apps/terminal.app): A libui-based terminal application.
- System Monitor (/apps/monitor.app): A basic system monitor showing memory and CPU utilization.
- 4 In a Row (/apps/4inarow.app): A basic four-in-a-row game. Play with two players or against the computer.
- Sandbar (/bin/sandbar): A basic "taskbar" that displays a row of buttons at the bottom of the screen to launch applications.
 
### CLI Programs

The code for these can be found in [programs](programs/).

- ls (/bin/ls): Lists the entries in the current or given directory.
- cat (/bin/cat): Writes the contents of a file to stdout.
- cp (/bin/cp): Copies a file.
- mv (/bin/mv): Moves a file.
- pwd (/bin/pwd): Prints the current working directory.
- mkdir (/bin/mkdir): Creates a new directory.
- echo (/bin/echo): Prints the arguments given to it separated by spaces to stdout.
- rm (/bin/rm): Removes a file.
- ln (/bin/ln): Creates a hard or symbolic link to a file or directory.
- rmdir (/bin/rmdir): Removes a directory.
- touch (/bin/touch): Updates the access/modification times of a file or creates it if it doesn't exist.
- truncate (/bin/truncate): Resizes a file.
- chmod (/bin/chmod): Changes the mode of a file.
- chown (/bin/chown): Changes the owner of a file.
- free (/bin/free): Shows the amount of total, used, and free memory (use the -h flag for human-readable numbers).
- ps (/bin/ps): Shows the currently running processes.
- dsh (/bin/dsh): A basic userspace shell with support for pipes (`|`) and redirections (`>`/`>>`).
  - There is only support for one redirection at a time right now.
- apprun (/bin/apprun)

Programs that take arguments will provide you with the correct usage when you run them without arguments.


### Libraries

- [libc](libraries/libc): The standard C library.
- [libm](libraries/libm): The math portion of the standard C library.
- [libpond](libraries/libpond): The library used for interfacing with the pond window manager / compositor.
- [libgraphics](libraries/libgraphics): A library which provides a few utilities for working with graphics such as image format loading.
- [libui](/libraries/libui): A UI framework for applications.
- [libterm](/libraries/libterm): A framework for handling terminals.
- [libduck](/libraries/libduck): A library containing commonly used classes and utilities, such as argument and configuration file parsing.
- [libriver](/libraries/libriver): An IPC library not dissimilar to D-Bus, which provides a framework for remote function calls and data passing.
- [libapp](/libraries/libapp): A library providing methods to retrieve information about installed and running applications.
- [libsys](/libraries/libsys): Provides higher-level C++ abstractions for retrieving system information, namely from procFS.

### Ports

Ports will only compile if their corresponding submodule is downloaded with `git submodule init` and `git submodule update`.

- [DOOM](ports/doom): A little buggy at the moment, but playable. With the current multitasking and window manager implementation, it can be a little slow.

### Known Issues / Limitations
- Framebuffer scrolling is slow on real hardware. I'm not focusing on fixing this right now until I start working on a window manager.
- Must be booted off of the master drive on the primary PATA controller as of now.
- PATA DMA doesn't seem to work on real hardware at the moment, so the `use_pio` grub commandline option should be specified if you're crazy enough to test this on real hardware ;)
- Ext2 triply indirect block pointers cannot be read/written, so there may be issues writing and reading large files
- A buffer overflow attack on the kernel may be possible, because only pointers passed to syscalls are checked for validity (and not the length of the data to be read/written)
- Dynamic linking does not currently use CoW to share memory between processes, so each process has its own copy of the library in memory
- It's pretty unstable

### Future Goals
- Cut down on memory usage by sharing memory for various commonly used items (libraries, icons, configuration, etc)
- Better support for real hardware
- Network support
- Sound support
- More s t a b i l i t y and s p e e d
- Multiprocessor (multicore) support
- An in-house heap implementation
- More POSIX compatibility
- Better looking UI with animations and effects such as shadows and blur/transparency
- Slowly transition various functions from the kernel to userspace (ie microkernel)
- A better filesystem cache implementation that can free memory when needed and periodically flushes writes

### Building / Running
- See [INSTRUCTIONS.md](INSTRUCTIONS.md) for instructions.

### Credits
- [blanham's mirror of liballoc 1.1](https://github.com/blanham/liballoc) for the kernel heap allocation implementation (it's open domain, so if you want to use it, I highly recommend it)
- [SRombaut's implementation of shared_ptr](https://github.com/SRombauts/shared_ptr/)
- [SerenityOS](http://serenityos.org) for a lot of inspiration
- [Gohufont](https://font.gohu.org/) for the font (licensed under [WTFPL](http://www.wtfpl.net/about/))

### License
- See [LICENSE.TXT](LICENSE.txt).
