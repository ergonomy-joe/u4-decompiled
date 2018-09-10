This is experimemtal stuff, and it is not mean to be part of any release.
The point is to build the old 16 bit code from Ultima IV with a 32bit compiler.
You can try to build with Visual Studio 97 (an old one !) with the project file UN_U4.DSW
This one contains two projects: the game, and the title part.
You can also build with Visual Studio 2008: project file UN_U4.SLN
But this one containt only the game part.

I made a small wrapper with a window, some drawing functions, etc...
I had to convert the content of the ".asm" files to C code. It seems to work but I didn't do a serious check.
The drawing functions are very slow.
There is no frame limitation.
There may be bugs related to the conversion of signed chars or 16bit ints to 32 bit variables.
There are a lot of warnings.
...

ergonomy_joe 2018/09/10
