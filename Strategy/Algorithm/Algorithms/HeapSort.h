#pragma once
#include "../Interface/Concepts/RandomAccesIterator.h"
#include "../Interface/Concepts/Comparable.h"

namespace Algorithm
{
	class HeapSort
	{
		public:

		template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
			static void sort(Iterator const& begin, Iterator const& end, Comparator const& comparator);

		private:

		template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
			static void heapify(Iterator const& begin, Iterator const& end, Comparator const& comparator);
	};


	template<typename Iterator, typename Comparator> requires Interface::RandomAccessIterator<Iterator>
	void HeapSort::heapify(Iterator const& begin, Iterator const& end, Comparator const& comparator)
	{
		auto size = std::distance(begin, end);
		auto node = begin;

	}


}