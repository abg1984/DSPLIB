#pragma once

#include <vector>
#include <cassert>

namespace DSP
{
	template <typename T>
	class IIRCoefficients
	{
	public:
		void assertCoefficientNormalization();
		std::vector<T> numerator;
		std::vector<T> denominator;
	};

	template <typename T>
	void IIRCoefficients<T>::assertCoefficientNormalization()
	{
		assert(denominator.front() == static_cast<T>(1) && "Denominator coefficients have to be normalized to 1");
	}

	template <typename T>
	bool operator==(const IIRCoefficients<T>& lhs, const IIRCoefficients<T>& rhs)
	{
		return (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
	}
}

