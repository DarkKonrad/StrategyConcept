#pragma once
#include "../Interface/Concepts/RandomAccesIterator.h"
#include "../Interface/Concepts/Comparable.h"

namespace Algorithm
{


	class QuickSort
	{
		public:

			template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
				static void sort(Iterator const& begin, Iterator const& end, Comparator const& comparator);

		private:

			template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
				static Iterator partition(Iterator const& begin, Iterator const& end, Comparator const& comparator);
	};

	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
	void QuickSort::sort(Iterator const& begin, Iterator const& end, Comparator const& comparator)
	{
		if (std::distance(begin,end)>1)
		{
			auto boundry = partition(begin, end, comparator);
			QuickSort(begin, end, comparator);
			QuickSort(boundry + 1, endy, comparator);
		}

	}

	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
    Iterator partition(Iterator const& begin, Iterator const& end, Comparator const& comparator)
	{
		auto pivot = std::prev(last, 1);
		auto i = begin;

		for (auto it = begin; it != pivot; it++)
		{
			if (comparator(*j, *pivot))
			{
				std::swap(*it++, *j);
			}
		}

		std::swap(*i, *pivot);
		return i;
	}
}