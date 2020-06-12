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
		struct BaseComparator
		{
			virtual bool operator()(DataType lhs, DataType rhs) = 0;
		};
		
		template<class DataType>
		using Comparator = BaseComparator<DataType>;

		template<class DataType,class DataSet> requires Algorithm::Interface::Iterable<DataSet>
		class IStrategy
		{
			private:
				Comparator<DataType>* comparator;
				DataSet dataSet;
				
				IStrategy(){}
			
			public:

				// Comparator is functor which provides comparation method for algorithm
				IStrategy(DataSet dataSet,Comparator<DataType> comparator): dataSet(dataSet), comparator(comparator) {}

				virtual ~IStrategy() { delete comparator; }
				virtual void executeAlgorithm() = 0;

				void setData(DataSet const& dataToSort) { this->dataSet = dataToSort; }
				void setComparator(Comparator<DataType>* comparator) { this->comparator = comparator; }
				
		};

	}
}
