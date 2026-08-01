#include "sorting/merge_sort.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

TEST(MergeSortTest, SingleElementOrEmpty)
{
	std::vector< int > arr = { 42 };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);

	EXPECT_EQ(arr[0], 42);
}

TEST(MergeSortTest, SortsPositiveNumbers)
{
	std::vector< int > arr = { 5, 2, 8, 1, 9, 3 };
	std::vector< int > expected = { 1, 2, 3, 5, 8, 9 };

	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);

	ASSERT_EQ(arr, expected);
}

TEST(MergeSortTest, HandlesDuplicatesAndNegatives)
{
	std::vector< int > arr = { -3, 5, 2, -3, 0, 5, 1 };

	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);

	EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

TEST(MergeSortTest, AlreadySorted)
{
	std::vector< int > arr = { 1, 2, 3, 4, 5 };
	std::vector< int > expected = { 1, 2, 3, 4, 5 };

	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);

	EXPECT_EQ(arr, expected);
}
