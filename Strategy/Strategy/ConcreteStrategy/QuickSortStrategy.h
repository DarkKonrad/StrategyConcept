#pragma once
#include "../Interface/IStrategy.h"
#include "../../Algorithm/Algorithms/QuickSort.h"
#include "../../Algorithm/Interface/Concepts/Iterable.h"
namespace Strategy
{
	
	template<class DataType>
	struct DefaultQuickSortComparator : public Interface::Comparator<DataType>
	{
		virtual bool operator()(DataType lhs, DataType rhs) override
		{
			return lhs < rhs;
		}
	};

	template<class DataType, class DataSet> requires Algorithm::Interface::Iterable<DataSet>
	class QuickSortStrategy : public Interface::IStrategy<DataType, DataSet>
	{
		private:
		QuickSortStrategy() {}

		public:
		QuickSortStrategy(DataSet dataSet, Comparator<DataType>* comparator = new DefaultQuickSortComparator):
			IStrategy(dataSet,comparator){}

		virtual void executeAlgorithm()
		{
			Algorithm::QuickSort::sort(this->dataSet.begin(), this->dataSet.end(), this->comparator);
		}
	};
}