#include "algorithms/sorting/counting_sort.hpp"
#include "algorithms/sorting/heap_sort.hpp"
#include "algorithms/sorting/insertion_sort.hpp"
#include "algorithms/sorting/merge_sort.hpp"
#include "algorithms/sorting/quick_sort.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

//--------------------int-numbers------------------------------------------
TEST(MergeSortTest, EmptyArrayTest)
{
	std::vector< int > arr = {};
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = {};
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, EmptyArrayTest)
{
	std::vector< int > arr = {};
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = {};
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, EmptyArrayTest)
{
	std::vector< int > arr = {};
	InsertionSort(arr.data(), arr.size());
	std::vector< int > exp = {};
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, EmptyArrayTest)
{
	std::vector< int > arr = {};
	Heap_Sort(arr);
	std::vector< int > exp = {};
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, EmptyArrayTest)
{
	std::vector< int > arr = {};
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< int > exp = {};
	EXPECT_EQ(arr, exp);
}

//---------------------------------------------------------------------------

TEST(MergeSortTest, OneElemTest)
{
	std::vector< int > arr = { 1 };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 1 };
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, OneElemTest)
{
	std::vector< int > arr = { 1 };
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 1 };
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, OneElemTest)
{
	std::vector< int > arr = { 1 };
	InsertionSort(arr.data(), arr.size());
	std::vector< int > exp = { 1 };
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, OneElemTest)
{
	std::vector< int > arr = { 1 };
	Heap_Sort(arr);
	std::vector< int > exp = { 1 };
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, OneElemTest)
{
	std::vector< int > arr = { 1 };
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< int > exp = { 1 };
	EXPECT_EQ(arr, exp);
}
//-------------------------------------------------------------------------
TEST(MergeSortTest, SortedArray)
{
	std::vector< int > arr = { 1, 2, 3, 4, 5, 6 };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, SortedArray)
{
	std::vector< int > arr = { 1, 2, 3, 4, 5, 6 };
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, SortedArray)
{
	std::vector< int > arr = { 1, 2, 3, 4, 5, 6 };
	InsertionSort(arr.data(), arr.size());
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, SortedArray)
{
	std::vector< int > arr = { 1, 2, 3, 4, 5, 6 };
	Heap_Sort(arr);
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, SortedArray)
{
	std::vector< int > arr = { 1, 2, 3, 4, 5, 6 };
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}
//-------------------------------------------------------------------------
TEST(MergeSortTest, ReversedArray)
{
	std::vector< int > arr = { 6, 5, 4, 3, 2, 1 };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, ReversedArray)
{
	std::vector< int > arr = { 6, 5, 4, 3, 2, 1 };
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, ReversedArray)
{
	std::vector< int > arr = { 6, 5, 4, 3, 2, 1 };
	InsertionSort(arr.data(), arr.size());
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, ReversedArray)
{
	std::vector< int > arr = { 6, 5, 4, 3, 2, 1 };
	Heap_Sort(arr);
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, ReversedArray)
{
	std::vector< int > arr = { 6, 5, 4, 3, 2, 1 };
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< int > exp = { 1, 2, 3, 4, 5, 6 };
	EXPECT_EQ(arr, exp);
}
//-------------------------------------------------------------------------
TEST(MergeSortTest, EqualNumbers)
{
	std::vector< int > arr = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, EqualNumbers)
{
	std::vector< int > arr = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< int > exp = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, EqualNumbers)
{
	std::vector< int > arr = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	InsertionSort(arr.data(), arr.size());
	std::vector< int > exp = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, EqualNumbers)
{
	std::vector< int > arr = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	Heap_Sort(arr);
	std::vector< int > exp = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, EqualNumbers)
{
	std::vector< int > arr = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< int > exp = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	EXPECT_EQ(arr, exp);
}
//------------------float/double-numbers----------------------------------------
TEST(MergeSortTest, FloatAndDoubleTest)
{
	std::vector< double > arr = { 1.1, 0.1, 2.3, 5.001, 6.2 };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< double > exp = { 0.1, 1.1, 2.3, 5.001, 6.2 };
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, FloatAndDoubleTest)
{
	std::vector< double > arr = { 1.1, 0.1, 2.3, 5.001, 6.2 };
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< double > exp = { 0.1, 1.1, 2.3, 5.001, 6.2 };
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, FloatAndDoubleTest)
{
	std::vector< double > arr = { 1.1, 0.1, 2.3, 5.001, 6.2 };
	InsertionSort(arr.data(), arr.size());
	std::vector< double > exp = { 0.1, 1.1, 2.3, 5.001, 6.2 };
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, FloatAndDoubleTest)
{
	std::vector< double > arr = { 1.1, 0.1, 2.3, 5.001, 6.2 };
	Heap_Sort(arr);
	std::vector< double > exp = { 0.1, 1.1, 2.3, 5.001, 6.2 };
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, FloatAndDoubleTest)
{
	std::vector< double > arr = { 1.1, 0.1, 2.3, 5.001, 6.2 };
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< double > exp = { 0.1, 1.1, 2.3, 5.001, 6.2 };
	EXPECT_EQ(arr, exp);
}
//-------------------char-typedef------------------------------------------
TEST(MergeSortTest, CharTest)
{
	std::vector< char > arr = { 'c', 'a', 'b', 'd', 's', 'c' };
	MergeSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< char > exp = { 'a', 'b', 'c', 'c', 'd', 's' };
	EXPECT_EQ(arr, exp);
}

TEST(QuickSortTest, CharTest)
{
	std::vector< char > arr = { 'c', 'a', 'b', 'd', 's', 'c' };
	QuickSort(arr.data(), 0, static_cast< std::ptrdiff_t >(arr.size()) - 1);
	std::vector< char > exp = { 'a', 'b', 'c', 'c', 'd', 's' };
	EXPECT_EQ(arr, exp);
}

TEST(InsertionSortTest, CharTest)
{
	std::vector< char > arr = { 'c', 'a', 'b', 'd', 's', 'c' };
	InsertionSort(arr.data(), arr.size());
	std::vector< char > exp = { 'a', 'b', 'c', 'c', 'd', 's' };
	EXPECT_EQ(arr, exp);
}

TEST(HeapSortTest, CharTest)
{
	std::vector< char > arr = { 'c', 'a', 'b', 'd', 's', 'c' };
	Heap_Sort(arr);
	std::vector< char > exp = { 'a', 'b', 'c', 'c', 'd', 's' };
	EXPECT_EQ(arr, exp);
}

TEST(CountingSortTest, CharTest)
{
	std::vector< char > arr = { 'c', 'a', 'b', 'd', 's', 'c' };
	Counting_Sort(arr.data(), static_cast< std::ptrdiff_t >(arr.size()));
	std::vector< char > exp = { 'a', 'b', 'c', 'c', 'd', 's' };
	EXPECT_EQ(arr, exp);
}
