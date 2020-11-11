#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "Utils.hpp"
#include "Iterator.hpp"

namespace ft
{
	template <class T>
	class VectorIterator : public iterator<random_access_iterator_tag, T>
	{
		private:
			T*		_ptr;
		public:
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
				return (tmp);
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
				return (tmp);
			}
			VectorIterator	operator+(int n)
			{
				return (VectorIterator(_ptr + n));
			}
			VectorIterator	operator-(int n)
			{
				return (VectorIterator(_ptr - n));
			}
			VectorIterator	&operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}
			VectorIterator	&operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}
			bool	operator==(const VectorIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool	operator!=(const VectorIterator &other) const
			{
				return (_ptr != other._ptr);
			}
			bool	operator<(const VectorIterator &other) const
			{
				return (_ptr < other._ptr);
			}
			bool	operator>(const VectorIterator &other) const
			{
				return (_ptr > other._ptr);
			}
			bool	operator<=(const VectorIterator &other) const
			{
				return (!(_ptr > other._ptr));
			}
			bool	operator>=(const VectorIterator &other) const
			{
				return (!(_ptr < other._ptr));
			}
			T&	operator*(void)
			{
				return (*_ptr);
			}
			T*	operator->(void)
			{
				return (_ptr);
			}
			T& operator[](int n)
			{
				return (*(_ptr + n));
			}
			T*	getPtr()
			{
				return (_ptr);
			}
	};

	template <class T, class Alloc = std::allocator<T> >
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
					_alloc.construct(&_ptr[i], val);
			}
			template <class InputIterator>
			Vector(InputIterator first, InputIterator last,
							const allocator_type& alloc = allocator_type())
			: _ptr(nullptr), _size(0), _capacity(0)
			{
				_ptr = _alloc.allocate(1);
				assign(first, last);
				
			}
			Vector(const Vector& other)
			: _ptr(nullptr), _size(0), _capacity(0)
			{
				*this = other;
			}
			~Vector()
			{
				for (unsigned int i = 0; i < _size; ++i)
					_alloc.destroy((_ptr + i));
				_alloc.deallocate(_ptr, _capacity + 1);
			}
			Vector&	operator=(const Vector<T>& other)
			{
				for (unsigned int i = 0; i < _size; ++i)
					_alloc.destroy((_ptr + i));
				// _alloc_.deallocate(_ptr, _capacity + 1);
				assign(other.begin(), other.end());
				
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
				return (const_iterator(_ptr + _size));
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
				while (n < _size)
					pop_back();
				if (n > _size)
					insert(end(), (n - _size), val);
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
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("reserve: length error");

				T*			new_ptr;

				new_ptr = _alloc.allocate(n + 1);
				for (unsigned int i = 0; i < _size; ++ i)
					_alloc.construct(&new_ptr[i], _ptr[i]);
				
				//원래 ptr지우고 ptr = newptr & capacity = n
				// clear()? ptr만 지우기?? deallocate?
				_alloc.deallocate(_ptr, _capacity + 1);

				_ptr = new_ptr;
				_capacity = n;
			}
			reference operator[](size_type n)
			{
				return (_ptr[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (_ptr[n]);
			}
			reference at(size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("at: out of range");
				return (_ptr[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("at: out of range");
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
				int	n = 0;
				for (InputIterator it = first; it != last; ++it)
					++n;
				if (n > _capacity)
					reserve(n);
				for (InputIterator it = first; it != last; ++it)
				{
					_alloc.construct(&_ptr[_size], *it);
					++_size;
				}
			}
			void	assign(size_type n, const value_type& val)
			{
				if (_size)
					clear();
				if (n > _capacity)
					reserve(n);
				while (_size < n)
				{
					_alloc.construct(&_ptr[_size], val);
					++_size;
				}
			}
			void push_back(const value_type& val)
			{
				if	(_capacity == 0)
					reserve(1);
				else if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				_alloc.construct(&_ptr[_size], val);
				++_size;
			}
			void pop_back()
			{
				--_size;
				_alloc.destroy(_ptr +_size - 1);
			}
			iterator insert(iterator position, const value_type& val)
			{
				insert(position, (size_type)1, val);
				return (position);
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				int	pos = 0;
				for (iterator it = begin(); it != position; ++it)
					++pos;

				for (unsigned int i = 0; i < n; ++i)
				{
					push_back(_ptr[pos]);
					_ptr[pos] = val;
				}
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				int	pos = 0;
				for (iterator it = begin(); it != position; ++it)
					++pos;

				for (InputIterator it = first; it != last; ++it)
				{
					push_back(_ptr[pos]);
					_ptr[pos] = *it;
				}
			}
			iterator erase(iterator position)
			{
				int	pos = 0;
				iterator it = begin();
				while(it++ != position)
					++pos;
				--_size;
				iterator	ret = it;
				while (pos < _size)
					_ptr[pos++] = *it++;
				_alloc.destroy(&(_ptr[pos]));
				return (ret);
			}
			iterator erase(iterator first, iterator last)
			{
				int	old_size = _size;
				int	pos = 0;
				iterator it;
				for (it = begin(); it != first; ++it)
					++pos;
				while (it != last)
				{
					--_size;
					++it;
				}
				iterator	ret = it;
				while (pos < _size)
					_ptr[pos++] = *it++;
				while (pos < old_size)
					_alloc.destroy(&(_ptr[pos++]));
				return (ret);
			}
			void swap (Vector& x)
			{
				std::swap(_ptr, x._ptr);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
			}
			void clear()
			{
				while (_size)
				{
					--_size;
					_alloc.destroy(&(_ptr[_size - 1]));
				}
			}
	};
	template <class T, class Alloc>
	bool	operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (unsigned int i = 0; i < lhs.size(); ++i)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);	
	}
	template <class T, class Alloc>
	bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		unsigned int	n;
		if (lhs.size() < rhs.size())
			n = lhs.size();
		else
			n = rhs.size();

		for (unsigned int i = 0; i < n; ++i)
		{
			if (lhs[i] < rhs[i])
				return (true);
			else if (lhs[i] > rhs[i])
				return (false);
		}
		return (lhs.size() < rhs.size());
	}
	template <class T, class Alloc>
	bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
 	bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void	swap(Vector<T,Alloc>& x, Vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif