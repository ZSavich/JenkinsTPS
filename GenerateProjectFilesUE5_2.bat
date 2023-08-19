@echo off

call "%~dp0devops\Config.bat"

devops\Misc\GenerateProjectFiles.bat "%EnginePath_5.2%" "%UBTRelativePath5%" "%VersionSelector%" "%ProjectName%"