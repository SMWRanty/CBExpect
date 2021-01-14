#pragma once
#include "Expect.hpp"

namespace Cloudburst::Expect
{
	class MakeExpect 
	{
	public:
		MakeExpect(const std::string& file, uint32_t line):
			_file(file),
			_line(line)
		{}

		template <class Type> Expect<Type> expect(const Type& value) const
		{
			return Expect<Type>(value,  _file, _line);
		}

		Expect<std::string> expect(const char* value) const
		{
			return Expect<std::string>(value, _file, _line);
		}
	private:
		std::string _file;
		uint32_t _line;
	};
			
	inline MakeExpect build_make_expect(const std::string& file, uint32_t line)
  {
		return MakeExpect(file, line);
	}
}

#define CBEXPECT_EXPECT ::Cloudburst::Expect::build_make_expect(__FILE__, __LINE__).expect
