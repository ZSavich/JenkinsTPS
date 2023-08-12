@echo off

set EnginePath=C:\UnrealEngine5.2
set UBTRelativePath=Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe
set VersionSelector=%EnginePath%\Engine\Binaries\Win64\UnrealVersionSelector.exe
set ProjectName=TPS.uproject

devops/GenerateProjectFiles.bat "%EnginePath%" "%UBTRelativePath%" "%VersionSelector%" "%ProjectName%"