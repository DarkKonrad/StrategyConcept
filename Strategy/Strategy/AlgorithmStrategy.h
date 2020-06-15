#pragma once
#include "../Algorithm/Execution/AlgorithmExecutor.h"
#include "../Algorithm/Interface/Concepts/Iterable.h"

#include <functional>
enum class StrategyType
{
	QuickSort,
	HeapSort
};

template<typename DataSetType, typename DataType> requires Algorithm::Interface::Iterable<DataSetType>
	class AlgorithmStrategy
	{
	private:
		StrategyType strategyType;

	public:

		AlgorithmStrategy() : strategyType(StrategyType::QuickSort) {}

		void Execute(DataSetType* dataSet);

		template<typename Comparator> requires Algorithm::Interface::ComparatorFunctor<Comparator>
			void Execute(DataSetType* dataSet, Comparator const& comparator);

			void Execute(DataSetType* dataSet, std::function<bool(DataType, DataType)> comparator);

			void setStrategy(StrategyType strategyType);
	};


template<typename DataSetType, typename DataType> requires Algorithm::Interface::Iterable<DataSetType>
	void AlgorithmStrategy<DataSetType, DataType>::Execute(DataSetType* dataSet)
	{
		Algorithm::AlgorithmExecutor<DataSetType, DataType> algorithmExecutor(dataSet);

		switch (strategyType)
		{
			case StrategyType::QuickSort:
				algorithmExecutor.ExecuteQuickSort();
				break;
			default:
				break;
		}
	}


template<typename DataSetType, typename DataType> requires Algorithm::Interface::Iterable<DataSetType>

template<typename Comparator> requires Algorithm::Interface::ComparatorFunctor<Comparator>
	void AlgorithmStrategy<DataSetType, DataType>::Execute(DataSetType* dataSet, Comparator const& comparator)
	{
		Algorithm::AlgorithmExecutor<DataSetType, DataType> algorithmExecutor(dataSet);

		switch (strategyType)
		{
			case StrategyType::QuickSort:
				algorithmExecutor.ExecuteQuickSort(comparator);
				break;
			default:
				break;
		}
	}

	template<typename DataSetType, typename DataType> requires Algorithm::Interface::Iterable<DataSetType>
		void AlgorithmStrategy<DataSetType, DataType>::Execute(DataSetType* dataSet, std::function<bool(DataType, DataType)> comparator)
		{
			Algorithm::AlgorithmExecutor<DataSetType, DataType> algorithmExecutor(dataSet);

			switch (strategyType)
			{
				case StrategyType::QuickSort:
					algorithmExecutor.ExecuteQuickSort(comparator);
					break;
				default:
					break;
			}
		}

	template<typename DataSetType, typename DataType> requires Algorithm::Interface::Iterable<DataSetType>
		void AlgorithmStrategy<DataSetType, DataType>::setStrategy(StrategyType strategyType)
		{
					this->strategyType = strategyType;
		}