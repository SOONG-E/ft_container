#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

template <class Iter> class reverse_iterator;

template <class Iter>
class reverse_iterator : public std::iterator<typename ::iterator_traits<Iter>::iterator_category, typename ::iterator_traits<Iter>::value_type, typename ::iterator_traits<Iter>::difference_type, typename ::iterator_traits<Iter>::pointer, typename ::iterator_traits<Iter>::reference > {
public :
	typedef Iter		iterator_type;
	typedef typename ::iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename ::iterator_traits<Iter>::value_type		value_type;
	typedef typename ::iterator_traits<Iter>::difference_type	difference_type;
	typedef typename ::iterator_traits<Iter>::pointer			pointer;
	typedef typename ::iterator_traits<Iter>::reference			reference;

	public :
		/* Constructor */
		reverse_iterator() : _base(){};
		explicit reverse_iterator (iterator_type it) : _base(it) {};
		template< class OtherIter >
		reverse_iterator (const reverse_iterator<OtherIter>& rev_it) : _base(rev_it._base) {};

		/* Member function */
		iterator_type base() const{
			iterator_type _returnBase = _base;
			return (_returnBase);
		} 

		/* overloaded function */
		template< class OtherIter >
		reverse_iterator& operator=( const reverse_iterator<OtherIter>& other ){
			_base = other._base;
			return (*this);
		};

		reference operator*() const{
			iterator_type _returnBase = _base;
			return (*(--_returnBase));
		};
		reverse_iterator<iterator_type> operator+(difference_type n) const{
			reverse_iterator<iterator_type> _returnBase(*this);
			_returnBase._base -= n;
			return (_returnBase);
		};

		reverse_iterator& operator++(){
			--_base;
			return (*this);
		};
		reverse_iterator  operator++(int){
			reverse_iterator<iterator_type> _returnBase(*this);
			--_base;
			return (_returnBase);
		};

		reverse_iterator& operator+=(difference_type n){
			_base -= n;
			return (*this);
		};

		reverse_iterator<iterator_type> operator-(difference_type n) const{
			reverse_iterator<iterator_type> _returnBase(*this);
			_returnBase._base += n;
			return (_returnBase);
		};

		reverse_iterator& operator--(){
			++_base;
			return (*this);
		};
		reverse_iterator  operator--(int){
			reverse_iterator<iterator_type> _returnBase(*this);
			++_base;
			return (_returnBase);
		};

		reverse_iterator& operator-=(difference_type n){
			_base += n;
			return (*this);
		};

		pointer operator->() const{
			return &(operator*());
		};

		reference operator[] (difference_type n) const{
			return (base()[-n-1]);
		};

		template< class OtherIter >
		bool  operator==(reverse_iterator<OtherIter>& other){
			return (_base == other._base);
		};

		template< class OtherIter >
		bool  operator!=(reverse_iterator<OtherIter>& other){
			return (_base != other._base);
		};

		template< class OtherIter >
		bool  operator<(reverse_iterator<OtherIter>& other){
			return (_base > other._base);
		};

		template< class OtherIter >
		bool  operator<=(reverse_iterator<OtherIter>& other){
			return (_base >= other._base);
		};

		template< class OtherIter >
		bool  operator>(reverse_iterator<OtherIter>& other){
			return (_base < other._base);
		};

		template< class OtherIter >
		bool  operator>=(reverse_iterator<OtherIter>& other){
			return (_base <= other._base);
		};

	protected :
		iterator_type	_base;
};


#endif