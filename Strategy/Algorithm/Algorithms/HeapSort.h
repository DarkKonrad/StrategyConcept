#pragma once
#include "../Interface/Concepts/RandomAccesIterator.h"
#include "../Interface/Concepts/Comparable.h"

#include <algorithm>
#include <iterator>

namespace Algorithm
{
	class HeapSort
	{
		public:

		template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
			static void sort(Iterator const&  begin, Iterator const&  end, Comparator& comparator);

		private:

		template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
			static void heapify(Iterator const&  begin, Iterator const&  end, Iterator const&  index, Comparator& comparator);
			

	};


	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
	void HeapSort::heapify(Iterator const&  begin, Iterator const&  end,Iterator const&  index ,Comparator& comparator)
	{	
		auto count = std::distance(begin, end);
		
		auto rootIt = index;
		auto rightIt = begin;
		auto leftIt = begin;

		//indexes
		auto left_index = 2 * std::distance(begin, index);
		auto right_index = 2 * std::distance(begin,index) + 1;

		if (left_index < count)
		{
			std::advance(leftIt, left_index); // lets try to prevent accessing out of bound 
			if (comparator(*leftIt, *rootIt))
			{
				rootIt = leftIt;
			}
		}

		if (right_index < count)
		{
			std::advance(rightIt, right_index);
			if (comparator(*rightIt, *rootIt))
			{
				rootIt = rightIt;
			}
		}

		if (rootIt != index)
		{
			std::iter_swap(index, rootIt);
			heapify(begin, end, rootIt, comparator);
		}

	}

	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
	static void HeapSort::sort(Iterator const&  begin, Iterator const&  end, Comparator& comparator)
	{
		auto it = begin;
		auto distance = std::distance(begin, end);
		std::advance(it, distance/2 );

		for (; it > begin ; --it)
		{
			heapify(begin, end, it, comparator);
		}

		for (it=end-1; it != begin ; --it)
		{
			std::iter_swap(begin, it);
			heapify(begin,it, begin, comparator);
		}

	}
}