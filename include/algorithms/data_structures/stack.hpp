#include <iostream>
#include <vector>

template< typename T >

class Stack
{
  private:
	std::vector< T > s;

  public:
	void push(const T &value) { s.push_back(value); }
	void push(T &&value) { s.push_back(std::move(value)); }
	void pop()
	{
		if (!s.empty())
		{
			s.pop_back();
		}
	}
	size_t get_size() const { return s.size(); }
	bool top(T &out_value) const
	{
		if (s.empty())
		{
			return false;
		}
		out_value = s.back();
		return true;
	}
	bool empty() const { return s.empty(); }
};
