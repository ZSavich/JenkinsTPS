// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;

public class TPS : ModuleRules
{
	public TPS(ReadOnlyTargetRules Target) : base(Target)
	{
		Console.WriteLine("TPS Module Rules --------------->");
		Console.WriteLine("Unreal Version {0}.{1}.{2} --------------->", Target.Version.MajorVersion, Target.Version.MinorVersion, Target.Version.MinorVersion);
		Console.WriteLine("Target Platform {0} --------------->", Target.Platform);
		Console.WriteLine("Target Type {0} --------------->", Target.Type);
		Console.WriteLine("Branch Name {0} --------------->", Target.Version.BranchName);
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		if (Target.Type == TargetType.Editor)
		{
			PublicDependencyModuleNames.Add("HeadMountedDisplay");
			PublicDefinitions.Add("MY_VR_MACRO=1");
		}
		else
		{
			PublicDefinitions.Add("MY_VR_MACRO=0");
		}
	}
}
