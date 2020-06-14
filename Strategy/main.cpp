#include <iostream>
#include"Strategy/ConcreteStrategy/QuickSortStrategy.h"

#include "Strategy/Interface/IStrategy.h"
#include "Algorithm/Algorithms/QuickSort.h"
#include "Algorithm/Interface/Concepts/Iterable.h"

#include <vector>
using namespace std;

void main()
{
	int foo[] = { 10,20,30,40,50 };
	vector<int> bar;

	// iterate foo: inserting into bar
	for (auto it = std::begin(foo); it != std::end(foo); ++it)
		bar.push_back(*it);

	Strategy::QuickSortStrategy<int, vector<int>> quick(bar);
}