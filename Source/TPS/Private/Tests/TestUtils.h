﻿// TPS Game Copyright

#pragma once

namespace TPSGame
{
template <typename Type1, typename Type2> struct TestPayload
{
	Type1 TestValue;
	Type2 ExpectedValue;
	float Tolerance = KINDA_SMALL_NUMBER;
};
}  // namespace TPSGame