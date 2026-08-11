#include <initializer_list>

#include <iostream>
#include <vector>

template< typename T >
class SLList
{
  private:
	struct Node
	{
		T value;
		Node* next;
		Node(T val) : value(val), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	size_t size;

  public:
	SLList() : head(nullptr), tail(nullptr), size(0) {}

	~SLList()
	{
		while (!empty())
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	SLList(std::initializer_list< T > input)
	{
		for (const auto& item : input)
		{
			pushback(item);
		}
	}

	bool empty() { return head == nullptr; }

	void pushback(const T& value)
	{
		Node* n = new Node(value);
		if (empty())
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}
		size++;
	}

	void pushfront(const T& value)
	{
		Node* n = new Node(value);
		if (empty())
		{
			head = n;
			tail = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
		size++;
	}

	void insert_after(const T& value, Node* n)
	{
		if (n->next == nullptr)
		{
			pushback(value);
			return;
		}
		else
		{
			Node* temp = new Node(value);
			temp->next = n->next;
			n->next = temp;
			size++;
		}
	}

	void insert_after(const T& value, const T& input)
	{
		Node* av = head;
		while (av != nullptr)
		{
			if (av->value == input)
			{
				if (av == tail)
				{
					pushback(value);
				}
				else
				{
					Node* ins = new Node(value);
					ins->next = av->next;
					av->next = ins;
					size++;
				}

				av = av->next;
			}

			av = av->next;
		}
	}

	Node* get_tail() { return tail; }

	void popback()
	{
		if (empty())
		{
			return;
		}
		if (size == 1)
		{
			Node* temp = head;
			delete temp;
			head = nullptr;
			tail = nullptr;
			size = 0;
			return;
		}
		Node* av = head;
		while (av->next != tail)
		{
			av = av->next;
		}
		delete av->next;
		tail = av;
		tail->next = nullptr;
		size--;
	}
};
