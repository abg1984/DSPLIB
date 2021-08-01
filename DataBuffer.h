#pragma once

#include "Subject.h"
#include <queue>

namespace DSP
{
	template <typename T>
	class DataBuffer : public Subject 
	{
	public:
		DataBuffer(std::size_t size)
			: itsSize{ size }
		{
		}

		T& front()
		{
			return itsData.front();
		}

		void pop()
		{
			itsData.pop();
		}

		void fill(T newData)
		{
			if (isBufferFull())
			{
				itsData.push(newData);
			}
			else
			{				
				notify(); // Notify observers
			}
		}

	private:
		bool isBufferFull()
		{
			return itsData.size() <= itsSize;
		}

		std::queue<T> itsData;
		std::size_t itsSize;
	};
}
