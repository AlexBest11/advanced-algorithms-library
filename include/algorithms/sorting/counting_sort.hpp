#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

template< typename T >
void Counting_Sort(T* arr, std::ptrdiff_t len)
{
	if (len <= 0)
	{
		return;
	}
	T max = *(std::max_element(arr, arr + len));
	T min = *(std::min_element(arr, arr + len));
	std::vector< T > count(max - min + 1);
	for (std::ptrdiff_t i = 0; i < len; i++)
	{
		count[arr[i] - min] += 1;
	}
	for (std::ptrdiff_t i = 1; i < max - min + 1; i++)
	{
		count[i] += count[i - 1];
	}
	std::vector< T > cnt(len);
	for (std::ptrdiff_t i = len; i > 0;)
	{
		--i;
		std::ptrdiff_t count_idx = arr[i] - min;
		count[count_idx] -= 1;
		cnt[count[count_idx]] = arr[i];
	}
	for (std::ptrdiff_t i = 0; i < len; i++)
	{
		arr[i] = cnt[i];
	}
}
