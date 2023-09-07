// TPS Game Copyright

#include "TestUtils.h"
#if (WITH_DEV_AUTOMATION_TESTS || WITH_PERF_AUTOMATION_TESTS)

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/SandboxTests.h"

using namespace TPSGame;

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathMaxInt, "TPSGame.Math.MaxInt",
								 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
									 EAutomationTestFlags::HighPriority)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMathSqrt, "TPSGame.Math.Sqrt",
								 EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter |
									 EAutomationTestFlags::HighPriority)

bool FMathMaxInt::RunTest(const FString& Parameters)
{
	AddInfo("Max [int] Function Testing");

	if constexpr (FMath::Max(13, 25) != 25)
	{
		AddWarning("Incorrect Max Number");
		return false;
	}

	TestTrue("2 Different Positive Numbers", FMath::Max(13, 25) == 25);
	TestTrueExpr(FMath::Max(0, 123) == 123);
	TestTrue("2 Zeroes", FMath::Max(0, 0) == 0);
	TestTrue("2 Different Negative Numbers", FMath::Max(-45, -67) == -45);
	TestTrue("2 Equal Negative Numbers", FMath::Max(-9, -9) == -9);
	return true;
}

bool FMathSqrt::RunTest(const FString& Parameters)
{
	AddInfo("Sqrt Function Testing");
	typedef TArray<TestPayload<float, float>> SqrtTestPayload;
	SqrtTestPayload TestData{{4.f, 2.f}, {3.f, 1.7f, 0.1f}, {3.f, 1.73f, 0.01f}, {3.f, 1.73205f, 1.e-5f}};

	for (const auto Payload : TestData)
	{
		const bool IsEqual = FMath::IsNearlyEqual(FMath::Sqrt(Payload.TestValue), Payload.ExpectedValue, Payload.Tolerance);
		TestTrueExpr(IsEqual);
	}
	return true;
}

#endif