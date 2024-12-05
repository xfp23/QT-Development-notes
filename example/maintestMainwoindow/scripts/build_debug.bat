@echo off
title qmake and nmake build prompt
set MINGW_PATH=C:\Qt\Tools\mingw1310_64
set QT_DIR=C:\Qt\6.8.0\mingw_64
set BUILD_DIR=%cd%\build
set PRO_DIR=%cd%
set PATH=%MINGW_PATH%\bin;%QT_DIR%\bin;%PATH%


if not exist %BUILD_DIR% (
    md %BUILD_DIR%
)

cd build
qmake.exe %PRO_DIR%\testvs.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=console"
if exist %BUILD_DIR%\debug\testvs.exe del %BUILD_DIR%\debug\testvs.exe
@REM C:\Qt\Tools\QtCreator\bin\jom.exe -j4
%MINGW_PATH%\bin\mingw32-make -f Makefile.Debug
cd debug
if not exist %BUILD_DIR%\debug\Qt5Core.dll (
    windeployqt testvs.exe
)