@each off
CD ..\Source
FOR \R %%f IN (*.cpp, *.h, *.cs) DO (
	clang-format -i %%f
	echo %%f
)
CD /d %~dp0
PAUSE