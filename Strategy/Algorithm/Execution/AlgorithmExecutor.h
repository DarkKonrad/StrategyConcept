#pragma once
#include <iterator>
#include <algorithm>
#include "../Interface/Concepts/Iterable.h"
#include "../Interface/Concepts/ComparatorFunctor.h"
#include "../Interface/Concepts/RandomAccesIterator.h"
#include "../Algorithms/QuickSort.h"

#include <functional>

namespace Algorithm
{

	template<typename DataSetObjectType, typename DataType> requires Interface::Iterable<DataSetObjectType>
		class AlgorithmExecutor
		{
		private:

			AlgorithmExecutor() {}
			DataSetObjectType* object;

		public:

			AlgorithmExecutor(DataSetObjectType* dataSet): object(dataSet) {}
			void setDataSet(DataSetObjectType* dataSet) { object = dataSet; }

			template<class Algorithm, class Comparator> requires Interface::ComparatorFunctor<Comparator>
			void Execute(Comparator comparator);

			template<class Algorithm>
			void Execute(std::function<bool(DataType left, DataType right)>comparator);


			template<class Comparator> 
			void ExecuteQuickSort(Comparator comparator);
		
			void ExecuteQuickSort(std::function<bool(DataType left, DataType right)> comparator);  // Wondering if compiler will lost 
			
			void ExecuteQuickSort();

		};


		
		template<typename DataSetObjectType, typename DataType> requires Interface::Iterable<DataSetObjectType>

		template<class Algorithm, class Comparator>	requires Interface::ComparatorFunctor<Comparator>
		inline void AlgorithmExecutor<DataSetObjectType, DataType>::Execute(Comparator comparator) 
		{
			Algorithm::sort(std::begin(*object), std::end(*object), comparator);
		}

		template<typename DataSetObjectType, typename DataType> requires Interface::Iterable<DataSetObjectType>
		template<class Algorithm>
		inline void AlgorithmExecutor<DataSetObjectType, DataType>::Execute(std::function<bool(DataType left, DataType right)>comparator)
		{
			Algorithm::sort(object->begin(), object->end(), comparator);
		}

		//Uses deafult Comparator 'lhs < rhs';
		template<typename DataSetObjectType, typename DataType> requires Interface::Iterable<DataSetObjectType>
		inline void AlgorithmExecutor<DataSetObjectType, DataType>::ExecuteQuickSort()
		{
			Execute<QuickSort>(std::less<DataType>());
			
		}

		template<typename DataSetObjectType, typename DataType> requires Interface::Iterable<DataSetObjectType>
		inline void AlgorithmExecutor<DataSetObjectType, DataType>::ExecuteQuickSort(std::function<bool(DataType left, DataType right)>comparator)
		{
			Execute<QuickSort>(comparator);
		}

		template<typename DataSetObjectType, typename DataType> requires Interface::Iterable<DataSetObjectType>
			
		template<class Comparator> 
		inline void AlgorithmExecutor<DataSetObjectType, DataType>::ExecuteQuickSort(Comparator comparator) 
		{
			Execute<QuickSort>(comparator);
		}
}