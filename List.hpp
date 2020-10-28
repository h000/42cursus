#ifndef LIST_HPP
# define LIST_HPP

#include "Utils.hpp"
#include "Iterator.hpp"

namespace ft
{
    template <class T, class Category = bidirectional_iterator_tag>
	class ListIterator
	{
		protected:
			Node<T>*	_ptr;
		public:
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef Category		iterator_category;
	
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
			Node<T>		*_head;
			Node<T>		*_tail;
			size_t		_size;
        public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference	reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer		pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef ListIterator<T>			iterator;
			typedef ListIterator<const T>	const_iterator;
			typedef ReverseIterator<iterator>	reverse_iterator;
			typedef ReverseIterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t		difference_type;
			typedef size_t				size_type;

			explicit List() : _head(nullptr), _tail(nullptr), _size(0)
			{
				_tail = new Node<T>();
				_tail->next = nullptr;
				_tail->prev = nullptr;
				_tail->data = 0;
				_head = _tail;
			}
			explicit List(size_type n, const value_type& val = value_type())
			: _head(nullptr), _tail(nullptr), _size(0)
			{
				_tail = new Node<T>();
				_tail->next = nullptr;
				_tail->prev = nullptr;
				_tail->data = 0;
				_head = _tail;
				insert(_tail, n, val);
			}
			template <class InputIterator>
			List(InputIterator first, InputIterator last)
			{
				_tail = new Node<T>();
				_tail->next = nullptr;
				_tail->prev = nullptr;
				_tail->data = 0;
				_head = _tail;
				insert(_tail, first, last);
			}
			List(const List& other)
			{
				*this = other;
			}
			~List(void) {};
			List&	operator=(const List<T>& other)
			{
				//깊은 복사 -double free날 수 있음
				// if (_size)
				// // 	clear();
				// if (_tail)
				// 	delete (_tail);
				//////////
				_head = other._head;
				_tail = other._tail;
				_size = other._size;
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
				return (iterator(_tail));
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
			}
			void	assign(size_type n, const value_type& val)
			{
				//val의 카피로 초기화사킨 새 contents n개 넣기
			}
			void	push_front(const value_type& val)
			{
				//맨 앞에 새로운 node 추가
				Node<T>	*node = new Node<T>();
				node->prev = nullptr;
				node->next = _head;
				node->data = val;
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
				delete tmp;
				--_size;
			}
			void	push_back(const value_type& val)
			{
				//맨 뒤에 노드 추가
				Node<T>	*node = new Node<T>();
				if (_size != 0)
					_tail->prev->next = node;
				else
					_head = node;
				node->prev = _tail->prev;
				node->next = _tail;
				node->data = val;
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
				_tail->prev = _tail->prev->prev;
				delete tmp;
				--_size;
			}
			iterator insert(iterator position, const value_type& val)
			{
				//특정 위치 앞에 노드 추가
				insert(position, 1, val);
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
				tmp = position.getPtr()->prev;
				while (i++ < n)
				{
					Node<T>	*node = new Node<T>();
					node->prev = tmp;
					node->next = tmp->next;
					node->data = val;
					tmp->next = node;
					node->next->prev = node;
					++_size;
					tmp = node;
				}
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				Node<T>	*tmp;

				if (_size == 0)
				{
					push_back(*first);
					++first;
				}
				tmp = position.getPtr()->prev;
				for (InputIterator it = first; it != last; ++it)
				{
					Node<T>	*node = new Node<T>();
					node->prev = tmp;
					node->next = tmp->next;
					node->data = *it;
					tmp->next = node;
					node->next->prev = node;
					++_size;
					tmp = node;
				}
			}
			iterator erase (iterator position)
			{
				// position을 지움
				if (position == _tail)
					return ;
				Node<T> *tmp;
				tmp = position;
				position->prev->next = position->next;
				position->next->prev = position->prev;
				delete tmp;
				//굳이 tmp 안만들어도 될듯?
				--_size;
			}
			iterator erase (iterator first, iterator last)
			{
				// first부터 last까지 지움
				Node<T>	*tmp;

				tmp = position.getPtr()->prev;
				for (InputIterator it = first; it != last; ++it)
				{
					if (it == _tail)
						return ;
					Node<T>	*node = new Node<T>();
					node->prev = tmp;
					node->next = tmp->next;
					node->data = *it;
					tmp->next = node;
					node->next->prev = node;
					++_size;
					tmp = node;
				}

			}
			void swap (List& x);
			void resize (size_type n, value_type val = value_type());
			void clear();
			void splice (iterator position, List& x);
			void splice (iterator position, List& x, iterator i);
			void splice (iterator position, List& x, iterator first, iterator last);
			void remove (const value_type& val);
			template <class Predicate>
			void remove_if (Predicate pred);
			void unique();
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred);
			void merge (List& x);
			template <class Compare>
 			void merge (List& x, Compare comp);
			void sort();
			template <class Compare>
			void sort (Compare comp);
			void reverse();




			

			
    };

	template <class T, class Alloc>
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
	template <class T, class Alloc>
 	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);
	template <class T, class Alloc>
	void swap (List<T,Alloc>& x, List<T,Alloc>& y);
}




#endif