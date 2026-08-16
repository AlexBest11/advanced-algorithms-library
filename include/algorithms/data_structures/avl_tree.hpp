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

	Node* find_min_in_right_side(Node* node)
	{
		if (node->right != nullptr)
		{
			Node* current = node->right;
			while (current->left != nullptr)
			{
				current = current->left;
			}
			return current;
		}
		return node;
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

	Node* remove(Node* node, const T& data)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (data < node->data)
		{
			node->left = remove(node->left, data);
		}
		else if (data > node->data)
		{
			node->right = remove(node->right, data);
		}
		else
		{
			if (node->left == nullptr || node->right == nullptr)
			{
				Node* current = nullptr;
				if (node->left != nullptr)
				{
					current = node->left;
				}
				else if (node->right != nullptr)
				{
					current = node->right;
				}

				if (current == nullptr)
				{
					current = node;
					node = nullptr;
				}
				else
				{
					Node* temp = node;
					node = current;
					current = temp;
				}
				delete current;
				size--;
			}
			else
			{
				Node* temp = find_min_in_right_side(node);
				node->data = temp->data;
				node->right = remove(node->right, temp->data);
			}
		}
		if (node == nullptr)
			return nullptr;

		update_height(node);

		if (get_balance(node) == 2)
		{
			if (get_balance(node->left) < 0)
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
			if (get_balance(node->right) > 0)
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

	void delete_elem(const T& value)
	{
		if (find(value) != nullptr)
		{
			root = remove(root, value);
		}
	}

	Node* find(const T& elem)
	{
		Node* current = root;
		while (current != nullptr)
		{
			if (current->data == elem)
			{
				return current;
			}
			else if (elem < current->data)
			{
				current = current->left;
			}
			else if (elem > current->data)
			{
				current = current->right;
			}
		}
		return nullptr;
	}

	Node* find_parent(const T& elem)
	{
		Node* current = root;
		Node* parent = nullptr;
		while (true)
		{
			if (current == nullptr)
			{
				return nullptr;
			}
			else if (elem < current->data)
			{
				if (current->left->data == elem)
				{
					parent = current;
					break;
				}
				current = current->left;
			}
			else if (elem > current->data)
			{
				if (current->right->data == elem)
				{
					parent = current;
					break;
				}
				current = current->right;
			}
		}
		return parent;
	}
};
