#include <initializer_list>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template< typename V >
class HashTableClose
{
  private:
	size_t m;
	size_t count_ = 0;
	static constexpr double max_load = 0.75;

	struct Hash_Node
	{
		int key;
		V value;
		Hash_Node(int k, V val) : key(k), value(val) {}
	};
	std::vector< std::vector< Hash_Node > > hash_table;
	size_t hash1(int k) const
	{
		uint32_t key = static_cast< uint32_t >(k);
		if (key < 0)
		{
			key = ~key + 1;
		}

		if (key == 0)
		{
			return 0;
		}
		long long sum = 0;
		while (key != 0)
		{
			sum += (key % 10) * 13;
			key /= 10;
		}
		return sum;
	}

	size_t get_idx(size_t h, size_t table_size) const { return h % table_size; }

	void rehash()
	{
		size_t new_m = m * 2;
		std::vector< std::vector< Hash_Node > > new_table(new_m);
		for (auto& bucket : hash_table)
		{
			for (auto& node : bucket)
			{
				size_t idx = get_idx(hash1(node.key), new_m);
				new_table[idx].push_back(std::move(node));
			}
		}
		hash_table = std::move(new_table);
		m = new_m;
	}

  public:
	explicit HashTableClose(size_t size = 11) : hash_table(size), m(size) {};

	void push(int key, const V& value)
	{
		if (static_cast< double >(count_ + 1) / m > max_load)
		{
			rehash();
		}
		auto& bucket = hash_table[get_idx(hash1(key), m)];

		for (auto& node : bucket)
		{
			if (node.key == key)
			{
				node.value = value;
				return;
			}
		}
		bucket.emplace_back(key, value);
		count_++;
	}

	bool remove(int key)
	{
		auto& bucket = hash_table[get_idx(hash1(key), m)];
		for (auto i = bucket.begin(); i != bucket.end(); i++)
		{
			if (i->key == key)
			{
				*i = std::move(bucket.back());
				bucket.pop_back();
				--count_;
				return true;
			}
		}
		return false;
	}

	bool contains(int key) const
	{
		const auto& bucket = hash_table[get_idx(hash1(key), m)];
		for (const auto& node : bucket)
		{
			if (node.key == key)
			{
				return true;
			}
		}
		return false;
	}

	size_t size() const { return count_; }
	bool empty() const { return count_ == 0; }
};
