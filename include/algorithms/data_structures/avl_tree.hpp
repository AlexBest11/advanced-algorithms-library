#include <initializer_list>

#include <algorithm>
#include <iostream>
#include <vector>

template< typename T >
class AVL_Tree
{
  private:
	struct Node
	{
		T data;
		int height;
		Node* left;
		Node* right;
		Node(const T& dat) : data(dat), left(nullptr), right(nullptr), height(1) {}
	};

	size_t size;
	Node* root;

	int get_heigh(Node* n) { return n ? n->height : 0; }

	int get_balance(Node* n) { return n ? get_heigh(n->left) - get_heigh(n->right) : 0; }

	void update_height(Node* n)
	{
		if (n)
		{
			n->height = std::max(get_heigh(n->left), get_heigh(n->right)) + 1;
		}
	}

	Node* right_rotate(Node* node)
	{
		Node* y = node->left;
		node->left = y->right;
		y->right = node;

		update_height(node);
		update_height(y);

		return y;
	}

	Node* left_rotate(Node* node)
	{
		Node* y = node->right;
		node->right = y->left;
		y->left = node;

		update_height(node);
		update_height(y);

		return y;
	}

	Node* insert(Node* node, const T& data)
	{
		if (node == nullptr)
		{
			return new Node(data);
		}

		if (data < node->data)
		{
			node->left = insert(node->left, data);
		}
		else if (data > node->data)
		{
			node->right = insert(node->right, data);
		}
		else
		{
			return node;
		}

		update_height(node);

		if (get_balance(node) == 2)
		{
			if (get_balance(node->left) == -1)
			{
				node->left = left_rotate(node->left);
				return right_rotate(node);
			}
			else
			{
				return right_rotate(node);
			}
		}

		if (get_balance(node) == -2)
		{
			if (get_balance(node->right) == 1)
			{
				node->right = right_rotate(node->right);
				return left_rotate(node);
			}
			else
			{
				return left_rotate(node);
			}
		}
		return node;
	}

  public:
	AVL_Tree() : root(nullptr), size(0) {}

	void insert(const T& data)
	{
		root = insert(root, data);
		size++;
	}
};
