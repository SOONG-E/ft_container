#ifndef PAIR_HPP
#define PAIR_HPP

template <class T1, class T2> struct pair;

template <class T1, class T2>
struct pair{
public :
	typedef	T1	first_type;
	typedef T2	second_type;

	public :
		first_type	first;
		second_type	second;

		pair(): first(), second() {};
		template<class U, class V> 
		pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {};
		pair (const first_type& a, const second_type& b) : first(a), second(b) {};

		pair& operator= (const pair& pr){
			first = pr.first;
			second = pr.second;

			return (*this);
		};


};

template< class T1, class T2 >
::pair<T1, T2> make_pair( T1 t, T2 u ){
	pair<T1, T2> _returnPair(t, u);

	return (_returnPair);
};

template< class T1, class T2 >
bool operator==( const ::pair<T1, T2>& lhs, const ::pair<T1, T2>& rhs ){
	return (lhs.first == rhs.first && lhs.second == rhs.second);
};

template< class T1, class T2 >
bool operator!=( const ::pair<T1, T2>& lhs, const ::pair<T1, T2>& rhs ){
	return (lhs.first != rhs.first || lhs.second != rhs.second);
};

template< class T1, class T2 >
bool operator<( const ::pair<T1, T2>& lhs, const ::pair<T1, T2>& rhs ){
	if (lhs.first == rhs.first)
		return (lhs.second < rhs.second);
	return (lhs.first < rhs.first);
};

template< class T1, class T2 >
bool operator<=( const ::pair<T1, T2>& lhs, const ::pair<T1, T2>& rhs ){
	if (lhs.first == rhs.first)
		return (lhs.second <= rhs.second);
	return (lhs.first <= rhs.first);
};

template< class T1, class T2 >
bool operator>( const ::pair<T1, T2>& lhs, const ::pair<T1, T2>& rhs ){
	if (lhs.first == rhs.first)
		return (lhs.second > rhs.second);
	return (lhs.first > rhs.first);
};

template< class T1, class T2 >
bool operator>=( const ::pair<T1, T2>& lhs, const ::pair<T1, T2>& rhs ){
	if (lhs.first == rhs.first)
		return (lhs.second >= rhs.second);
	return (lhs.first >= rhs.first);
};

#endif