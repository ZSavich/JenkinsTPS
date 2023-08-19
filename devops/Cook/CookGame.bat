@echo off

call "%~dp0..\Config.bat"

"%RunUATPath%" BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-clientconfig="%Configuration%" ^
-build -skippackage -cook ^
