// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.Collections.Generic;

public class TPSTarget : TargetRules
{
	public TPSTarget(TargetInfo Target) : base(Target)
	{
		Console.WriteLine("TPS Game Target ------------------->");
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("TPS");
	}
}