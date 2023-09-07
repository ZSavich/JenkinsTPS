// TPS Game Copyright

#include "Tests/ScienceFunctionLibrary.h"

DEFINE_LOG_CATEGORY_STATIC(LogScienceFunctionLibrary, All, All);

int32 UScienceFunctionLibrary::Fibonacci(int32 Value)
{
	if (Value < 0)
	{
		UE_LOG(LogScienceFunctionLibrary, Error, TEXT("Invalid input for Fibonacci: %i"), Value);
	}

	return Value <= 1 ? Value : Fibonacci(Value - 1) + Fibonacci(Value - 2);
}
