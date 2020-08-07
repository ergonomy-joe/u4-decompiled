Lots of information/tools/remakes about "Ultima IV - Quest Of The Avatar" have been made, but so far, no one really gave an insight of the binary itself. To be more precise, of the executables of the PC version of the game (ported by James Van Artsdalen).
There are two of them: AVATAR.EXE and TITLE.EXE

Basically, what I did is reverse engineer them to obtain a list of source files, that, when compiled and linked, produce new executables very close to the original ones (there are maybe 10 bytes difference for each executable).

Some of the source files are in assembly code.
The biggest chunk is in C language, which means that it should be easier to read it.
Of course, since this is a reverse-engineered from binary, files|variables|functions names were lost and I had to come up with new naming. I hope you like it.

Concerning the compiler, I used "Microsoft C Compiler 4.00". Which is certainly the version that was used to build the original game.

Very good remakes of the game exist already; this project is not intended to compete with them at all. Instead, interested people can take a look at the code to understand some algorithms, coding technics from another age, ...

I hope you enjoy browsing the code !
ergonomy_joe

# Steps to compile with "Microsoft C Compiler 4.00"

1. Download dosbox https://www.dosbox.com
1. Launch dosbox
1. Use Ctrl+F12 to speed up to ~15k cycles. It speeds up builds.
1. >MOUNT c "[Local-Directory]/SRC"
	e.g. MOUNT c "E:\projects\u4-decompiled\SRC"
1. Download tools
	1. Go to https://www.pcjs.org/software/pcx86/util/other/unp/4.11/
	1. In the dropdown under the command prompt select "UNP (Executable Unpacker) Source"
	1. Click "Load" and then "Save"
	1. In the dropdown select "MS C 4.00 (Disk 1)"
	1. Rename downloaded file to MSC1.img
	1. In the dropdown select "MS C 4.00 (Disk 2)"
	1. Rename downloaded file to MSC2.img
	1. In the dropdown select "MS C 4.00 (Disk 3)"
	1. Rename downloaded file to MSC3.img
	1. In the dropdown select "MS Macro Assembler 3.00"
	1. Rename downloaded file to MASM300.img
	1. Go to https://winworldpc.com/product/borland-turbo-c/2x
	1. Download "Borland Turbo C 2.0 (3.5)"
	1. Extract disk2.img from download and place with other img files
1. Extract tools
	1. >mkdir C:\tools
	1. >mkdir C:\tools\MSC400
	1. >mkdir C:\tools\MASM300
	1. >mkdir C:\tools\MASM300\LIB
	1. >mkdir C:\tools\MASM300\INCLUDE
	1. >mkdir C:\tools\turboc20
	1. >mkdir C:\ORIGINAL
	1. >MOUNT d "[Local Directory with img files]"
	1. >imgmount a D:\UNP411~1.IMG -t floppy
	1. >copy A:\UNP.EXE C:\TOOLS
	1. >imgmoung -u a
	1. >imgmount a D:\MSC1.IMG -t floppy
	1. >copy A:\*.* C:\tools\MSC400
	1. >imgmoung -u a
	1. >imgmount a D:\MSC2.IMG -t floppy
	1. >copy A:\EXEPACK.EXE C:\tools
	1. >imgmoung -u a
	1. >imgmount a D:\MSC3.IMG -t floppy
	1. >copy A:\*.* C:\tools\MSC400\LIB
	1. >copy A:\LINK.EXE C:\tools\MSC400
	1. >imgmoung -u a
	1. >imgmount a D:\MASM300.IMG -t floppy
	1. >copy A:\LINK.EXE C:\tools\MASM300
	1. >copy A:\LINK.EXE C:\tools
	1. >copy A:\MASM.EXE C:\tools\MASM300
	1. >imgmount -u a
	1. >imgmount a D:\disk2.img -t floppy
	1. >copy A:\MAKE.EXE C:\TOOLS\TURBOC20
1. Build
	1. >DOIT
	