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
