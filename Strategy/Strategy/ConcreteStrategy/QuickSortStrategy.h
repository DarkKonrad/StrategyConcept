#pragma once
#include "../Interface/IStrategy.h"
#include "../../Algorithm/Algorithms/QuickSort.h"
#include "../../Algorithm/Interface/Concepts/Iterable.h"
namespace Strategy
{
	template<class DataType, class DataSetType> requires Algorithm::Interface::Iterable<DataSetType>
	class Interface::IStrategy;
	
	template<class DataType>
	struct DefaultQuickSortComparator : public Interface::Comparator<DataType>
	{
		virtual bool operator()(DataType lhs, DataType rhs) override
		{
			return lhs < rhs;
		}
	};

	template<class DataType, class DataSetType> requires Algorithm::Interface::Iterable<DataSetType>
	class QuickSortStrategy : public Interface::IStrategy<DataType, DataSetType>
	{
		private:
		QuickSortStrategy() {}

		public:
		QuickSortStrategy(DataSetType const& dataSet, Interface::Comparator<DataType>* comparator = new DefaultQuickSortComparator<DataType>):
			Interface::IStrategy<DataType,DataSetType>(dataSet,comparator){}

		virtual void executeAlgorithm()
		{
			Algorithm::QuickSort::sort(this->dataSet.begin(), this->dataSet.end(), *(this->comparator));
		}
	};
}