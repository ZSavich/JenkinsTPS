@echo off

call "%~dp0\..\Config.bat"

"%RunUATPath%" BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-serverconfig="%Configuration%" ^
-build -package -cook -pak -allmaps -stage ^
-archive -archivedirectory="%ArchivePath%" ^
-server -noclient