#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Utils.hpp"
#include "Iterator.hpp"

namespace ft
{
	template <class T, class Category = random_access_iterator_tag>
	class VectorIterator
	{
		private:
			
		public:
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef Category		iterator_category;
	
		VectorIterator(void);
		virtual ~VectorIterator(void);
		VectorIterator(Node<T>* ptr);
		VectorIterator(const VectorIterator& other);
		VectorIterator&	operator=(const VectorIterator& other);
		bool	operator==(const VectorIterator &other) const;
		bool	operator!=(const VectorIterator &other) const;
		T&	operator*(void);
		//	*a = t
		T*	operator->(void);
		VectorIterator&	operator++(void);
		VectorIterator	operator++(int);
		VectorIterator&	operator--(void);
		VectorIterator	operator--(int);
		//+, -, <, >, <=, >=, +=, -=, a[n] 추가 구현 필요
	};

	template <class T, class Alloc = allocator<T> >
	class Vector
	{
		private:

		public:
			typedef T		value_type;
			typedef Alloc	allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef VectorIterator<T>				iterator;
			typedef VectorIterator<const T>			const_iterator;
			typedef ReverseIterator<iterator>		reverse_iterator;
			typedef ReverseIterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t					difference_type;
			typedef size_t							size_type;

			explicit Vector (const allocator_type& alloc = allocator_type())
			{

			}	
			explicit Vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			{

			}	
			template <class InputIterator>
			Vector (InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type())
			{

			}	
			Vector (const vector& x)
			{

			}

			Vector&	operator=(const Vector<T>& other)
			{
				_head = other._head;
				_tail = other._tail;
				_size = other._size;
				return (*this);
			};
			iterator				begin(void)
			{
				return (iterator());
			}
			const_iterator			begin(void) const
			{
				return (const_iterator());
			}
			iterator				end(void)
			{
				return (iterator());
			}
			const_iterator			end(void) const
			{
				return (iterator());
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator());
			}
			const_reverse_iterator	rbegin() const
			{
				return (const_reverse_iterator());
			}
			reverse_iterator		rend(void)
			{
				return (reverse_iterator());
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator());
			}

			size_type	size(void) const {}
			size_type	max_size(void) const {}
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool	empty(void) const {}
			void reserve (size_type n);
			
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference	back(void);
			const_reference	back(void) const;

			template <class InputIterator>
 			void	assign (InputIterator first, InputIterator last);
			void	assign (size_type n, const value_type& val);
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (Vector& x);
			void clear();
	};
	template <class T, class Alloc>
	bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
	template <class T, class Alloc>
 	bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs);
	template <class T, class Alloc>
	void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y);


	//이건 뭐? vector<bool>
		// template < class T, class Alloc = allocator<T> >
		// class vector; // generic template
		// template <class Alloc>
		// class vector<bool,Alloc>;  // bool specialization
}

#endif