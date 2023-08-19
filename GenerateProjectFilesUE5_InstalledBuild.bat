@echo off

call "%~dp0\..\Config.bat"

devops\Misc\GenerateProjectFiles.bat "%EnginePath_5.2_InstalledBuild%" "%UBTRelativePath5%" "%VersionSelector%" "%ProjectName%"