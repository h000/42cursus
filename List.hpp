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
			return (this);
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
			return (this);
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
	};

    template <typename T, typename Alloc = std::allocator<T> >
    class List
    {
		private:
			Node<T>		*_head;
			Node<T>		*_tail;
			size_type	_size;
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

			explicit List() : _head(nullptr), _tail(nullptr), _size(0) {}
			explicit List(size_type n, const value_type& val = value_type())
			: _head(nullptr), _tail(nullptr), _size(0)
			{
				
			}
			template <class InputIterator>
			List(InputIterator first, InputIterator last);
			List(const List& other)
			{
				*this = other;
			}
			~List(void) {};
			List&	operator=(const List<T>& other)
			{
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
				return (iterator(_tail));
			}
			const_iterator			end(void) const
			{
				return (iterator(_tail));
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(_tail));
			}
			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator(_tail));
			}
			reverse_iterator		rend(void)
			{
				return (reverse_iterator(_head));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_head));
			}
			bool	empty(void) const {}
			size_type	size(void) const {}
			size_type	max_size(void) const {}
			reference	front(void);
			const_reference	front(void) const;
			reference	back(void);
			const_reference	back(void) const;
			template <class InputIterator>
 			void	assign (InputIterator first, InputIterator last);
			void	assign (size_type n, const value_type& val);
			void	push_front (const value_type& val);
			void pop_front();
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
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