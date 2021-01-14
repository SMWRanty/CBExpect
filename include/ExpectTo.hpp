#pragma once
#include "TestExpectationFailure.hpp"

#include <string>

namespace Cloudburst::Expect
{
	template <class Type> class ExpectTo
	{
	public:
	ExpectTo(const Type& actual, const std::string& file, uint32_t line):
		_actual(actual),
		_file(file),
		_line(line)
	{}

  void equal(const Type& expected) const
	{
		if (expected != _actual)
		{
			throw TestExpectationFailure<Type>(expected, _actual, _file, _line);
		}
	}

	void beGreaterThanOrEqualTo(const Type& expected) const
	{
		if (_actual < expected)
		{
			throw TestExpectationFailure<Type>(expected, _actual, _file, _line);
		}
	}
	private:
		const Type& _actual;
		std::string _file;
		uint32_t _line;
	};
}
