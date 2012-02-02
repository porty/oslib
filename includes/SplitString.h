#pragma once

#include <string>

namespace OS
{
	template <typename T>
	void splitString(const std::string & Str, const std::string & Splitter, T & Result)
	{
		// stolen from http://www.google.com/codesearch?hl=en&q=+lang:c%2B%2B+SplitString+show:rYrRfbWW31U:OS9bxycGtI8:FDkqeeJuqYM&sa=N&cd=7&ct=rc&cs_p=http://gentoo.osuosl.org/distfiles/boxbackup-0.10.tgz&cs_f=boxbackup-0.10/lib/common/Utils.cpp#a0
		// with slight modification
		// Split it up.
		std::string::size_type b = 0;
		std::string::size_type e = 0;

		while(e = Str.find(Splitter, b), e != Str.npos)
		{
			// Get this string
			unsigned int len = e - b;
			if(len >= 1)
			{
				Result.push_back(Str.substr(b, len));
			}
			//b = e + 1;
			b = e + Splitter.length();
		}
		// Last string
		if(b < Str.size())
		{
			Result.push_back(Str.substr(b));
		}
	}

	template <typename T>
	void splitString(const std::string & Str, const std::string & Splitter, T & Result, int max)
	{
		// stolen from http://www.google.com/codesearch?hl=en&q=+lang:c%2B%2B+SplitString+show:rYrRfbWW31U:OS9bxycGtI8:FDkqeeJuqYM&sa=N&cd=7&ct=rc&cs_p=http://gentoo.osuosl.org/distfiles/boxbackup-0.10.tgz&cs_f=boxbackup-0.10/lib/common/Utils.cpp#a0
		// with slight modification
		// Split it up.
		std::string::size_type b = 0;
		std::string::size_type e = 0;
		int count = 0;

		while(e = Str.find(Splitter, b), (e != Str.npos) && (++count < max))
		{
			// Get this string
			unsigned int len = e - b;
			if(len >= 1)
			{
				Result.push_back(Str.substr(b, len));
			}
			//b = e + 1;
			b = e + Splitter.length();
		}
		// Last string
		if(b < Str.size())
		{
			Result.push_back(Str.substr(b));
		}
	}
}
