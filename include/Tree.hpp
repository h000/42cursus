#ifndef TREE_HPP
# define TREE_HPP

#include "Utils.hpp"

namespace ft
{
	enum Color{RED, BLACK};

	template<class Key, class T>
	struct  Node
	{
		std::pair<Key, T>	data;
		Node*		left;
		Node*		right;
		Node*		parent;
		enum Color	color;
	};

	template<class Key, class T>
	class	RedBlackTree<class Key, class T, class Compare, class Alloc>
	{
		private:
			typedef typename Alloc::template rebind<Node<T> >::other node_alloc;
			
			// Node*	_root;
			Alloc	_alloc;

			Node*	create_node(std::pair<Key, T> data, Node<T>* left, Node<T>* right, Node<T>* parent, enum Color	color)
			{
				Node	tmp;
				Node*	n;
				
				tmp.data = data;
				tmp.left = left;
				tmp.right = right;
				tmp.parent = parent;
				tmp.color = color;
				
				n = node_alloc(_alloc).allocate(1);
				node_alloc(_alloc).construct(n, tmp);
				return (n);
			}
			void		delete_node(Node* node)
			{
				node_alloc(_alloc).destroy(node);
				node_alloc(_alloc).deallocate(node, 1);
				node = nullptr;
			}
			void		rotate_right(Node* node)
			{
				// node와 node->left를 바꿈
				Node*	tmp = node->left;
				Node*	p = node->parent;

				if (tmp->right != NULL)
					tmp->right->parent = node;
				node->left = tmp->right;
				node->parent = tmp;
				tmp->right = node;
				tmp->parent = p;

				if (p != NULL)
				{
					if (p->right == node);
						p->right = tmp;
					else
						p->left = tmp;
				}
			}
			void		rotate_left(Node* node)
			{
				// node와 node->right를 바꿈
				Node*	tmp = node->right;
				Node*	p = node->parent;

				if (tmp->left != NULL)
					tmp->left->parent = node;
				node->right = tmp->left;
				node->parent = tmp;
				tmp->left = node;
				tmp->parent = p;

				if (p != NULL)
				{
					if (p->left == node);
						p->left = tmp;
					else
						p->right = tmp;
				}
			}
			Node*	grandparent(Node* node)
			{
				if ((node != NULL) && (node->parent != NULL))
					return node->parent->parent;
				else
					return NULL;
			}

			Node*	uncle(Node* node)
			{
				Node* g = grandparent(n);
				if (g == NULL)
					return NULL; // No grandparent means no uncle
				if (node->parent == g->left)
					return g->right;
				else
					return g->left;
			}
		public:
			Node*	insert_node(Node* node, Node* parent, const std::pair<Key, T> &data)
			{
				if (node == nullptr)
				{
					node = create_node(data, nullptr, nullptr, parent, RED);
					// if (parent == nullptr && _root == nullptr)
					// 	_root = node;
				}
				else if (node->data.first > data.first) // data.first(Key)가 root의 Key 보다 작으면 왼쪽에 삽입
					node->left = insert(node->left, node, data);
				else if (node->data.first < data.first) // 크면 오른쪽에 삽입
					node->right = insert(node->right, node, data);
				else
					throw std::range_error("Duplicate");
				return (node);
			}
			void	check_node(Node* node)
			{
				if (node->parent = nullptr)
					node->color = BLACK;
				else if (node->parent->color == RED)
				{
					Node*	u = uncle(node);
					Node*	g = grandparent(node);

					if ((u != nullptr) && (u->color == RED))
					{
						// uncle node도 RED면 p,u,g의 색을 바꾼다. (recoloring)
						n->parent->color = BLACK;
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
			Node*	insert(Node* node, const std::pair<Key, T> &data)
			{
				insert_node(node, node->parent, data);
				check_node(node);
			}
			
	}

	
}


#endif