#include <initializer_list>

#include <algorithm>
#include <iostream>
#include <vector>

enum class Color
{
	red = 1,
	black = 0
};

template< typename T >
class RB_Tree
{
  private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node* parent;
		Color color;
		Node(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr), color(Color::red) {}
	};

	size_t size = 0;
	Node* root = nullptr;

	void right_rotate(Node* node)
	{
		Node* x = node->left;
		node->left = x->right;
		if (x->right != nullptr)
		{
			x->right->parent = node;
		}
		x->parent = node->parent;
		if (node->parent == nullptr)
		{
			root = x;
		}
		else if (node == node->parent->left)
		{
			node->parent->left = x;
		}
		else
		{
			node->parent->right = x;
		}
		x->right = node;
		node->parent = x;
	}

	void left_rotate(Node* node)
	{
		Node* x = node->right;
		node->right = x->left;
		if (x->left != nullptr)
		{
			x->left->parent = node;
		}
		x->parent = node->parent;
		if (node->parent == nullptr)
		{
			root = x;
		}
		else if (node == node->parent->right)
		{
			node->parent->right = x;
		}
		else
		{
			node->parent->left = x;
		}
		x->left = node;
		node->parent = x;
	}

	void fix_insert(Node* node)
	{
		while (node != root && node->parent != nullptr && node->parent->color == Color::red)
		{
			Node* grandfather = node->parent->parent;

			if (node->parent == grandfather->left)
			{
				Node* uncle = grandfather->right;
				if (uncle != nullptr && uncle->color == Color::red)
				{
					node->parent->color = Color::black;
					uncle->color = Color::black;
					grandfather->color = Color::red;
					node = grandfather;
				}
				else
				{
					if (node == node->parent->right)
					{
						node = node->parent;
						left_rotate(node);
					}
					node->parent->color = Color::black;
					grandfather->color = Color::red;
					right_rotate(grandfather);
				}
			}
			else
			{
				Node* uncle = grandfather->left;
				if (uncle != nullptr && uncle->color == Color::red)
				{
					node->parent->color = Color::black;
					uncle->color = Color::black;
					grandfather->color = Color::red;
					node = grandfather;
				}
				else
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						right_rotate(node);
					}
					node->parent->color = Color::black;
					grandfather->color = Color::red;
					left_rotate(grandfather);
				}
			}
		}

		root->color = Color::black;
	}

	void clear_subtree(Node* node)
	{
		if (node != nullptr)
		{
			clear_subtree(node->left);
			clear_subtree(node->right);
			delete node;
		}
	}

  public:
	RB_Tree() = default;
	RB_Tree(const RB_Tree&) = delete;
	RB_Tree& operator=(const RB_Tree&) = delete;

	~RB_Tree() { clear_subtree(root); }

	size_t get_size() const { return size; }

	void insert(const T& data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
			root->color = Color::black;
			size = 1;
			return;
		}

		Node* current = root;
		while (true)
		{
			if (data < current->data)
			{
				if (current->left == nullptr)
				{
					Node* n = new Node(data);
					n->parent = current;
					current->left = n;
					size += 1;
					fix_insert(n);
					break;
				}
				current = current->left;
			}
			else if (data > current->data)
			{
				if (current->right == nullptr)
				{
					Node* n = new Node(data);
					n->parent = current;
					current->right = n;
					size += 1;
					fix_insert(n);
					break;
				}
				current = current->right;
			}
			else
			{
				return;
			}
		}
	}
};
