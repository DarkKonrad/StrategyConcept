#include <iostream>
#include "Strategy/AlgorithmStrategy.h"
#include "Algorithm/Algorithms/QuickSort.h"
#include "Algorithm/Interface/Concepts/Iterable.h"

#include <vector>
using namespace std;

template<class Iterable_Col> requires Algorithm::Interface::Iterable<Iterable_Col>
void showCollection(Iterable_Col const& item)
{
	cout << endl << endl;
	for (auto it = std::begin(item); it != std::end(item); ++it)
	{
		cout << *it << " ";
	}
		
}

bool comparefunc(int a, int b)
{
	return a < b;
}

struct myCompar
{
	bool operator ()(int a,int b)
	{
		return a > b;
	}
};
void main()
{
	int foo[] = { 10,20,30,40,50 };
	vector<int> bar;
	vector<int> vec = { 999, 9, 7, 3, 2, 5, 6, 4, 1, 8 };
	// iterate foo: inserting into bar
	for (auto it = std::begin(foo); it != std::end(foo); ++it)
		bar.push_back(*it);
	
	//showCollection(vec);
    
	AlgorithmStrategy<vector<int>, int> strategy;
	strategy.setStrategy(StrategyType::HeapSort);
	//strategy.Execute(&vec);
	
	showCollection(vec);
	
	strategy.Execute(&vec);

	showCollection(vec);

	//strategy.Execute(&vec, myCompar());
	//showCollection(vec);

	//strategy.Execute(&vec, comparefunc);
	//showCollection(vec);
	//Algorithm::QuickSort::sort(std::begin(vec), std::end(vec), std::less<int>());
	
	//quick.executeAlgorithm();

	getchar();

}