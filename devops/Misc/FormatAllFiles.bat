@echo off

call "%~dp0..\Config.bat"

for /R "%SourceCodePath%" %%f IN (*.cpp, *.h, *.cs) do (
	clang-format -i "%%f"
	echo %%f
)
pause