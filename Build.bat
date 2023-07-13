"C:\Program Files\Epic Games\UE_5.2\Engine\Build\BatchFiles\RunUAT.bat" ^
BuildCookRun ^
-project=C:\JenkinsJobs\TPS\TPS.uproject ^
-platform=Win64 ^
-clientconfig=Development ^
-build ^
-cook ^
-pak ^
-allmaps ^
-stage -stagingdirectory=C:\JenkinsJobs\TPS\Stage ^
-archive -archivedirectory=C:\JenkinsJobs\TPS\BuildFromBat ^
