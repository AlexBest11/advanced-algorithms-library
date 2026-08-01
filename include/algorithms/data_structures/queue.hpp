#include <iostream>
#include <vector>

template< typename T >

class Queue
{
  private:
	struct Node
	{
		T data;
		Node* next;
		Node(const T& d) : data(d), next(nullptr) {}
		Node(T&& d) : data(std::move(d)), next(nullptr) {}
	};
	Node* tail;
	Node* head;
	size_t size;

  public:
	Queue() : head(nullptr), tail(nullptr), size(0) {}
	~Queue() { clear(); }
	bool empty() const { return head == nullptr; }
	size_t get_size() const { return size; }
	void push(const T& value)
	{
		Node* temp = new Node(value);
		if (empty())
		{
			head = temp;
			tail = temp;
			size++;
		}
		else
		{
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void pop()
	{
		if (empty())
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
		if (head == nullptr)
		{
			tail = nullptr;
		}
	}
	bool top(T& out_value) const
	{
		if (empty())
		{
			return false;
		}
		out_value = head->data;
		return true;
	}
	void clear()
	{
		while (!empty())
		{
			pop();
		}
	}
};
