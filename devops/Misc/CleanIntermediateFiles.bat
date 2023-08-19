@echo off

call "%~dp0\..\Config.bat"

pushd "%ProjectRoot%" || exit /b

for %%f in (%DirsToRemove%) do (
	if exist "%%f" (
		echo Removing directory "%%f" ...
		rmdir /s /q %%f || echo Could not delete file "%%f"
	)
)

for %%f in (%FilesToRemove%) do (
	if exist "%%f" (
		del /q %%f || echo Could not delete file "%%f"
	)
)
popd