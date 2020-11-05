#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {

	//iterator template parameters - category
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : input_iterator_tag {};
	struct bidirectional_iterator_tag : forward_iterator_tag {};
	struct random_access_iterator_tag : bidirectional_iterator_tag {};

	//iterator traits;
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type  difference_type;
		typedef typename Iterator::value_type		value_type;
		typedef typename Iterator::pointer	        pointer;
		typedef typename Iterator::reference	    reference;
		typedef typename Iterator::iterator_category    iterator_category;
	};
	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	//reverse iterator
	template <class Iterator>
	class   ReverseIterator
	{
		private:
			Iterator	_base;
		public:
			typedef Iterator	iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			ReverseIterator(void) {}
			explicit ReverseIterator(iterator_type it) : _base(it) {}
			ReverseIterator(const ReverseIterator<Iterator>& other)
			{
				*this = other;
			}
			~ReverseIterator(void) {};
			iterator_type	base(void) const
			{
				return (_base);
			}
			reference		operator*(void) const
			{
				iterator_type	tmp(_base);
				return (*--tmp); //시작이 _tail, 끝이 _head이기 때문에
			}
			ReverseIterator	operator+(difference_type n) const
			{
				return (ReversIterator(_base - n)); //현재 가리키는 곳에서 n만큼 떨어진 곳을 가리키는 reverse iterator
			}
			ReverseIterator&	operator++()
			{
				--_base;
				return (*this);
			}
			ReverseIterator	operator++(int)
			{
				ReverseIterator<Iterator> tmp = *this;
				++(*this);
				return (tmp);
			}
			ReverseIterator& operator+=(difference_type n)
			{
				_base -= n;
				return (*this); //현재 가리키는 곳에서 n만큼 떨어진 곳을 가리키는 reverse iterator
			}
			ReverseIterator	operator-(difference_type n) const
			{
				return (ReversIterator(_base + n));
			}
			ReverseIterator&	operator--()
			{
				++_base;
				return (*this);
			}
			ReverseIterator	operator--(int)
			{
				ReverseIterator<Iterator> tmp = *this;
				--(*this);
				return (tmp);
			}
			ReverseIterator& operator-=(difference_type n)
			{
				_base += n;
				return (*this);
			}
			pointer operator->() const
			{
				return &(operator*());
			}
			reference operator[] (difference_type n) const
			{
				return (base()[-n-1]);
			}
	};

	//nonmember function overloads (reverse iterator)
	template <class Iterator>
	bool operator==(const ReverseIterator<Iterator>& lhs,
					const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!=(const ReverseIterator<Iterator>& lhs,
					const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator<(const ReverseIterator<Iterator>& lhs,
					const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator<=(const ReverseIterator<Iterator>& lhs,
					const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	bool operator>(const ReverseIterator<Iterator>& lhs,
					const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator>=(const ReverseIterator<Iterator>& lhs,
					const ReverseIterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	ReverseIterator<Iterator> operator+(
				typename ReverseIterator<Iterator>::difference_type n,
				const ReverseIterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}
	template <class Iterator>
	typename ReverseIterator<Iterator>::difference_type operator-(
	const ReverseIterator<Iterator>& lhs, const ReverseIterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif