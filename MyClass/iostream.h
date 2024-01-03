#pragma once
#include "istream.h"
#include "ostream.h"

namespace STD
{
	class iostream : public istream, public ostream
	{
	public:
		iostream() {}
	};
}