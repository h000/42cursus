#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>
# include <exception>

namespace ft
{
    template<class T>
    struct Node
    {
        Node<T> *prev;
        Node<T> *next;
        T       data;
    };
}

#endif