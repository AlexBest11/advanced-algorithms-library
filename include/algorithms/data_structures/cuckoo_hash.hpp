#include <initializer_list>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template< typename V >
class HashTableCuckoo
{
  private:
	struct Hash_Node
	{
		int key;
		V value;
		bool reserv;
		Hash_Node(int k, V val) : key(k), value(val), reserv(true) {}
		Hash_Node() : key(0), value(), reserv(false) {}
	};

	std::vector< Hash_Node > table1;
	std::vector< Hash_Node > table2;

	size_t m;
	size_t count_;

	static constexpr double load_factor = 0.5;

	size_t hash1(int k) const
	{
		uint32_t key;
		if (k < 0)
		{
			key = ~static_cast< uint32_t >(k) + 1;
		}
		else
		{
			key = static_cast< uint32_t >(k);
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

	size_t hash2(int k) const
	{
		uint32_t key;
		if (k < 0)
		{
			key = ~static_cast< uint32_t >(k) + 1;
		}
		else
		{
			key = static_cast< uint32_t >(k);
		}

		if (key == 0)
		{
			return 1;
		}
		long long sum = 0;
		while (key != 0)
		{
			sum += (key % 10) * 17;
			key /= 10;
		}
		return sum + 5;
	}

	size_t get_idx(size_t h, size_t table_size) const { return h % table_size; }

	void rehash()
	{
		std::vector< Hash_Node > old_nodes;
		for (const auto& node : table1)
		{
			if (node.reserv == true)
			{
				old_nodes.push_back(node);
			}
		}
		for (const auto& node : table2)
		{
			if (node.reserv == true)
			{
				old_nodes.push_back(node);
			}
		}
		table1.clear();
		table2.clear();
		m = m * 2;
		table1.resize(m);
		table2.resize(m);
		count_ = 0;
		for (const auto& node : old_nodes)
		{
			push(node.key, node.value);
		}
	}

  public:
	HashTableCuckoo(size_t s) : table1(s), table2(s), m(s), count_(0) {}

	void push(int k, V val)
	{
		int temp_key = k;
		V temp_val = val;
		bool can_put_table = false;

		size_t check_idx1 = get_idx(hash1(temp_key), m);
		if (table1[check_idx1].reserv && table1[check_idx1].key == temp_key)
		{
			table1[check_idx1].value = temp_val;
			return;
		}
		size_t check_idx2 = get_idx(hash2(temp_key), m);
		if (table2[check_idx2].reserv && table2[check_idx2].key == temp_key)
		{
			table2[check_idx2].value = temp_val;
			return;
		}

		if (static_cast< double >(count_ + 1) / (m * 2) > load_factor)
		{
			rehash();
		}

		for (int i = 0; i < 50; i++)
		{
			if (can_put_table == false)
			{
				size_t idx1 = get_idx(hash1(temp_key), m);
				if (table1[idx1].reserv == false)
				{
					Hash_Node n(temp_key, temp_val);
					table1[idx1] = n;
					count_++;
					return;
				}
				else
				{
					Hash_Node n = table1[idx1];
					Hash_Node n1(temp_key, temp_val);
					temp_key = n.key;
					temp_val = n.value;
					table1[idx1] = n1;
					can_put_table = true;
					continue;
				}
			}
			if (can_put_table == true)
			{
				size_t idx2 = get_idx(hash2(temp_key), m);
				if (table2[idx2].reserv == false)
				{
					Hash_Node n(temp_key, temp_val);
					table2[idx2] = n;
					count_++;
					return;
				}
				else
				{
					Hash_Node n = table2[idx2];
					Hash_Node n1(temp_key, temp_val);
					temp_key = n.key;
					temp_val = n.value;
					table2[idx2] = n1;
					can_put_table = false;
					continue;
				}
			}
		}

		rehash();
		push(temp_key, temp_val);
	}

	V* find(int k)
	{
		size_t idx1 = get_idx(hash1(k), m);
		size_t idx2 = get_idx(hash2(k), m);

		if (table1[idx1].reserv && table1[idx1].key == k)
		{
			return &table1[idx1].value;
		}
		if (table2[idx2].reserv && table2[idx2].key == k)
		{
			return &table2[idx2].value;
		}

		return nullptr;
	}

	bool erase(int k)
	{
		size_t idx1 = get_idx(hash1(k), m);
		size_t idx2 = get_idx(hash2(k), m);
		if (table1[idx1].reserv && table1[idx1].key == k)
		{
			table1[idx1].reserv = false;
			count_ -= 1;
			return true;
		}
		if (table2[idx2].reserv && table2[idx2].key == k)
		{
			table2[idx2].reserv = false;
			count_ -= 1;
			return true;
		}
		return false;
	}
};
