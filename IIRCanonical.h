#pragma once

#include <vector>
#include <algorithm>

#include "IIRCoefficients.h"
#include "DSPUtility.h"

namespace DSP
{
	template <typename T>
	class IIRCanonical
	{
	public:
		IIRCanonical(const IIRCoefficients<T>& iirCoefficients);
		T processSample(T inputSample);

	private:
		void resizeDelayBuffer();
		IIRCoefficients<T> itsCoefficients;
		std::vector<T> itsDelayBuffer;
	};

	template <typename T>
	IIRCanonical<T>::IIRCanonical(const IIRCoefficients<T>& iirCoefficients) : itsCoefficients{ iirCoefficients }
	{
		resizeDelayBuffer();
	}

	template <typename T>
	T IIRCanonical<T>::processSample(T inputSample)
	{
		itsDelayBuffer[0] = static_cast<T>(0);
		itsDelayBuffer[0] = inputSample - DSP::Utility::dotProduct(itsDelayBuffer, itsCoefficients.denominator);
		T outputSample = DSP::Utility::dotProduct(itsDelayBuffer, itsCoefficients.numerator);
		DSP::Utility::shiftByOneSample(itsDelayBuffer);

		return outputSample;
	}

	template <typename T>
	void IIRCanonical<T>::resizeDelayBuffer()
	{
		std::size_t newSize = std::max(itsCoefficients.numerator.size(), itsCoefficients.denominator.size());
		itsDelayBuffer.resize(newSize);
	}

	



}




