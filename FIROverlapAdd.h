#pragma once

#include <memory>
#include <vector>
#include "Observer.h"
#include "DataBuffer.h"

namespace DSP
{
	// Absttract base class
	template <typename T>
	class FIROverlapAdd : public Observer
	{
	public:
		FIROverlapAdd(DataBuffer<T>* inputBlock, DataBuffer<T>* outputBlock)
			: itsInputBlock{ inputBlock }, itsOutputBlock{ outputBlock }
		{
		}

		virtual ~FIROverlapAdd() = default;
		void setCoefficients(const std::vector<T>& coefficients);
		void setCoefficients(std::vector<T>&& coefficients);
		virtual void processBlock() = 0;
		virtual void update() override;

	protected:
		std::vector<T> itsTailFromLastBlock;

	private:
		std::vector<T> itsCoefficients;
		DataBuffer<T>* itsInputBlock;
		DataBuffer<T>* itsOutputBlock;
	};

	template <typename T>
	void FIROverlapAdd<T>::setCoefficients(const std::vector<T>& coefficients)
	{
		itsCoefficients = coefficients;
		itsTailFromLastBlock.resize(itsCoefficients.size());
	}

	template <typename T>
	void FIROverlapAdd<T>::setCoefficients(std::vector<T>&& coefficients)
	{
		itsCoefficients = std::move(coefficients);
		itsTailFromLastBlock.resize(itsCoefficients.size());
	}

	template <typename T>
	void DSP::FIROverlapAdd<T>::update() 
	{
		processBlock();
	}

	// Derived classes
	template <typename T>
	class FIROverlapAddTime : public FIROverlapAdd<T>
	{
	public:
		using FIROverlapAdd<T>::FIROverlapAdd;
		virtual void processBlock() override;
	};

	template <typename T>
	void FIROverlapAddTime<T>::processBlock()
	{

	}
}


