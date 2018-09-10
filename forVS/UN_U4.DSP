# Microsoft Developer Studio Project File - Name="UN_U4" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=UN_U4 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "UN_U4.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UN_U4.MAK" CFG="UN_U4 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UN_U4 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "UN_U4 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "UN_U4 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "UN_U4 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /Gz /W3 /GX /Zi /Od /I "..\SRC" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /profile

!ENDIF 

# Begin Target

# Name "UN_U4 - Win32 Release"
# Name "UN_U4 - Win32 Debug"
# Begin Group "U4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\SRC\U4_3D.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_AI.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_ANIM.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_COMBA.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_COMBB.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_COMBC.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_CSTES.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_DNG.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_END.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_EVT.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_EXPLO.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_FILE.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_GET.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_HOLE.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_INIT.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_LB.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_LOCAT.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_MAIN.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_MAIN2.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_MAP.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_MIX.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_NPC.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_PEER.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_Q_N_V.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SHOPS.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SHRIN.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SPELL.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SRCH.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SRCH2.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_TALK.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_USE.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_UTIL.C
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_Z.C
# End Source File
# End Group
# Begin Group "U4_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\SRC\U4.H
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_DOS.H
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_FILE.H
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_GRAPH.H
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SCAN.H
# End Source File
# Begin Source File

SOURCE=..\SRC\U4_SHAPE.H
# End Source File
# End Group
# Begin Source File

SOURCE=.\common.c
# End Source File
# Begin Source File

SOURCE=.\common.h
# End Source File
# Begin Source File

SOURCE=.\u4_forWin.c
# End Source File
# Begin Source File

SOURCE=.\U4_VAR.C
# End Source File
# End Target
# End Project
