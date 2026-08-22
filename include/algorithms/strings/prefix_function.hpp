#include <iostream>
#include <string>
#include <vector>

std::vector< size_t > prefix_function(const std::string& str)
{
	std::vector< size_t > pr(str.size());
	pr[0] = 0;
	if (str.empty())
	{
		return {};
	}
	for (size_t i = 1; i < str.size(); i++)
	{
		size_t j = pr[i - 1];
		while (j > 0 && str[i] != str[j])
		{
			j = pr[j - 1];
		}
		if (str[i] == str[j])
		{
			j++;
		}
		pr[i] = j;
	}
	return pr;
}
