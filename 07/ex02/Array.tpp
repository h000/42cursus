template <typename T>
Array<T>::Array() : arr(nullptr), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : len(n)
{
	this->arr = new T[n];
}

template<typename T>
Array<T>::Array(Array const &other): arr(nullptr), len(0)
{
	//deep copy
	if (other.len > 0)
	{
		this->arr = new T[other.len]();
		for (unsigned int i = 0; i < other.len; i++)
			this->arr[i] = other.arr[i];
	}
	this->len = other.len;
}

template <typename T>
Array<T>::~Array()
{
	if (this->len > 0)
		delete[] this->arr;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array<T> const & other)
{
	if (this->len > 0)
		delete[] this->arr;
	if (other.len > 0)
	{
		this->arr = new T[other.len]();
		for (unsigned int i = 0; i < other.len; i++)
			this->arr[i] = other.arr[i];
	}
	this->len = other.len;
}

template <typename T>
T	&Array<T>::operator[](unsigned int idx)
{
	if (idx < 0 || idx >= this->len)
		throw OutOfLimitsException();
	return this->arr[idx];
}

template<typename T>
std::exception	Array<T>::OutOfLimitsException() const
{
	throw std::out_of_range("The element is out of limits!");
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->len);
}
