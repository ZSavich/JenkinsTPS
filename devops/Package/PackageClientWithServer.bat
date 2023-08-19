@echo off

call "%~dp0\..\Config.bat"

"%RunUATPath%" BuildCookRun ^
-project="%ProjectPath%" ^
-platform="%Platform%" ^
-clientconfig="%Configuration%" ^
-serverconfig="%Configuration%" ^
-build -package -cook -pak -allmaps -stage ^
-archive -archivedirectory="%ArchivePath%" ^
-client -server