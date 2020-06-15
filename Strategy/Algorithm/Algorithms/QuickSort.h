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
				static void sort(Iterator const&  begin, Iterator const&  end, Comparator const& comparator);

		private:

			template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator> 
				static Iterator partition(Iterator const&  begin, Iterator const& end,Comparator const& comparator);
	};

	
	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
		Iterator QuickSort::partition(Iterator const& begin, Iterator const& end, Comparator const& comparator)
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
	void QuickSort::sort(Iterator const& begin, Iterator const& end, Comparator const& comparator)
	{
		if (std::distance(begin,end)>1)
		{
			Iterator boundry = partition(begin, end, comparator);
			sort(begin, boundry, comparator);
			sort(boundry + 1, end, comparator);
		}

	}


}