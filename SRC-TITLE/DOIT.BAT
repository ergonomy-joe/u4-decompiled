@echo off
set OLDPATH=%PATH%

set MSC4=\TOOLS\MSC400
set PATH=%MSC4%
set INCLUDE=%MSC4%\INCLUDE
set LIB=%MSC4%\LIB
set CFLAGS=/Ox /Zp /Gc
set AS=\TOOLS\MASM300

echo START > log.txt

MSC %CFLAGS% title_x; >> log.txt
MSC %CFLAGS% file; >> log.txt
MSC %CFLAGS% title_0; >> log.txt
%AS% /Mx GRAPH; >> log.txt
%AS% /Mx BEEP; >> log.txt
%AS% /Mx INFLATE; >> log.txt
%AS% /Mx LOW; >> log.txt
MSC %CFLAGS% title_1; >> log.txt
%AS% /Mx UTIL2; >> log.txt
%AS% /Mx VAR; >> log.txt

REM MSC %CFLAGS% data; >> log.txt
REM MSC %CFLAGS% errmsg; >> log.txt
%AS% /Mx DATA; >> log.txt
%AS% /Mx ERRMSG; >> log.txt

LINK /MAP title_x file title_0 graph beep inflate low title_1 util2 VAR  %LIB%\binmode data errmsg,title_0; >> log.txt

\tools\exepack title_0.exe tmp.exe
\tools\unp tmp.exe
copy tmp.exe title_0.exe
del tmp.exe
copy title_0.exe ..\original\

set PATH=%OLDPATH%
set OLDPATH=

fc /b TITLE_0.EXE ..\ORIGINAL\TITLE.EXE > diff.txt
