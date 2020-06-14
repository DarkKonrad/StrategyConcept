#pragma once
#include "../Interface/Concepts/RandomAccesIterator.h"
#include "../Interface/Concepts/Comparable.h"

#include <algorithm>
#include <iterator>

namespace Algorithm
{
	class QuickSort
	{
		public:

			template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
				static void sort(Iterator  begin, Iterator  end, Comparator comparator);

		private:

			template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
				static Iterator partition(Iterator  begin, Iterator  end, Comparator comparator);
	};

	
	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
		Iterator QuickSort::partition(Iterator  begin, Iterator  end, Comparator comparator)
		{
			auto pivot = std::prev(end, 1);
			auto i = begin;

			for (auto it = begin; it != pivot; ++it)
			{
				if (comparator(*it, *pivot))
				{
					std::swap(*i++, *it);
				}
			}
			std::swap(*i, *pivot);
			return i;
		}
	
	
	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
	void QuickSort::sort(Iterator  begin, Iterator  end, Comparator comparator)
	{
		if (std::distance(begin,end)>1)
		{
			Iterator boundry = partition(begin, end, comparator);
			sort(begin, boundry, comparator);
			sort(boundry + 1, end, comparator);
		}

	}


}