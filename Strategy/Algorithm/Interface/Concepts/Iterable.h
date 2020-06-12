#pragma once
#include <concepts>
#include <iterator>
namespace Algorithm
{
	namespace Interface
	{
		// To use with std library's sorting the '<' operator is enough
		// This requirement is defined for potential future use for other alogithms
		template<typename Container>
		concept Iterable = requires (Container container)
		{
			{ std::begin(container) };
			{ std::end(container) };
		};
	}
}