@echo off

call "%~dp0..\Config.bat"

start "" "%ClientExePath%" -WINDOWED -ResX=600 -ResY=600 -WinX=10 - WinY=50 -ExecCmds="open 192.168.100.181"
start "" "%ClientExePath%" -WINDOWED -ResX=600 -ResY=600 -WinX=620 - WinY=50 -ExecCmds="open 192.168.100.181"