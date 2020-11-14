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

		Node(pair data, Node* left, Node* right, Node* parent, enum Color color)
		: data(data), right(right), left(left), parent(parent), color(color) {}
	};

	template<class Key, class T, class Compare, class Alloc>
	class	RedBlackTree
	{
		private:
			typedef std::pair<const Key, T>	pair;
			typedef typename Alloc::template rebind<Node<pair> >::other node_alloc;
			
			Node<pair>*	_root;
			Node<pair>*	_head;
			Node<pair>*	_tail;

			Compare	_comp;
			Alloc	_alloc;

			RedBlackTree();
			Node<pair>*	create_node(pair data, Node<pair>* left, Node<pair>* right, Node<pair>* parent, enum Color color)
			{
				Node<pair>	tmp(data, left, right, parent, color);
				Node<pair>*	n;
				
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

				if (node == _root)
					_root = node->left;

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

				if (node == _root)
					_root = node->right;

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
			Node<pair>*	sibling(Node<pair>* node)
			{
				if (node == node->parent->left)
					return node->parent->right;
				else
					return node->parent->left;
			}
			Node<pair>*	insert_node(Node<pair>* node, const std::pair<const Key, T> &data)
			{
				Node<pair>*	p = nullptr;
				while (node != nullptr)
				{
					p = node;
					if (_comp(data.first, node->data.first)) // data.first(Key)가 node의 Key 보다 작으면 왼쪽에 삽입
						node = node->left;
					else if (_comp(node->data.first, data.first)) // 크면 오른쪽에 삽입
						node = node->right;
					else
						throw std::range_error("Duplicate");
				}
				node = create_node(data, nullptr, nullptr, p, RED);
				if (p == nullptr && _root == nullptr)
					_root = node;
				else
				{
					if (_comp(data.first, p->data.first))
						p->left = node;
					else
						p->right = node;
					node->parent = p;
				}
				return (node);
			}
			void	insert_fixup(Node<pair>* node)
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
						insert_fixup(g); //만약 g가 루트면 BLACK이 되어야 하고, g의 부모도 RED이면 조건 위배로 바뀌어야 하기 때문에 다시 체크해준다.
					}
					else
					{
						// uncle node가 BLACK 또는 노드가 없음 -> restructuring (node parent와 node를 바꿈)
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
						//회전한 다음, 부모였던 노드 처리 (아직 RED node 이므로) && 둘 다 right, 둘 다 left 일 때
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
			void	remove_node(Node<pair>* node)
			{
				// if _tail == node ||  _head == node
				Node<pair>* tmp;

				if (!node->left || !node->right)
				{
					tmp = node->left ? node->left : node->right;
					if (tmp != nullptr) //one child
					{
						tmp->parent = node->parent;
						if (node->parent == nullptr)
							_root = tmp;
						else if (node->parent->right == node)
							node->parent->right = tmp;
						else
							node->parent->left = tmp;
					}
					if (node->color == BLACK)
					{
						if (tmp && tmp->color == RED)
							tmp->color == BLACK;
						else
							delete_fixup(tmp);
					}
					delete_node(node);
				}
				else //two children
				{
					tmp = min(node->right); // 원래 노드와 교체할 노드
					//원래 있던 자리 정리
					tmp->parent->left = tmp->right;
					tmp->right->parent = tmp->parent;
					//node 자리로 옮기기
					tmp->parent = node->parent;
					tmp->left = node->left;
					tmp->right = node->right;
					tmp->color = node->color;
					if (node->parent == nullptr)
						_root = tmp;
					else if (node->parent->right == node)
						node->parent->right = tmp;
					else
						node->parent->left = tmp;
					node->left->parent = tmp;
					node->right->parent = tmp;

					delete_node(node);
				}
			}
			void	delete_fixup(Node<pair>* node)
			{
				if (node->parent != nullptr)
				{
					Node<pair>*	s = sibling(node);

					if (s->color == RED)
					{
						node->parent->color = RED;
						s->color = BLACK;
						if (node == node->parent->left)
							rotate_left(node->parent);
						else
							rotate_right(node->parent);
						s = sibling(node);
					}
					if ((node->parent->color == BLACK) && (s->color == BLACK)
					&& (s->left->color == BLACK) && (s->right->color == BLACK))
					{
						s->color = RED;
						delete_fixup(node->parent);
					}
					else
					{
						if (node->parent->color == RED && s->color == BLACK
						&& s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							node->parent->color = BLACK;
						}
						else
						{
							if (s->color == BLACK)
							{
								if (n == n->parent->left && s->left->color == BLACK
								&& s->right->color == BLACK)
								{
									s->color = RED;
									s->right->color = BLACK;
									rotate_left(s);
									s= sibling(n);
								}
							}
							s->color = node->parent->color;
							node->parent->color = BLACK;

							if (node == node->parent->left)
							{
								s->right->color = BLACK;
								rotate_left(node->parent);
							}
							else
							{
								s->left->color = BLACK;
								rotate_right(node->parent);
							}
						}
					}
				}
			}
		public:
			RedBlackTree(const Compare& comp, const Alloc& alloc)
			: _root(nullptr), _head(nullptr), _tail(nullptr), _comp(comp), _alloc(alloc) {}
			~RedBlackTree(){}
			RedBlackTree(const RedBlackTree &x)
			: _root(nullptr), _head(nullptr), _tail(nullptr)
			{
				*this = x;
			}
			RedBlackTree&	operator=(const RedBlackTree &x)
			{
				_root = x._root;
				_head = x._head;
				_tail = x._tail;
				_comp = x._comp;
				_alloc = x._alloc;
			}

			Node<pair>*	begin() const
			{
				return (_head);
			}
			Node<pair>*	end() const
			{
				return (_tail);
			}
			Node<pair>*	root()
			{
				return (_root);
			}

			Node<pair>*	insert(Node<pair>* node, const pair& data)
			{
				node = insert_node(node, data);
				insert_fixup(node);
				if ((_head && _comp(data.first, _head->data.first)) || !_head)
					_head = node;
				if ((_tail && _comp(_tail->data.first, data.first)) || !_tail)
					_tail = node;
				return (node);
			}
			
			void		erase(Node<pair>* node)
			{
				
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
				return (nullptr);
			}

			Node<pair>* min(Node<pair>* root)
			{
				Node<pair>*	min = root;
				while (min && min->left)
					min = min->left;
			}
	};

	
}


#endif