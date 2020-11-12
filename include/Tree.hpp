#ifndef TREE_HPP
# define TREE_HPP

#include "Utils.hpp"

namespace ft
{
	enum Color{RED, BLACK};

	template<class pair>
	struct  Node
	{
		pair		data;
		Node*		left;
		Node*		right;
		Node*		parent;
		enum Color	color;
	};

	template<class Key, class T, class Compare, class Alloc>
	class	RedBlackTree
	{
		private:
			typedef	std::pair<Key, T>	pair;
			typedef typename Alloc::template rebind<Node<pair> >::other node_alloc;
			
			Node<pair>*	_root;
			Node<pair>*	_head;
			Node<pair>*	_tail;

			Compare	_comp;
			Alloc	_alloc;

			RedBlackTree();
			Node<pair>*	create_node(pair data, Node<pair>* left, Node<pair>* right, Node<pair>* parent, enum Color color)
			{
				Node<pair>	tmp;
				Node<pair>*	n;
				
				tmp.data = data;
				tmp.left = left;
				tmp.right = right;
				tmp.parent = parent;
				tmp.color = color;
				
				n = node_alloc(_alloc).allocate(1);
				node_alloc(_alloc).construct(n, tmp);
				return (n);
			}
			void		delete_node(Node<pair>* node)
			{
				node_alloc(_alloc).destroy(node);
				node_alloc(_alloc).deallocate(node, 1);
				node = nullptr;
			}
			void		rotate_right(Node<pair>* node)
			{
				// node와 node->left를 바꿈
				Node<pair>*	tmp = node->left;
				Node<pair>*	p = node->parent;

				if (tmp->right != NULL)
					tmp->right->parent = node;
				node->left = tmp->right;
				node->parent = tmp;
				tmp->right = node;
				tmp->parent = p;

				if (p != NULL)
				{
					if (p->right == node)
						p->right = tmp;
					else
						p->left = tmp;
				}
			}
			void		rotate_left(Node<pair>* node)
			{
				// node와 node->right를 바꿈
				Node<pair>*	tmp = node->right;
				Node<pair>*	p = node->parent;

				if (tmp->left != NULL)
					tmp->left->parent = node;
				node->right = tmp->left;
				node->parent = tmp;
				tmp->left = node;
				tmp->parent = p;

				if (p != NULL)
				{
					if (p->left == node)
						p->left = tmp;
					else
						p->right = tmp;
				}
			}
			Node<pair>*	grandparent(Node<pair>* node)
			{
				if ((node != NULL) && (node->parent != NULL))
					return node->parent->parent;
				else
					return NULL;
			}

			Node<pair>*	uncle(Node<pair>* node)
			{
				Node<pair>* g = grandparent(node);
				if (g == NULL)
					return NULL; // No grandparent means no uncle
				if (node->parent == g->left)
					return g->right;
				else
					return g->left;
			}
			Node<pair>*	insert_node(Node<pair>* node, Node<pair>* parent, const std::pair<Key, T> &data)
			{
				if (node == nullptr || node->data == NULL)
				{
					node = create_node(data, nullptr, nullptr, parent, RED);
					if (parent == nullptr && _root == nullptr)
						_root = node;
				}
				else if (_comp(data.first, node->data.first)) // data.first(Key)가 root의 Key 보다 작으면 왼쪽에 삽입
					node->left = insert_node(node->left, node, data);
				else if (_comp(node->data.first, data.first)) // 크면 오른쪽에 삽입
					node->right = insert_node(node->right, node, data);
				else
					throw std::range_error("Duplicate");
				return (node);
			}
			void	check_node(Node<pair>* node)
			{
				if (node->parent == nullptr)
					node->color = BLACK;
				else if (node->parent->color == RED)
				{
					Node<pair>*	u = uncle(node);
					Node<pair>*	g = grandparent(node);

					if ((u != nullptr) && (u->color == RED))
					{
						// uncle node도 RED면 p,u,g의 색을 바꾼다. (recoloring)
						node->parent->color = BLACK;
						u->color = BLACK;
						g->color = RED; //루트에서부터 모든 리프 노드 사이 존재하는 검은 노드 수가 같아야 하므로 
						check_node(g); //만약 g가 루트면 BLACK이 되어야 하고, g의 부모도 RED이면 조건 위배로 바뀌어야 하기 때문에 다시 체크해준다.
					}
					else
					{
						// uncle node가 BLACK -> restructuring (node parent와 node를 바꿈)
						if (node == node->parent->right && node->parent == g->left)
						{
							//node가 parent의 오른쪽에 있고 parent가 grandparent의 왼쪽일 때
							rotate_left(node->parent);
							node = node->left; //node = 원래 부모
						}
						else if ((node == node->parent->left) && (node->parent == g->right))
						{
							rotate_right(node->parent);
							node = node->right; // node = 원래 부모
						}
						//회전한 다음, 부모였던 노드 처리 (아직 RED node 이므로)
						//현재 node(원래 부모), parent(원래 자식)은 RED, uncle은 BLACK
						//parent->BLACK, grandparent->RED 하고 grandparent와 parent 바꾸기(rotation)
						node->parent->color = BLACK;
						g->color = RED;
						if (node == node->parent->left)
							rotate_right(g);
						else
							rotate_left(g);
					}
				}
			}
		public:
			RedBlackTree(Compare comp, Alloc alloc)
			: _root(nullptr), _head(nullptr), _tail(nullptr), _comp(comp), _alloc(alloc) {}
			// template <class InputIterator>
			// RedBlackTree(InputIterator first, InputIterator last, const Compare, const Alloc)
			// : _root(nullptr), _comp(comp), _alloc(alloc)
			// {
				
			// }
			~RedBlackTree(){}
			RedBlackTree(const RedBlackTree &x)
			: _root(nullptr)
			{
				*this = x;
			}
			RedBlackTree&	operator=(const RedBlackTree &x)
			{
				// clear();
				// insert(begint(), end());
			}
			Node<pair>*	insert(Node<pair>* node, const pair &data)
			{
				if (node != nullptr)
					insert_node(node, node->parent, data);
				else
					insert_node(nullptr, nullptr, data);
				check_node(node);
				
				if (_head && _comp(data, _head->data))
					_head = node;
				if (_tail && _comp(_tail->data, data))
					_tail = node;
			}
			Node<pair>*	begin()
			{
				// Node<pair>*	min = _root;
				// while (min && min->left)
				// 	min = min->left;
				return (_head);
			}
			Node<pair>*	end()
			{
				// Node<pair>*	max = _root;
				// while (max && max->right)
				// 	max = max->right;
				return (_tail);
			}
			Node<pair>*	root()
			{
				return (_root);
			}
			Node<pair>*	find(const Key& k)
			{
				Node<pair>* node;

				node = _root;
				while (node)
				{
					if (k == node->data.first)
						return (node);
					else if (_comp(k, node->data.first)) //k가 더 작으면
						node = node->left;
					else
						node = node->right;
				}
				return (end());
			}
	};

	
}


#endif