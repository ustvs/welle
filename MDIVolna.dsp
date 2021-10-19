# Microsoft Developer Studio Project File - Name="MDIVolna" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MDIVolna - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MDIVolna.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDIVolna.mak" CFG="MDIVolna - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDIVolna - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MDIVolna - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MDIVolna - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "MDIVolna - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MDIVolna - Win32 Release"
# Name "MDIVolna - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSetupIzlu.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSetupMode.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSetupVolnovod.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MDIVolna.cpp
# End Source File
# Begin Source File

SOURCE=.\MDIVolna.rc
# End Source File
# Begin Source File

SOURCE=.\MDIVolnaDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\MDIVolnaView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Volna.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\DlgSetupIzlu.h
# End Source File
# Begin Source File

SOURCE=.\DlgSetupMode.h
# End Source File
# Begin Source File

SOURCE=.\DlgSetupVolnovod.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MDIVolna.h
# End Source File
# Begin Source File

SOURCE=.\MDIVolnaDoc.h
# End Source File
# Begin Source File

SOURCE=.\MDIVolnaView.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Volna.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\30.bmp
# End Source File
# Begin Source File

SOURCE=.\res\4_plane.bmp
# End Source File
# Begin Source File

SOURCE=.\res\60.bmp
# End Source File
# Begin Source File

SOURCE=.\res\90.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap19.bmp
# End Source File
# Begin Source File

SOURCE=.\res\F.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Fc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ferrari.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Fs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\h.bmp
# End Source File
# Begin Source File

SOURCE=.\res\h1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\h2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\lambda.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MDIVolna.ico
# End Source File
# Begin Source File

SOURCE=.\res\MDIVolna.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MDIVolnaDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\moda.bmp
# End Source File
# Begin Source File

SOURCE=.\res\n1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\n2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\n3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\n4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\nc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\nf.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ns.bmp
# End Source File
# Begin Source File

SOURCE=.\res\O.bmp
# End Source File
# Begin Source File

SOURCE=.\res\PI.bmp
# End Source File
# Begin Source File

SOURCE=.\res\PI_2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\s1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\teta.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zigzag1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zigzag2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\zigzag3.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
