#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed(const int N);
		Fixed(const float F);
		Fixed	&operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fx);

#endif