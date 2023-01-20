#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "enable_if.hpp"
#include <type_traits>

namespace ft{
	template <class T> struct is_integral;

	template <class T>
	struct is_integral{
		typedef bool	value_type;

	};
}

#endif
