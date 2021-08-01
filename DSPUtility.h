#pragma once

#include <vector>
#include <cassert>
#include <algorithm>

namespace DSP
{
	namespace Utility
	{
		template <typename T>
		T dotProduct(const std::vector<T>& aVec, const std::vector<T>& anotherVec)
		{		
			// It actually does a partial dot product over the size of the shorter vector
			T result{ 0 };
			std::size_t shorterVecLen = std::min(aVec.size(), anotherVec.size());

			for (std::size_t i = 0; i < shorterVecLen; ++i)
			{
				result += aVec[i] * anotherVec[i];
			}

			return result;
		}

		template <typename T>
		void shiftByOneSample(std::vector<T>& aVec)
		{
			for (std::size_t i = aVec.size() - 1; i > 0; --i)
			{
				aVec[i] = aVec[i - 1];
			}
		}

		template <typename T>
		void zeroPadding(std::vector<T>& aVec, std::size_t numberOfZeros)
		{
			for (std::size_t i = 0; i < numberOfZeros; ++i)
			{
				aVec.push_back(static_cast<T>(0));
			}
		}


	}	
}

