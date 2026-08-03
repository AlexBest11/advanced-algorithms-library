#include <cstddef>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

template< typename T, typename Compare = std::less< T > >
class PriorityQueue
{
  private:
	std::vector< T > heap;
	Compare comp;
	bool compare(size_t i, size_t j) { return comp(heap[j], heap[i]); }

	void sift_down(size_t idx)
	{
		while (true)
		{
			size_t left = (idx * 2) + 1;
			size_t right = (idx * 2) + 2;

			size_t target = idx;

			if (left < heap.size() && compare(left, target))
			{
				target = left;
			}
			if (right < heap.size() && compare(right, target))
			{
				target = right;
			}

			if (target != idx)
			{
				std::swap(heap[target], heap[idx]);
				idx = target;
			}
			else
			{
				break;
			}
		}
	}

	void sift_up(size_t idx)
	{
		while (idx > 0)
		{
			size_t parent = (idx - 1) / 2;

			if (compare(idx, parent))
			{
				std::swap(heap[parent], heap[idx]);
				idx = parent;
			}
			else
			{
				break;
			}
		}
	}

  public:
	PriorityQueue() = default;

	explicit PriorityQueue(std::vector< T > data, Compare c = Compare()) : heap(std::move(data)), comp(c)
	{
		if (!heap.empty())
		{
			for (std::ptrdiff_t i = heap.size() / 2; i > 0; i--)
			{
				sift_down(i - 1);
			}
		}
	}

	const T& top() const { return heap[0]; }

	T pop()
	{
		T top = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		if (!heap.empty())
		{
			sift_down(0);
		}
		return top;
	}

	void push(const T& elem)
	{
		heap.push_back(elem);
		sift_up(heap.size() - 1);
	}
	void push(T&& elem)
	{
		heap.push_back(std::move(elem));
		sift_up(heap.size() - 1);
	}
	size_t get_size() const { return heap.size(); }
	bool empty() const { return heap.empty(); }
};
