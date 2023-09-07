// TPS Game Copyright

#include "TestUtils.h"
#include "Tests/ScienceFunctionLibrary.h"
#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

using namespace TPSGame;

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFibonacciSimple, "TPSGame.Science.Fibonacci.Simple",
								 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
									 EAutomationTestFlags::HighPriority)

bool FFibonacciSimple::RunTest(const FString& Parameters)
{
	AddInfo("Fibonacci Simple Test");

	typedef TArray<TestPayload<int32, int32>> TestPayload;

	// clang-format off
	TestPayload TestData {
		{0,0},
		{1,1},
		{2,1},
		{3,2},
		{5,5}
		};
	// clang-format on

	for (const auto Payload : TestData)
	{
		FString InfoString = FString::Printf(TEXT("Test Value - %i :: Expected Result - %i"), Payload.TestValue, Payload.ExpectedValue);
		TestEqual(InfoString, UScienceFunctionLibrary::Fibonacci(Payload.TestValue), Payload.ExpectedValue);
	}
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFibonacciStress, "TPSGame.Science.Fibonacci.Stress",
								 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::StressFilter |
									 EAutomationTestFlags::LowPriority)

bool FFibonacciStress::RunTest(const FString& Parameters)
{
	AddInfo("Fibonacci Stress Test");

	int32 PrevPrevValue = 0;
	int32 PrevValue = 1;

	for (int32 i = 2; i < 40; ++i)
	{
		const int32 CurrentValue = UScienceFunctionLibrary::Fibonacci(i);
		TestTrueExpr(CurrentValue == PrevPrevValue + PrevValue);
		PrevPrevValue = PrevValue;
		PrevValue = CurrentValue;
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFibonacciLogHasErrors, "TPSGame.Science.Fibonacci.LogErrors",
								 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
									 EAutomationTestFlags::HighPriority)

bool FFibonacciLogHasErrors::RunTest(const FString& Parameters)
{
	typedef TArray<TestPayload<TInterval<int32>, int32>> TestPayload;
	// clang-format off
	TestPayload TestData {
			{{13,25}, 25},
			{{25,25},25},
			{{0,123},123},
			{{0,0},0},
			{{-2345,0},0},
			{{-45,-67},-45},
			{{-9,-9},-9},
			{{-78,34},34}
	};
	// clang-format on

	for (auto Payload : TestData)
	{
		TestTrueExpr(FMath::Max(Payload.TestValue.Min, Payload.TestValue.Max) == Payload.ExpectedValue);
	}

	return true;
}

#endif