#pragma once

#include "DSPUtility.h"

namespace DSP
{
	template <typename T>
	class FIRDirectForm
	{
	public:
		FIRDirectForm() = default;
		FIRDirectForm(const std::vector<T>& coefficients);
		FIRDirectForm(std::vector<T>&& coefficients);
		FIRDirectForm(std::initializer_list<T> coefficients);
		T processSample(T inputSample);
		
	private:
		//void resizeDelayBuffer();
		std::vector<T> itsCoefficients;
		std::vector<T> itsDelayBuffer;
	};
}

template <typename T>
DSP::FIRDirectForm<T>::FIRDirectForm(const std::vector<T>& coefficients)
{
	itsCoefficients = coefficients;
	itsDelayBuffer.resize(itsCoefficients.size());
}

template <typename T>
DSP::FIRDirectForm<T>::FIRDirectForm(std::vector<T>&& coefficients)
{
	itsCoefficients = std::move(coefficients);
	itsDelayBuffer.resize(itsCoefficients.size());
}

template <typename T>
DSP::FIRDirectForm<T>::FIRDirectForm(std::initializer_list<T> coefficients)
{
	itsCoefficients.assign(coefficients);
	itsDelayBuffer.resize(itsCoefficients.size());
}

template <typename T>
T DSP::FIRDirectForm<T>::processSample(T inputSample)
{
	itsDelayBuffer[0] = inputSample;
	T outputSample = DSP::Utility::dotProduct(itsDelayBuffer, itsCoefficients);
	DSP::Utility::shiftByOneSample(itsDelayBuffer);

	return outputSample;
}

//template <typename T>
//void DSP::FIRDirectForm<T>::resizeDelayBuffer()
//{
//	itsDelayBuffer.resize(itsCoefficients.size());
//}






