#pragma once
#include <vector>
#include "Concepts/Comparable.h"
#include "Concepts/RandomAccesIterator.h"

namespace Algorithm
{
	namespace Interface
	{
		/*
			Alogrithm 
			sort(DataSet,begin,last)
		*/

		class Algorithm
		{
			public:
			template<typename Iterator,typename Comparator> requires RandomAccessIterator<Iterator> || Comparable<Comparator>
				void sort(Iterator begin, Iterator end, Comparator comparator);
			

		};


	}
}