@echo off

rem Engine Params
set EnginePath_5.2=C:\JenkinsJobs\UnrealEngine5.2
set EnginePath_5.2_InstalledBuild=C:\JenkinsJobs\UESource\UE_5.2_InstalledBuild

set UBTRelativePath5=Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe
set VersionSelector=C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe

rem !! Engine Version For Packaging !!
set RunUATPath=%EnginePath_5.2%\Engine\Build\BatchFiles\RunUAT.bat

rem Project Params
set ProjectRoot=D:\Projects\TPS
set ProjectPureName=TPS
set ProjectName=%ProjectPureName%.uproject
set ProjectPath="%ProjectRoot%\%ProjectName%"

rem Build Params
set Platform=Win64
set Configuration=Development
set ArchivePath=%ProjectRoot%\Build
set StagePath=%ProjectRoot%\Stage

rem Other Params
set SourceCodePath=%ProjectRoot%\Source
set DirsToRemove=Intermediate DerivedDataCache Saved Binaries Build .vs .idea
set FilesToRemove=*.sln

rem Target Params
set COPYRIGHT_LINE=// Copyright Epic Games, LaLala
set EXTRA_MODULE_NAMES="%ProjectPureName%"
set TargetTemplateFilePath=%ProjectRoot%\devops\Targets\GameModule.Target.cs.template

rem Run
set ServerExePath=%ProjectRoot%\Build\WindowsServer\%ProjectPureName%Server.exe
set ClientExePath=%ProjectRoot%\Build\WindowsClient\%ProjectPureName%Client.exe
set GameExePath=%ProjectRoot%\Build\Windows\%ProjectPureName%.exe