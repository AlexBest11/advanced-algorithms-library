#include "algorithms/data_structures/heap.hpp"

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

	while (heap.get_size() > 0)
	{
		data_.push_back(heap.top());
	}
	data = data_;
	return data_;
}
