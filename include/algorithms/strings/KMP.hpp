#include "strings/prefix_function.hpp"

#include <iostream>
#include <string>
#include <vector>

size_t KMP(const std::string& str, const std::string& word)
{
	if (str.empty() || word.empty())
	{
		return 0;
	}
	std::string fw = word + '\0' + str;
	size_t sow = word.size();
	std::vector< size_t > prefix = prefix_function(fw);

	size_t count = 0;
	for (size_t num : prefix)
	{
		if (sow == num)
		{
			count++;
		}
	}
	return count;
}
