#include <iostream>
#include <string>
#include <vector>

std::vector< size_t > z_function(const std::string& str)
{
	size_t n = str.size();
	size_t l = 0, r = 0;
	std::vector< size_t > z(n, 0);
	for (size_t i = 1; i < n; ++i)
	{
		if (i < r)
		{
			z[i] = std::min(r - i, z[i - l]);
		}
		while (i + z[i] < n && str[z[i]] == str[i + z[i]])
		{
			z[i]++;
		}
		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}
	return z;
}
