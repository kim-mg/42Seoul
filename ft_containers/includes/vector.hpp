#ifndef	FT_CONTAINERS_INCLUDES_VECTOR_HPP_
#define FT_CONTAINERS_INCLUDES_VECTOR_HPP_

#include <memory>

namespace ft {
	template <class T, class Allocator = std::allocator<T> > class vector {
		public:
			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			// typedef implementation-defined							iterator;
			// typedef implementation-defined							const_iterator;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename std::reverse_iterator<iterator>		reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator>	const_reverse_iterator;

			vector()
				noexcept(is_nothrow_default_constructible<allocator_type>::value);
			explicit vector(const allocator_type&);
			explicit vector(size_type n);
			vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
	}
}

#endif