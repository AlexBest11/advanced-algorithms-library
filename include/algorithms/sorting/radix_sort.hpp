#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template< typename T >
void Radix_Sort(T* arr, size_t size)
{
	if (size == 0)
	{
		return;
	}

	T max = *(std::max_element(arr, arr + size));

	if (max == 0)
	{
		return;
	}

	size_t cnt = 0;
	while (max != 0)
	{
		max = max / 10;
		cnt += 1;
	}
	int div = 1;
	for (size_t d = 1; d <= cnt; d++)
	{
		std::vector< size_t > count(10, 0);

		for (std::ptrdiff_t i = 0; i < size; i++)
		{
			count[(arr[i] / div) % 10] += 1;
		}
		for (std::ptrdiff_t i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		std::vector< T > result(size);
		for (std::ptrdiff_t i = size; i > 0;)
		{
			--i;
			std::ptrdiff_t count_idx = (arr[i] / div) % 10;
			count[count_idx] -= 1;
			result[count[count_idx]] = arr[i];
		}
		for (std::ptrdiff_t i = 0; i < size; i++)
		{
			arr[i] = result[i];
		}
		div *= 10;
	}
}
