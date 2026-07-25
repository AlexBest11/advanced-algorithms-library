#include "data_structures/heap.hpp"

#include <iostream>
#include <vector>

template< typename T >
std::vector< T > Heap_Sort(std::vector< T > &data)
{
	if (data.empty())
	{
		return {};
	}
	Heap< T > heap(std::move(data), 1);
	std::vector< T > data_;
	size_t size = heap.get_size();
	for (size_t i = 0; i < size; i++)
	{
		data_.push_back(heap.pop());
	}
	return data_;
}
