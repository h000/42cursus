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
			T*		_ptr;
		public:
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef Category		iterator_category;
	
		VectorIterator(void) : _ptr(nullptr) {}
		virtual ~VectorIterator(void) {}
		VectorIterator(T* ptr) : _ptr(ptr) {}
		VectorIterator(const VectorIterator& other)
		{
			*this = other;
		}
		VectorIterator&	operator=(const VectorIterator& other)
		{
			_ptr = other._ptr;
			return (*this);
		}
		VectorIterator&	operator++(void)
		{
			++_ptr;
			return (*this);
		}
		VectorIterator	operator++(int)
		{
			VectorIterator	tmp(*this);
			this->operator++();
			return (*this);
		}
		VectorIterator&	operator--(void)
		{
			--_ptr;
			return (*this);
		}
		VectorIterator	operator--(int)
		{
			VectorIterator	tmp(*this);
			this->operator--();
			return (*this);
		}
		VectorIterator	&operator+(difference_type n)
		{
			return (VectorIterator(_ptr + n));
		}
		VectorIterator	&operator-(difference_type n)
		{
			return (VectorIterator(_ptr - n));
		}
		VectorIterator	&operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		}
		VectorIterator	&operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}
		bool	operator==(const VectorIterator &other) const
		{
			return (this->_ptr == other._ptr);
		}
		bool	operator!=(const VectorIterator &other) const
		{
			return (this->_ptr != other._ptr);
		}
		bool	operator<(const VectorIterator &other) const
		{
			return (this->_ptr < other._ptr);
		}
		bool	operator>(const VectorIterator &other) const
		{
			return (this->_ptr > other._ptr)
		}
		bool	operator<=(const VectorIterator &other) const
		{
			return (!(this->_ptr > other._ptr));
		}
		bool	operator>=(const VectorIterator &other) const
		{
			return (!(this->_ptr < other._ptr));
		}
		T&	operator*(void)
		{
			return (*this->_ptr);
		}
		T*	operator->(void)
		{
			return (this->_ptr);
		}
		T& operator[](int n)
		{
			return (*(this->ptr_ + n));
		}
	};

	template <class T, class Alloc = allocator<T> >
	class Vector
	{
		private:
			T*		_ptr;
			size_t	_size;
			size_t	_capacity;
			Alloc	_alloc;
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

			explicit Vector(const allocator_type& alloc = allocator_type())
			: _ptr(nullptr), _size(0), _capacity(0)
			{
				//end()를 위해 alloc??
				_ptr = _alloc.allocate(1);
			}	
			explicit Vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _ptr(nullptr), _size(n), _capacity(n)
			{
				_ptr = _alloc.allocate(n + 1);
				for (unsigned int i = 0; i < n; ++ i)
					_alloc.construct(&_ptr[i], var);
			}
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type())
			: _ptr(nullptr), _size(0), _capacity(0)
			{
				_ptr = _alloc.allocate(1);
				insert(end(), first, last);
			}	
			Vector(const Vector& other)
			{
				*this = other;
			}
			~Vector()
			{
				for (unsigned int i = 0; i < _size; ++i)
					alloc_.destroy(*(ptr + i));
				alloc_.deallocate(_ptr, _capacity + 1);
			}
			Vector&	operator=(const Vector<T>& other)
			{
				for (unsigned int i = 0; i < _size; ++i)
					alloc_.destroy(*(ptr + i));
				// alloc_.deallocate(_ptr, _capacity + 1);
				insert(begin(), vector.begin(), vector.end());
				
				return (*this);
			};
			iterator				begin(void)
			{
				return (iterator(_ptr));
			}
			const_iterator			begin(void) const
			{
				return (const_iterator(_ptr));
			}
			iterator				end(void)
			{
				return (iterator(_ptr + _size));
			}
			const_iterator			end(void) const
			{
				return (iterator(_ptr + _size));
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

			size_type	size(void) const
			{
				return (_size);
			}
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(T));
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
					// remove 
				if (n > _size)
					// insert n개 채워질 때까지, val로

			}
			size_type capacity() const
			{
				return (_capacity);
			}
			bool	empty(void) const
			{
				return (_size == 0);
			}
			void reserve (size_type n)
			{
				if (n > max_size())
					throw std::length_error;

				T*			new_ptr;

				new_ptr = _alloc.allocate(n + 1);
				for (unsigned int i = 0; i < _size; ++ i)
					_alloc.construct(&new_ptr[i], _ptr[i]);
				
				//원래 ptr지우고 ptr = newptr & capacity = n
				// clear()? ptr만 지우기?? deallocate?
				
				_ptr = new_ptr;
				_capacity = n;
			}
			reference operator[] (size_type n)
			{
				return (_ptr[n]);
			}
			const_reference operator[] (size_type n) const
			{
				return (_ptr[n]);
			}
			reference at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range();
				return (_ptr[n]);
			}
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range();
				return (_ptr[n]);
			}
			reference front()
			{
				return (*_ptr);
			}
			const_reference front() const
			{
				return (*_ptr);
			}
			reference	back(void)
			{
				return (*(_ptr + _size - 1));
			}
			const_reference	back(void) const
			{
				return (*(_ptr + _size - 1));
			}

			template <class InputIterator>
 			void	assign(InputIterator first, InputIterator last)
			{
				if (_size)
					clear();
				insert(end(), first, last);
			}
			void	assign(size_type n, const value_type& val)
			{
				if (_size)
					clear();
				insert(end(), n, val);
			}
			void push_back(const value_type& val)
			{
				insert(end(), val);
			}
			void pop_back()
			{
				erase(end() - 1);
			}
			iterator insert(iterator position, const value_type& val)
			{
				insert(position, 1, val);
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				if (_size + n > _capacity)
					reserve(_size + n);
				while (size < n)
				{
					_ptr[_size] = *pos;
					*pos = val;
					++pos;
					++size;
				}
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last);
			{
				if (_size + n > _capacity)
					reserve(_size + n);
				iterator	pos = position;
				iterator	it = first;
				whlie (it != end())
				{
					_ptr[_size] = *pos;
					*pos = *it;
					++pos;
					++it;
					++size;
				}
			}
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