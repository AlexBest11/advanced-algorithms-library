#include <initializer_list>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template< typename T >
class Hash_Table_Open
{
  private:
	struct Node
	{
		int key;
		T value;
		Node() = default;
		Node(int k, T v) : key(k), value(v) {}
	};

	size_t size;
	std::vector< std::pair< Node, int > > hash_table;
	size_t count_ = 0;
	size_t count_t = 0;
	double max_load_t = 0.75;
	double max_load_c = 0.5;
	size_t hash(int k) const
	{
		int current = k;
		if (current < 0)
		{
			current = -current;
		}
		size_t sum = 0;
		while (current != 0)
		{
			sum += current % 10 * 7;
			current /= 10;
		}
		return sum;
	}

	size_t get_idx(size_t h, size_t current_size) const { return h % current_size; }

	static size_t next_power_of_two(size_t n)
	{
		size_t p = 1;
		while (p < n)
			p <<= 1;
		return p;
	}

	void rehash()
	{
		size = size * 2;
		std::vector< std::pair< Node, int > > hash_table_new(size, { Node(), 0 });

		for (auto i = hash_table.begin(); i < hash_table.end(); i++)
		{
			if (i->second == 1)
			{
				for (size_t j = 0; j < size; j++)
				{
					size_t idx = get_idx(hash(i->first.key) + (j * j + j) / 2, size);
					if (hash_table_new[idx].second == 0)
					{
						hash_table_new[idx].first = std::move(i->first);
						hash_table_new[idx].second = 1;
						break;
					}
				}
			}
		}
		hash_table = std::move(hash_table_new);
	}

	void rehash_tombstone()
	{
		std::vector< std::pair< Node, int > > hash_table_new(size, { Node(), 0 });
		for (auto i = hash_table.begin(); i < hash_table.end(); i++)
		{
			if (i->second == 1)
			{
				for (size_t j = 0; j < size; j++)
				{
					size_t idx = get_idx(hash(i->first.key) + (j * j + j) / 2, size);
					if (hash_table_new[idx].second == 0)
					{
						hash_table_new[idx].second = 1;
						hash_table_new[idx].first = std::move(i->first);
						break;
					}
				}
			}
		}
		hash_table = std::move(hash_table_new);
		count_t = 0;
	}

  public:
	Hash_Table_Open(size_t s) : size(next_power_of_two(s)), hash_table(next_power_of_two(s), { Node(), 0 }) {}

	bool push(int key, const T& value)
	{
		if (static_cast< double >(count_ + 1) / size > max_load_c)
		{
			rehash();
		}
		if (static_cast< double >(count_t + 1) / size > max_load_t)
		{
			rehash_tombstone();
		}
		bool found_tombstone = false;
		size_t tombstone_idx = 0;

		for (size_t i = 0; i < size; i++)
		{
			size_t idx = get_idx(hash(key) + (i * i + i) / 2, size);
			if (hash_table[idx].second == 1 && hash_table[idx].first.key == key)
			{
				hash_table[idx].first.value = value;
				return true;
			}
			if (hash_table[idx].second == 0)
			{
				if (!found_tombstone)
				{
					hash_table[idx].second = 1;
					hash_table[idx].first.key = key;
					hash_table[idx].first.value = value;
					count_++;
					return true;
				}
				else
				{
					hash_table[tombstone_idx].first.key = key;
					hash_table[tombstone_idx].first.value = value;
					hash_table[tombstone_idx].second = 1;
					count_++;
					count_t--;
					return true;
				}
			}
			if (hash_table[idx].second == 2 && !found_tombstone)
			{
				tombstone_idx = idx;
				found_tombstone = true;
				continue;
			}
		}
		return false;
	}

	bool remove(int k)
	{
		for (size_t j = 0; j < size; j++)
		{
			size_t idx = get_idx(hash(k) + (j * j + j) / 2, size);
			if (hash_table[idx].second == 0)
			{
				return false;
			}
			if (hash_table[idx].second == 1 && hash_table[idx].first.key == k)
			{
				hash_table[idx].first.key = 0;
				hash_table[idx].first.value = T();
				hash_table[idx].second = 2;
				count_--;
				count_t++;
				return true;
			}
		}
		return false;
	}

	bool contains(int k) const
	{
		for (size_t j = 0; j < size; j++)
		{
			size_t idx = get_idx(hash(k) + (j * j + j) / 2, size);

			if (hash_table[idx].second == 0)
				return false;
			if (hash_table[idx].second == 1 && hash_table[idx].first.key == k)
				return true;
		}
		return false;
	}

	T* find(int k)
	{
		for (size_t i = 0; i < size; i++)
		{
			size_t idx = get_idx(hash(k) + (i * i + i) / 2, size);
			if (hash_table[idx].second == 0)
			{
				return nullptr;
			}
			if (hash_table[idx].first.key == k && hash_table[idx].second == 1)
			{
				return &hash_table[idx].first.value;
			}
		}
		return nullptr;
	}
};
