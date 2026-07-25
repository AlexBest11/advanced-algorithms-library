#include <iostream>
#include <utility>
#include <vector>

// 0 - maxHeap
// 1 - minHeap
// in method compare: operator >
template< typename T >
class Heap
{
  private:
	std::vector< T > heap;
	bool which;
	bool compare(size_t i, size_t j)
	{
		if (which == 0)
		{
			return heap[i] > heap[j];
		}
		else
		{
			return heap[i] < heap[j];
		}
	}

  public:
	Heap(std::vector< T > data, bool wh)
	{
		heap = std::move(data);
		which = wh;
		if (!heap.empty())
		{
			for (size_t i = heap.size() / 2; i > 0; i--)
			{
				sift_down(i - 1);
			}
		}
	}

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
	size_t get_size() { return heap.size(); }
};
