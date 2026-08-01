// We used the `<=` comparison to make the algorithm robust.
#include <cstddef>
#include <iostream>
#include <vector>

template< typename T >
void Merge(T* arr, std::ptrdiff_t left, std::ptrdiff_t mid, std::ptrdiff_t right)
{
	std::vector< T > arr_tmp(static_cast< std::ptrdiff_t >(right - left + 1));
	std::ptrdiff_t i = left;
	std::ptrdiff_t j = mid + 1;
	std::ptrdiff_t k = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			arr_tmp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			arr_tmp[k] = arr[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		arr_tmp[k] = arr[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		arr_tmp[k] = arr[j];
		k++;
		j++;
	}
	for (std::ptrdiff_t idx = left; idx <= right; idx++)
	{
		arr[idx] = arr_tmp[idx - left];
	}
}

template< typename T >
void MergeSort(T* arr, std::ptrdiff_t left, std::ptrdiff_t right)
{
	if (left >= right)
	{
		return;
	}
	std::ptrdiff_t mid = left + (right - left) / 2;

	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);

	Merge(arr, left, mid, right);
}
