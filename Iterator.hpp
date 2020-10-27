#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {

    //iterator template parameters - category
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : input_iterator_tag {};
    struct bidirectional_iterator_tag : forward_iterator_tag {};
    struct random_access_iterator_tag : bidirectional_iterator_tag {};

    // //iterator traits;
    // template <class Iterator>
    // class iterator_traits
    // {
    //     typedef typename Iterator::difference_type   difference_type;
    //     typedef typename Iterator::value_type        value_type;
    //     typedef typename Iterator::pointer           pointer;
    //     typedef typename Iterator::reference         reference;
    //     typedef typename Iterator::iterator_category iterator_category;
    // }
	// template <class T>
    // class iterator_traits<T*>
    // {
    //     typedef typename Iterator::difference_type	ptrdiff_t;
    //     typedef typename Iterator::value_type		T;
    //     typedef typename Iterator::pointer			T*;
    //     typedef typename Iterator::reference			T&;
    //     typedef typename Iterator::iterator_category	random_access_iterator_tag;
    // }
    // template <class T>
	// class iterator_traits<const T*>
	// {
	// 	typedef typename Iterator::difference_type	ptrdiff_t;
    //     typedef typename Iterator::value_type		T;
    //     typedef typename Iterator::pointer			const T*;
    //     typedef typename Iterator::reference			const T&;
    //     typedef typename Iterator::iterator_category	random_access_iterator_tag;
	// }

	//reverse iterator
    template <class Iterator>
    class   ReverseIterator
    {
        private:
            iterator_type	_base;
        public:
            typedef Iterator    iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
            typedef typename iterator_traits<Iterator>::value_type			value_type;
            typedef typename iterator_traits<Iterator>::difference_type		difference_type;
            typedef typename iterator_traits<Iterator>::pointer				pointer;
            typedef typename iterator_traits<Iterator>::reference			reference;

            ReverseIterator(void) {}
            explicit ReverseIterator(iterator_type it) : _base(it) {}
            template <class Iter>
            ReverseIterator(const reverse_iterator<Iterator>& other)
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
				//--tmp;? 왜지?
				return (*tmp);
			}
			ReverseIterator	operator+(difference_type n) const
			{
				_base -= n;
				return (*this); //현재 가리키는 곳에서 n만큼 떨어진 곳을 가리키는 reverse iterator
			}
			ReverseIterator&	operator++()
			{
				--_base;
				return (*this);
			}
			ReverseIterator	operator++(int)
			{
				ReverseIterator<Iterator> ite(base_--);
				return (ite);
			}
			
    }

}

#endif