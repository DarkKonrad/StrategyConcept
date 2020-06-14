#pragma once
#include "../../Algorithm/Execution/AlgorithmExecutor.h"
#include "../Interface/IStrategy.h"
#include "../../Algorithm/Algorithms/QuickSort.h"
#include "../../Algorithm/Interface/Concepts/Iterable.h"




namespace Strategy
{
	template<class DataSetType, class DataType>
	class QuickSortStrategy : public Interface::IStrategy<DataSetType>
	{
	private:
		QuickSortStrategy() {}
		Algorithm::AlgorithmExecutor<DataSetType, DataType> algorithmExecutor;

	public:
		QuickSortStrategy(DataSetType* object) : algorithmExecutor(object) {}
		void setDataSet(DataSetType* object) { algorithmExecutor.setDataSet(object); }

		virtual void ExecuteAlgorithm() override
		{
			algorithmExecutor.ExecuteQuickSort();
		}
		virtual void ExecuteAlgorithm(std::function<bool(DataType left, DataType right)> comparator) 
		{
			algorithmExecutor.ExecuteQuickSort(comparator);
		}
	};
}