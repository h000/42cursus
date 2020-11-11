#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{

	template <class T>
	class MapIterator : public iterator<bidirectional_iterator_tag, T>
	{
		private:
			Node*	_ptr;
		public:
			MapIterator(void) {}
			virtual ~MapIterator(void) {}
			MapIterator(Node<T>* ptr) : _ptr(ptr) {}
			MapIterator(const MapIterator& other)
			{
				*this = other;
			}
			MapIterator&	operator=(const MapIterator& other)
			{
				_ptr = other._ptr;
				return (*this);
			}
			MapIterator&	operator++(void)
			{
				if (_ptr && _ptr->next)
					_ptr = _ptr->next;
				return (*this);
			}
			MapIterator	operator++(int)
			{
				MapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			}
			MapIterator&	operator--(void)
			{
				if (_ptr && _ptr->prev)
					_ptr = _ptr->prev;
				return (*this);
			}
			MapIterator	operator--(int)
			{
				MapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			}
			bool	operator==(const MapIterator &other) const
			{
				return (_ptr == other._ptr);
			}
			bool	operator!=(const MapIterator &other) const
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

	template < class Key, class T, class Compare = std::less<Key>,
				class Alloc = std::allocator<std::pair<const Key,T>> >
	class Map
	{
		private:
			RedBlackTree<Key, T, Compare, Alloc>	_tree;
			Alloc	_alloc;

		public:
			typedef	Key									key_type;
			typedef	T									mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare								key_compare;
			class 	value_compare;
			
			typedef Alloc								allocator_type;
			typedef typename Alloc::reference			reference;
			typedef typename Alloc::const_reference		const_reference;
			typedef typename Alloc::pointer				pointer;
			typedef typename Alloc::const_pointer		const_pointer;
			typedef Iterator<const Key, T, key_compare> 		iterator;
			typedef Iterator<const Key, const T, key_compare>	const_iterator;
			typedef ReverseIterator<iterator>			reverse_iterator;
			typedef ReverseIterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t						difference_type;
			typedef size_t								size_type;
		
			explicit Map(const key_compare& comp = key_compare(),
            	const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			Map(const Map& x);
			~Map();
			Map& operator= (const Map& x);

			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend(void);
			const_reverse_iterator	end() const;

			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			mapped_type&	operator[] (const key_type& k);

			pair<iterator,bool> insert(const value_type& val);
			iterator	insert(iterator position, const value_type& val);
			template <class InputIterator>
			void		insert(InputIterator first, InputIterator last);
			void		erase(iterator position);
			size_type	erase(const key_type& k);
			void		erase(iterator first, iterator last);
			void		swap(Map& x);
			void		clear();

			key_compare key_comp() const;
			value_compare value_comp() const;

			iterator find(const key_type& k);
			const_iterator find(const key_type& k) const;
			size_type count(const key_type& k) const;
			iterator lower_bound(const key_type& k);
			const_iterator lower_bound(const key_type& k) const;
			iterator upper_bound(const key_type& k);
			const_iterator upper_bound(const key_type& k) const;
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
			pair<iterator,iterator>             equal_range(const key_type& k);
	};

}

#endif