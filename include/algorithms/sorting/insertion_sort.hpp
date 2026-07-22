#include <cstddef>
#include <iostream>
template< typename T >
void InsertionSort(T *arr, size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		T cur = arr[i];
		std::ptrdiff_t j = static_cast< std::ptrdiff_t >(i) - 1;
		while (j >= 0 && arr[j] > cur)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = cur;
	}
}
