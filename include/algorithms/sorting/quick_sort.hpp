#include <cstddef>
#include <iostream>
#include <utility>

template< typename T >

size_t Mediana_three(T* arr, size_t l, size_t r)
{
	size_t mid = l + (r - l) / 2;
	if (arr[l] > arr[mid])
	{
		std::swap(arr[l], arr[mid]);
	}
	if (arr[l] > arr[r])
	{
		std::swap(arr[l], arr[r]);
	}
	if (arr[mid] > arr[r])
	{
		std::swap(arr[r], arr[mid]);
	}
	return mid;
}
template< typename T >
void QuickSort(T* arr, std::ptrdiff_t left, std::ptrdiff_t right)
{
	if (left >= right)
	{
		return;
	}
	size_t mid = Mediana_three(arr, left, right);
	T pivot = arr[mid];
	std::ptrdiff_t i = left;
	std::ptrdiff_t j = right;
	while (j >= i)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	QuickSort(arr, left, j);
	QuickSort(arr, i, right);
}
