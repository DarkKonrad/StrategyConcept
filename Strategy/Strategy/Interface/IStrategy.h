#pragma once
#include "../../Algorithm/Execution/AlgorithmExecutor.h"
#include <functional>

namespace Strategy
{
	enum class AlgorithmType
	{
		QuickSort=1,
		BubbleSort,
		InsertionSort,
		TreeSort
	};

	
	namespace Interface
	{
		template<class DataType>
		class IStrategy
		{
			public:
				//void setDataSet(DataSetType* anotherSet) { algorithmExecutor.setDataSet(anotherSet); }
				virtual void ExecuteAlgorithm() = 0;
				//virtual void ExecuteAlgorithm(std::function<bool(DataType left, DataType right)> comparator) = 0;
		
			
		};

	}
}
