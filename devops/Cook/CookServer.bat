@echo off

call "%~dp0..\Config.bat"

"%RunUATPath%" BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-serverconfig="%Configuration%" ^
-build -skippackage -cook -server -noclient