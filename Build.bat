@echo off

call "%~dp0\..\Config.bat"

"C:\Program Files\Epic Games\UE_5.2\Engine\Build\BatchFiles\RunUAT.bat" ^
BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-clientconfig="%Configuration%" ^
-build -cook -pak -allmaps ^
-stage -stagingdirectory="%StagePath%" ^
-archive -archivedirectory="%ArchivePath%" ^
