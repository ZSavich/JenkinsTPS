@echo off

del /q "%TargetFilePath%"

for /f "usebackq tokens=*" %%a in ("%TargetTemplateFilePath%") do (
	call echo %%a>>"%TargetFilePath%"
)

call "%~dp0..\Misc\FormatAllFiles.bat"