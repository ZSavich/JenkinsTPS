// TPS Game Copyright

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScienceFunctionLibrary.generated.h"

UCLASS()
class TPS_API UScienceFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

  public:
	UFUNCTION(BlueprintPure, Category = "ScienceLibrary")
	static int32 Fibonacci(int32 Value);
};
