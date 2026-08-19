#include <initializer_list>

#include <algorithm>
#include <iostream>
#include <utility>
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

	Node* find_min_right_side(Node* n)
	{
		Node* current = n->right;
		if (current == nullptr)
		{
			return n;
		}
		while (current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	Color get_color(Node* n) { return (n == nullptr) ? Color::black : n->color; }

	void fix_delete(Node* node, Node* parent)
	{
		while (node != root && parent != nullptr && get_color(node) == Color::black)
		{
			if (node == parent->left)
			{
				Node* brother = parent->right;
				if (get_color(brother) == Color::red)
				{
					brother->color = Color::black;
					parent->color = Color::red;
					left_rotate(parent);
					brother = parent->right;
				}
				Color brother_left_color = (brother != nullptr) ? get_color(brother->left) : Color::black;
				Color brother_right_color = (brother != nullptr) ? get_color(brother->right) : Color::black;

				if (brother_left_color == Color::black && brother_right_color == Color::black)
				{
					if (brother != nullptr)
					{
						brother->color = Color::red;
					}
					node = parent;
					parent = node->parent;
				}
				else
				{
					if (brother_right_color == Color::black)
					{
						if (brother->left != nullptr)
						{
							brother->left->color = Color::black;
						}
						brother->color = Color::red;
						right_rotate(brother);
						brother = parent->right;
					}
					brother->color = parent->color;
					parent->color = Color::black;
					if (brother->right != nullptr)
					{
						brother->right->color = Color::black;
					}
					left_rotate(parent);
					node = root;
				}
			}
			else
			{
				Node* brother = parent->left;
				if (get_color(brother) == Color::red)
				{
					brother->color = Color::black;
					parent->color = Color::red;
					right_rotate(parent);
					brother = parent->left;
				}

				Color brother_left_color = (brother != nullptr) ? get_color(brother->left) : Color::black;
				Color brother_right_color = (brother != nullptr) ? get_color(brother->right) : Color::black;

				if (brother_left_color == Color::black && brother_right_color == Color::black)
				{
					if (brother != nullptr)
					{
						brother->color = Color::red;
					}
					node = parent;
					parent = node->parent;
				}
				else
				{
					if (brother_left_color == Color::black)
					{
						if (brother->right != nullptr)
						{
							brother->right->color = Color::black;
						}
						brother->color = Color::red;
						left_rotate(brother);
						brother = parent->left;
					}
					brother->color = parent->color;
					parent->color = Color::black;
					if (brother->left != nullptr)
					{
						brother->left->color = Color::black;
					}
					right_rotate(parent);
					node = root;
				}
			}
		}

		if (node != nullptr)
		{
			node->color = Color::black;
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

	Node* find(const T& value)
	{
		Node* current = root;
		while (current != nullptr)
		{
			if (current->data < value)
			{
				current = current->right;
			}
			else if (current->data > value)
			{
				current = current->left;
			}
			else
			{
				return current;
			}
		}
		return nullptr;
	}

	void remove(const T& value)
	{
		Node* n = find(value);
		if (n != nullptr)
		{
			if (n->left != nullptr && n->right != nullptr)
			{
				Node* m = find_min_right_side(n);
				std::swap(n->data, m->data);
				n = m;
			}
			Node* child = nullptr;
			if (n->left != nullptr)
			{
				child = n->left;
			}
			if (n->right != nullptr)
			{
				child = n->right;
			}
			Node* parent = n->parent;
			Color removed_color = n->color;
			if (child != nullptr)
			{
				child->parent = parent;
			}
			if (parent == nullptr)
			{
				root = child;
			}
			else if (parent->left == n)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
			delete n;
			size -= 1;

			if (removed_color == Color::red)
			{
				return;
			}
			else
			{
				if (child != nullptr && child->color == Color::red)
				{
					child->color = Color::black;
				}
				else
				{
					fix_delete(child, parent);
				}
			}
		}
	}
};
