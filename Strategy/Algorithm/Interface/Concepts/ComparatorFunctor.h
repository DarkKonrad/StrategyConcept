#pragma once

namespace Algorithm
{
	namespace Interface
	{
		template<typename Functor>
		concept ComparatorFunctor = requires(Functor f)
		{
			{ f.operator() }->bool;
		};

	}
}
