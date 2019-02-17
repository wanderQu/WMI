# Microsoft Developer Studio Project File - Name="WMI" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WMI - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WMI.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WMI.mak" CFG="WMI - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WMI - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "WMI - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WMI - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /ZI /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /incremental:yes /debug /machine:I386

!ELSEIF  "$(CFG)" == "WMI - Win32 Debug"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fr /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "WMI - Win32 Release"
# Name "WMI - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddDistri.cpp
# End Source File
# Begin Source File

SOURCE=.\AddDistriReturn.cpp
# End Source File
# Begin Source File

SOURCE=.\AddGood.cpp
# End Source File
# Begin Source File

SOURCE=.\AddOrder.cpp
# End Source File
# Begin Source File

SOURCE=.\AddOtherIn.cpp
# End Source File
# Begin Source File

SOURCE=.\AddOtherOut.cpp
# End Source File
# Begin Source File

SOURCE=.\AddPay.cpp
# End Source File
# Begin Source File

SOURCE=.\AddProReturn.cpp
# End Source File
# Begin Source File

SOURCE=.\AddRecv.cpp
# End Source File
# Begin Source File

SOURCE=.\AddWareAdj.cpp
# End Source File
# Begin Source File

SOURCE=.\CLock.cpp
# End Source File
# Begin Source File

SOURCE=.\CLock.h
# End Source File
# Begin Source File

SOURCE=.\Data.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogAdd.cpp
# End Source File
# Begin Source File

SOURCE=.\Distribute.cpp
# End Source File
# Begin Source File

SOURCE=.\EditEx.cpp
# End Source File
# Begin Source File

SOURCE=.\excel.cpp
# End Source File
# Begin Source File

SOURCE=.\ExternParent.cpp
# End Source File
# Begin Source File

SOURCE=.\hangePass.cpp
# End Source File
# Begin Source File

SOURCE=.\harac.cpp
# End Source File
# Begin Source File

SOURCE=.\Log.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Manage.cpp
# End Source File
# Begin Source File

SOURCE=.\MyRes.cpp
# End Source File
# Begin Source File

SOURCE=.\Procurment.cpp
# End Source File
# Begin Source File

SOURCE=.\Set.cpp
# End Source File
# Begin Source File

SOURCE=.\SetSysParam.cpp
# End Source File
# Begin Source File

SOURCE=.\ShareMemory.cpp
# End Source File
# Begin Source File

SOURCE=.\ShareMemory.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Title.cpp
# End Source File
# Begin Source File

SOURCE=.\WareHouse.cpp
# End Source File
# Begin Source File

SOURCE=.\WareIn.cpp
# End Source File
# Begin Source File

SOURCE=.\WareOut.cpp
# End Source File
# Begin Source File

SOURCE=.\WMI.cpp
# End Source File
# Begin Source File

SOURCE=.\WMI.rc
# End Source File
# Begin Source File

SOURCE=.\WMIDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\WMIView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddDistri.h
# End Source File
# Begin Source File

SOURCE=.\AddDistriReturn.h
# End Source File
# Begin Source File

SOURCE=.\AddGood.h
# End Source File
# Begin Source File

SOURCE=.\AddOrder.h
# End Source File
# Begin Source File

SOURCE=.\AddOtherIn.h
# End Source File
# Begin Source File

SOURCE=.\AddOtherOut.h
# End Source File
# Begin Source File

SOURCE=.\AddPay.h
# End Source File
# Begin Source File

SOURCE=.\AddProReturn.h
# End Source File
# Begin Source File

SOURCE=.\AddRecv.h
# End Source File
# Begin Source File

SOURCE=.\AddWareAdj.h
# End Source File
# Begin Source File

SOURCE=.\Data.h
# End Source File
# Begin Source File

SOURCE=.\DialogAdd.h
# End Source File
# Begin Source File

SOURCE=.\Distribute.h
# End Source File
# Begin Source File

SOURCE=.\EditEx.h
# End Source File
# Begin Source File

SOURCE=.\excel.h
# End Source File
# Begin Source File

SOURCE=.\ExternParent.h
# End Source File
# Begin Source File

SOURCE=.\hangePass.h
# End Source File
# Begin Source File

SOURCE=.\harac.h
# End Source File
# Begin Source File

SOURCE=.\Log.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Manage.h
# End Source File
# Begin Source File

SOURCE=.\MyRes.h
# End Source File
# Begin Source File

SOURCE=.\Procurment.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Set.h
# End Source File
# Begin Source File

SOURCE=.\SetSysParam.h
# End Source File
# Begin Source File

SOURCE=.\include\sqlite3.h
# End Source File
# Begin Source File

SOURCE=.\include\sqlite_dll.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TabDlg.h
# End Source File
# Begin Source File

SOURCE=.\Title.h
# End Source File
# Begin Source File

SOURCE=.\WareHouse.h
# End Source File
# Begin Source File

SOURCE=.\WareIn.h
# End Source File
# Begin Source File

SOURCE=.\WareOut.h
# End Source File
# Begin Source File

SOURCE=.\WMI.h
# End Source File
# Begin Source File

SOURCE=.\WMIDoc.h
# End Source File
# Begin Source File

SOURCE=.\WMIView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\add.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\del.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Log.bmp
# End Source File
# Begin Source File

SOURCE=.\res\logo.bmp
# End Source File
# Begin Source File

SOURCE=".\res\源文件\Logo.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Logo_160_90.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Logo_800_450.bmp
# End Source File
# Begin Source File

SOURCE=.\res\WMI.ico
# End Source File
# Begin Source File

SOURCE=.\res\WMI.rc2
# End Source File
# Begin Source File

SOURCE=.\res\WMIDoc.ico
# End Source File
# Begin Source File

SOURCE=".\res\图片1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\退出.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\无标题.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\XPStyle.manifest
# End Source File
# End Target
# End Project
