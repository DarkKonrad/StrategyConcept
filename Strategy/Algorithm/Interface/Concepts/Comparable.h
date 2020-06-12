#pragma once
#include <concepts>
namespace Algorithm
{
	namespace Interface
	{	
		// To use with std library's sorting the '<' operator is enough
		// This requirement is defined for potential future use for other alogithms
		template<typename Type>
		concept Comparable = requires(Type left, Type right)
		{
			{ left == right } -> bool;
			{ left != right } -> bool;
			{ left < right } -> bool;
			{ left > right } -> bool;
		};
	
		template<typename Type>
		concept BasicComparable = requires(Type left, Type right)
		{
			{ left < right } -> bool;		
		};

		// Concept Random Acces iterator ? | Begin End
	}
}