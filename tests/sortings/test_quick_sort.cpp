#include "algorithms/sorting/quick_sort.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

// QuickSort(T* arr, std::ptrdiff_t left, std::ptrdiff_t right) — сортирует
// диапазон [left, right] включительно, работая напрямую с "сырым" указателем.

TEST(QuickSortTest, SortsRandomVector)
{
	std::vector< int > data = { 5, 3, 8, 1, 9, 2, 7 };
	std::vector< int > expected = data;
	std::sort(expected.begin(), expected.end());

	QuickSort(data.data(), 0, static_cast< std::ptrdiff_t >(data.size()) - 1);

	EXPECT_EQ(data, expected);
}

TEST(QuickSortTest, HandlesEmptyAndSingleElement)
{
	std::vector< int > empty_data;
	// right = -1 при пустом векторе: left(0) >= right(-1) -> функция
	// сразу выходит, arr[l] не разыменовывается, поэтому это безопасно.
	QuickSort(empty_data.data(), 0, static_cast< std::ptrdiff_t >(empty_data.size()) - 1);
	EXPECT_TRUE(empty_data.empty());

	std::vector< int > single = { 42 };
	QuickSort(single.data(), 0, static_cast< std::ptrdiff_t >(single.size()) - 1);
	EXPECT_EQ(single, (std::vector< int >{ 42 }));
}
