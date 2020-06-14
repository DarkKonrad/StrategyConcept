#pragma once
#include <iterator>

namespace Algorithm
{
	namespace Interface
	{
		template<typename _Iterator>
		concept RandomAccessIterator = requires (_Iterator left, _Iterator right)
		{
			{ left == right } -> bool;
			{ left != right } -> bool;
			{ left < right } ->bool;
			{ left > right } ->bool;
			{ left <= right } ->bool;
			{ left >= right }->bool;
			{ left[0] };
			{ std::swap(left, right) };

			{ *left };
			{ left++ };
			{ ++left };
			{ *left++ };
			{ --left };
			{ left-- };
			{ *left-- };

		};
	}
}