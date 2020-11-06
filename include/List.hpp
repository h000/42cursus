#ifndef LIST_HPP
# define LIST_HPP

#include "Utils.hpp"
#include "Iterator.hpp"

namespace ft
{
    template <class T>
	class ListIterator : public std::iterator<bidirectional_iterator_tag, T>
	{
		private:
			Node<T>*	_ptr;
		public:
			ListIterator(void) {}
			virtual ~ListIterator(void) {}
			ListIterator(Node<T>* ptr) : _ptr(ptr) {}
			ListIterator(const ListIterator& other)
			{
				*this = other;
			}
			ListIterator&	operator=(const ListIterator& other)
			{
				_ptr = other._ptr;
				return (*this);
			}
			ListIterator&	operator++(void)
			{
				if (_ptr && _ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			ListIterator	operator++(int)
			{
				ListIterator	tmp(*this);
				this->operator++();
				return (tmp);
			}
			ListIterator&	operator--(void)
			{
				if (_ptr && _ptr->prev)
					_ptr = _ptr->prev;
				return (*this);
			}
			ListIterator	operator--(int)
			{
				ListIterator	tmp(*this);
				this->operator--();
				return (tmp);
			}
			bool	operator==(const ListIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool	operator!=(const ListIterator &other) const
			{
				return (_ptr != other._ptr);
			}
			T&	operator*(void)
			{
				return (_ptr->data);
			}
			T*	operator->(void)
			{
				return (&(_ptr->data));
			}
			Node<T>	*getPtr(void)
			{
				return (_ptr);
			}
	};

	template <typename T, typename Alloc = std::allocator<T> >
	class List
	{
		private:
			typedef typename Alloc::template rebind<Node<T>>::other node_alloc;
			
			Node<T>*	_head;
			Node<T>*	_tail;
			size_t		_size;
			Alloc		_alloc;

			Node<T>*	create_node(Node<T>* prev, Node<T>* next, T data)
			{
				Node<T>	tmp;
				Node<T>	*n;
				
				tmp.next = next;
				tmp.prev = prev;
				tmp.data = data;
				
				n = node_alloc(_alloc).allocate(1);
				node_alloc(_alloc).construct(n, tmp);
				return (n);
			}
			void		delete_node(Node<T>* node)
			{
				node_alloc(_alloc).destroy(node);
				node_alloc(_alloc).deallocate(node, 1);
				node = nullptr;
			}
        public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef ListIterator<T>					iterator;
			typedef ListIterator<const T>			const_iterator;
			typedef ReverseIterator<iterator>		reverse_iterator;
			typedef ReverseIterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t					difference_type;
			typedef size_t							size_type;

			explicit List(const allocator_type& alloc = allocator_type())
			: _head(nullptr), _tail(nullptr), _size(0), _alloc(alloc)
			{
				_tail = create_node(nullptr, nullptr, 0);
				_head = _tail;
			}
			explicit List(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _head(nullptr), _tail(nullptr), _size(0), _alloc(alloc)
			{
				_tail = create_node(nullptr, nullptr, 0);
				_head = _tail;

				insert(_tail, n, val);
			}
			template <class InputIterator>
			List(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _head(nullptr), _tail(nullptr), _size(0), _alloc(alloc)
			{
				_tail = create_node(nullptr, nullptr, 0);
				_head = _tail;

				insert(_tail, first, last);
			}
			List(const List& other)
			: _head(nullptr), _tail(nullptr), _size(0)
			{
				*this = other;
			}
			~List(void)
			{
				if (_size)
					clear();
				if (_tail)
					delete_node(_tail);
			}
			List&	operator=(const List<T>& other)
			{
				//깊은 복사 -double free날 수 있음
				_alloc = other._alloc;
				if (_size != 0)
					clear();
				if (!_tail)
				{
					_tail = create_node(nullptr, nullptr, 0);
					_head = _tail;
				}
				if (other._size)
					insert(end(), other.begin(), other.end());
				return (*this);
			};
			iterator				begin(void)
			{
				return (iterator(_head));
			}
			const_iterator			begin(void) const
			{
				return (const_iterator((Node<const T>*)_head));
			}
			iterator				end(void)
			{
				return (iterator(_tail)); //_tail은 마지막 요소(문자열끝의 널같은거)
			}
			const_iterator			end(void) const
			{
				return (const_iterator((Node<const T>*)_tail));
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator		rend(void)
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}
			bool	empty(void) const
			{
				return (_size == 0);
			}
			size_type	size(void) const
			{
				return (_size);
			}
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(Node<T>));
			}
			reference	front(void)
			{
				return (_head->data);
			}
			const_reference	front(void) const
			{
				return (_head->data);
			}
			reference	back(void)
			{
				return (_tail->prev->data);
			}
			const_reference	back(void) const
			{
				return (_tail->prev->data);
			}
			template <class InputIterator>
 			void	assign(InputIterator first, InputIterator last)
			{
				//first부터 last까지 차례로 리스트에 넣기
				if (_size)
					clear();
				insert(end(), first, last);
			}
			void	assign(size_type n, const value_type& val)
			{
				//val의 카피로 초기화사킨 새 contents n개 넣기
				if (_size)
					clear();
				insert(end(), n, val);
			}
			void	push_front(const value_type& val)
			{
				//맨 앞에 새로운 node 추가
				Node<T>	*node;
				node = create_node(nullptr, _head, val);

				_head->prev = node;
				_head = node;
				_size += 1;
			}
			void	pop_front()
			{
				//맨 앞에 노드 제거
				if (_head == _tail)
					return ;
				Node<T> *tmp;
				tmp = _head;
				_head = _head->next;
				delete_node(tmp);
				--_size;
			}
			void	push_back(const value_type& val)
			{
				//맨 뒤에 노드 추가
				Node<T>	*node;
				node = create_node(_tail->prev, _tail, val);

				if (_size != 0)
					_tail->prev->next = node;
				else
					_head = node;
				_tail->prev = node;
				_size += 1;
			}
			void	pop_back()
			{
				//맨 뒤에 노드 제거
				if (_head == _tail)
					return ;
				Node<T> *tmp;
				tmp = _tail->prev;
				_tail->prev = tmp->prev;
				if (tmp->prev != nullptr)
					tmp->prev->next = _tail;
				else
					_head = _tail;
				delete_node(tmp);
				--_size;
			}
			iterator insert(iterator position, const value_type& val)
			{
				//특정 위치 앞에 노드 추가
				insert(position, (size_type)1, val);
				return (position.getPtr()->prev);
			}
			void	insert(iterator position, size_type n, const value_type& val)
			{
				//특정 위치 앞에 n개 만큼 노드 추가
				//position 이 NULL이면? & 그 밖에 예외?
				Node<T>	*tmp;

				size_type i = 0;
				if (_size == 0)
				{
					push_back(val);
					i += 1;
				}
				if (position == begin())
				{
					push_front(val);
					i += 1;
				}
				tmp = position.getPtr()->prev;
				while (i++ < n)
				{
					Node<T>	*node;
					node = create_node(tmp, tmp->next, val);
;
					tmp->next = node;
					node->next->prev = node;
					++_size;
					tmp = node;
				}
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				Node<T>	*tmp;

				if (_size == 0)
				{
					push_back(*first++);
					// ++first;
				}
				if (position == begin())
				{
					push_front(*first++);
					// ++first;
				}
				tmp = position.getPtr()->prev;
				for (InputIterator it = first; it != last; ++it)
				{
					Node<T>	*node;
					node = create_node(tmp, tmp->next, *it);

					tmp->next = node;
					node->next->prev = node;
					++_size;
					tmp = node;
				}
			}
			iterator erase(iterator position)
			{
				// position을 지움
				if (position == begin())
				{
					pop_front();
					return (begin());
				}
				if (position == end())
					return (end());
				Node<T> *tmp, *res;
				tmp = position.getPtr();
				res = tmp->next;
				tmp->prev->next = res;
				res->prev =tmp->prev;
				delete_node(tmp);
				--_size;
				return (res);
			}
			iterator erase(iterator first, iterator last)
			{
				// first부터 last까지 지움
				Node<T>	*tmp = first.getPtr();
				iterator it = first;

				while (it++ != last)
				{
					if (tmp == _head)
						_head = tmp->next;
					else
						tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					delete_node(tmp);
					--_size;
					tmp = it.getPtr();
				}
				return (tmp);
			}
			void swap(List& x)
			{
				std::swap(_head, x._head);
				std::swap(_tail, x._tail);
				std::swap(_size, x._size);
			}
			void resize(size_type n, value_type val = value_type())
			{
				//size가 n이 됨 (size가 n보다 크면 앞 n개만 가져오고 나머진 지우고
				//n보다 작으면 뒤에 val로 채움)
				while (_size > n)
					pop_back();
				while (_size < n)
					push_back(val);
			}
			void clear()
			{
				erase(begin(), end());
			}
			void splice(iterator position, List& x)
			{
				Node<T>*	pos = position.getPtr();

				if (position == begin())
					_head = x._head;
				else
				{
					x._head->prev = pos->prev;
					pos->prev->next = x._head;
				}
				pos->prev = x._tail->prev;
				x._tail->prev->next = pos;
				_size += x._size;

				x._tail->prev = nullptr;
				x._head = x._tail;
				x._size = 0;
			}
			void splice(iterator position, List& x, iterator i)
			{
				Node<T>*	pos = position.getPtr();
				Node<T>*	tmp = i.getPtr();

				if (i != x.begin())
					tmp->prev->next = tmp->next;
				else
					x._head = tmp->next;
				tmp->next->prev = tmp->prev;
				--x._size;

				if (position != begin())
					pos->prev->next = tmp;
				else
					_head = tmp;
				tmp->prev = pos->prev;
				pos->prev = tmp;
				tmp->next = pos;
				++_size;
			}
			void splice(iterator position, List& x, iterator first, iterator last)
			{
				Node<T>*	pos = position.getPtr();
				Node<T>*	start = first.getPtr();
				Node<T>*	end = last.getPtr()->prev;

				if (first != x.begin())
					start->prev->next = end->next;
				else
					x._head = end->next;
				end->next->prev = start->prev;

				if (position != begin())
					pos->prev->next = start;
				else
					_head = start;
				start->prev = pos->prev;
				pos->prev = end;
				end->next = pos;

				for (iterator it = first; it != last; ++it)
				{
					_size += 1;
					x._size -= 1;
				}
			}
			void remove (const value_type& val)
			{
				iterator it = begin();
				while (it != end())
				{
					if (*it == val)
						it = erase(it);
					else
						++it;
				}
			}
			template <class Predicate>
			void remove_if (Predicate pred)
			{
				iterator it = begin();
				while (it != end())
				{
					if (pred(*it))
						it = erase(it);
					else
						++it;
				}
			}
			void unique()
			{
				// 중복되는 거 x
				iterator 	first = begin();
				while (first != end())
				{
					iterator	second = first;
					++second;
					while (second != end())
					{
						if (*second == *first)
							second = erase(second);
						else
							++second;
					}
					++first;
				}
			}
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				// binar_pred(*first, *second) == 1 이면 삭제
				iterator 	first = begin();
				while (first != end())
				{
					iterator	second = first;
					++second;
					while (second != end())
					{
						if (binary_pred(*first, *second))
							second = erase(second);
						else
							++second;
					}
					++first;
				}
			}
			void merge (List& x)
			{
				// 리스트 x 삭제 & x에 있는 요소들을 ordered position으로 삽입
				if (&x == this)
					return ;
				iterator	first = begin();
				iterator	second = x.begin();

				while (second != x.end())
				{
					if (first == end() || *first > *second)
					{
						insert(first, *second);
						++second;
					}
					else
						++first;
				}
				x.clear();
			}
			template <class Compare>
 			void merge (List& x, Compare comp)
			{
				if (&x == this)
					return ;
				iterator	first = begin();
				iterator	second = x.begin();

				while (second != x.end())
				{
					if (first == end() || comp(*second, *first))
					{
						insert(first, *second);
						++second;
					}
					else
						++first;
				}
				x.clear();
			}
			void sort()
			{
				iterator 	first = begin();
				while (first != end())
				{
					iterator	second = first;
					++second;
					while (second != end())
					{
						if (*first > *second)
							std::swap(*first, *second);
						++second;
					}
					++first;
				}
			}
			template <class Compare>
			void sort (Compare comp)
			{
				iterator 	first = begin();
				while (first != end())
				{
					iterator	second = first;
					++second;
					while (second != end())
					{
						if (!comp(*first, *second))
							std::swap(*first, *second);
						++second;
					}
					++first;
				}
			}
			void reverse()
			{
				iterator	first = begin();
				iterator	last = end();
				--last;

				for (unsigned int i = 0; i < _size / 2; ++i)
				{
					std::swap(*first, *last);
					++first;
					--last;
				}
			}
    };

	template <class T, class Alloc>
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		typename List<T, Alloc>::const_iterator	l_it = lhs.begin();
		typename List<T, Alloc>::const_iterator	r_it = rhs.begin();
		for (unsigned int i = 0; i < lhs.size(); ++i)
		{
			if (*l_it != *r_it)
				return (false);
			++l_it;
			++r_it;
		}
		return (true);
	}
	template <class T, class Alloc>
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		//behave as if using algorithm "lexicographical_compare"
		typename List<T, Alloc>::const_iterator	l_it = lhs.begin();
		typename List<T, Alloc>::const_iterator	r_it = rhs.begin();

		for (; (l_it != lhs.end()) && (r_it != rhs.end()); ++l_it, ++r_it)
		{
			if (*l_it < *r_it)
				return true;
			if (*r_it < *l_it)
				return false;
		}
		// lhs가 먼저 끝났으면 rhs보다 더 작고 나머지 경우는 작지 않으므로
		return (l_it == lhs.end() && r_it != rhs.end());
	}
	template <class T, class Alloc>
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
 	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void swap (List<T,Alloc>& x, List<T,Alloc>& y)
	{
		x.swap(y);
	}
};




#endif