#include "iterator_traits.hpp"

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
 
template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}
 
int main()
{
    std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

    my_reverse(v.begin(), v.end());
    for (int n =0; n < 5 ; ++n) {
        std::cout << v[n] << ' ';
    }
    std::cout << '\n';
 
    std::list<int> l;

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
    my_reverse(l.begin(), l.end());
    for (std::list<int>::iterator it = l.begin() ; it != l.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
 
    int a[] = {1, 2, 3, 4, 5};
    my_reverse(a, a + 5);
    for (int n =0; n < 5 ; ++n) {
        std::cout << a[n] << ' ';
    }
    std::cout << '\n';
}
