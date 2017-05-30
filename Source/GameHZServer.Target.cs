using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class GameHZServerTarget : TargetRules
{

    public GameHZServerTarget(TargetInfo Target)

    {

        Type = TargetType.Server;

        bUsesSteam = true;

    }

    //
    // TargetRules interface.
    //
    public override void SetupBinaries
    (
     TargetInfo Target,
     ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
     ref List<string> OutExtraModuleNames
     )
    {
        OutExtraModuleNames.Add("GameHZ");
    }
}