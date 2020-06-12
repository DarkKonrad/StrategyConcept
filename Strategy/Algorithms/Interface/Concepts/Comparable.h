#pragma once
#include <concepts>
namespace Algorithm
{
	namespace Interface
	{	
		template<typename Type>
		concept Comparable = requires(Type left, Type right)
		{
			{ left == right } -> bool;
			{ left != right } -> bool;
			{ left < right } -> bool;
			{ left > right } -> bool;
		}
	
	}
}