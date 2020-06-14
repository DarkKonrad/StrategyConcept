#pragma once
#include "../../Algorithm/Interface/Concepts/Iterable.h"

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
		struct IBaseComparator
		{
			virtual bool operator()(DataType lhs, DataType rhs) = 0;
		};
		
		template<class DataType>
		using Comparator = IBaseComparator<DataType>;

		template<class DataType,class DataSet> requires Algorithm::Interface::Iterable<DataSet>
		class IStrategy
		{
			protected:
				IStrategy() {}
				Comparator<DataType>* comparator;
				DataSet dataSet;

			public:
				// Comparator is functor which provides comparation method for algorithm
				IStrategy(DataSet dataSet,Comparator<DataType>* comparator = nullptr): dataSet(dataSet), comparator(comparator) {}

				virtual ~IStrategy() { delete comparator; }
				virtual void executeAlgorithm() = 0;

				void setData(DataSet const& dataToSort) { this->dataSet = dataToSort; }
				void setComparator(Comparator<DataType>* comparator) { this->comparator = comparator; }
				
		};

	}
}
