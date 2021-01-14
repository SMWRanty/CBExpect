#pragma once
#include "ExpectTo.hpp"
#include "ExpectNotTo.hpp"

#include <string>

namespace Cloudburst::Expect
{
	template <class Type> class Expect 
	{
	public:
		Expect(const Type& actual, const std::string& file, uint32_t line):
				to(actual, file, line),
				notTo(actual, file, line)
		{}

		ExpectTo<Type> to;
		ExpectNotTo<Type> notTo;
	};
}
