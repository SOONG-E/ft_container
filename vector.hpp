#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <type_traits>
#include <array>
#include <iostream> // 

using namespace std;

template < class T, class Alloc = allocator<T> > class vector;

template < class T, class Alloc >
class vector {
	public : 
		/* Member types: 12 */
		typedef T			value_type;
		typedef Alloc		allocator_type;
		typedef	typename	allocator_type::reference					reference;
		typedef	typename	allocator_type::const_reference				const_reference;
		typedef	typename	allocator_type::pointer						pointer;
		typedef	typename	allocator_type::const_pointer				const_pointer;
		// typedef typename	random_access_iterator<value_type>			iterator;
		// typedef	typename	random_accedd_iterator<const value_type>	const_iterator;
		typedef typename	reverse_iterator<iterator>					reverse_iterator;
		typedef typename	reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	typename 	iterator_traits<iterator>::difference_type	difference_type;
		typedef	make_unsigned<difference_type>::type					size_type;

		/* Constructor: 4 */
		vector(){};
		explicit vector (const allocator_type& alloc = allocator_type())
			: _vector(array<value_type, 0>), _size(0), _capacity(0) {cout << "SDSD " <<endl;};
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _vector(array<value_type, n>, _size(n), _capacity(n)){
				_vector.fill(val);
			}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
			_capacity = last - first;
			_size = _capacity;
			_vector = array<T, _capacity>;
			for (int i = 0; first != last; ++first)
				_vector[i] = *first;
		};
		vector (const vector& x)
			: _vector(x._vector), _size(x._size), _capacity(x._capacity){};

	private :
		size_type	_size;
		size_type	_capacity;
		array		_vector;
};

#endif