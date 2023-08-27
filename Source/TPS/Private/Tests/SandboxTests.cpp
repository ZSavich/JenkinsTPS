// TPS Game Copyright

#include "Tests/SandboxTests.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"

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
	TestEqual("Sqrt(4)", FMath::Sqrt(4.f), 2.f);
	TestEqual("Sqrt(3) with Tolerance 0.1f", FMath::Sqrt(3.f), 1.7f, 0.1f);
	TestEqual("Sqrt(3) with Tolerance 0.01f", FMath::Sqrt(3.f), 1.73f, 0.01f);
	TestEqual("Sqrt(3) with Tolerance 1.e-5f", FMath::Sqrt(3.f), 1.73205f, 1.e-5f);
	return true;
}
