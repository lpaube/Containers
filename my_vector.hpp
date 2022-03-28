/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:11:36 by laube             #+#    #+#             */
/*   Updated: 2022/03/28 15:14:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>

namespace ft
{
  template <typename T, typename Allocator = std::allocator<T> >
  class vector
  {

    // size_type m_size;       // Current size of the vector
    // size_type m_capacity;   // Maximum size of vector (this is dynamic in nature)
    // pointer   m_data;  // Pointer to the start of data type container
    // allocator_type m_allocator;

  public:
    // Member Types
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef T *pointer;
    typedef const T *const_pointer;
    // typedef normal_iterator<value_type>           iterator;
    // typedef normal_iterator<const value_type>     const_iterator;
    // typedef reverse_iterator<iterator>       reverse_iterator;
    // typedef reverse_iterator<const_iterator> const_reverse_iterator;

    bool empty() const;
    size_type size() const;
    size_type max_size() const {
      return (get_allocator().max_size());
    }
    void reserve(size_type new_cap);
    size_type capacity() const;

  private:
    pointer m_start;
    pointer m_finish;
    pointer m_end_of_storage;
    allocator_type m_alloc;

    pointer _allocate(allocator_type& alloc, size_type count) {
      return alloc.allocate(count);
    }

    void _vallocate(size_type count)
    {
      if (count > max_size())
        std::cout << "error......." << std::endl;
        // this->throw_length_error();
      this->m_start = _allocate(this->m_alloc, count);
      this->m_finish = this->m_start;
    }

    void  _construct_at_end(size_type count, const_reference value) {
      for (int i = 0; i < count; i++)
      this->m_alloc.construct(this->m_start + i, value);
    }

  public:
    // MEMBER FUNCTIONS--
    // Constructors
    vector() : m_start(nullptr), m_finish(nullptr), m_end_of_storage(nullptr), m_alloc() {}
    explicit vector(const Allocator &alloc) : m_start(nullptr), m_finish(nullptr), m_end_of_storage(nullptr), m_alloc(alloc) {}
    explicit vector(size_type count, const T &value = T(), const Allocator &alloc = Allocator()) : m_alloc(alloc)
    {
      if (count > 0)
      {
        _vallocate(count);
        _construct_at_end(count, value);
      }
    }
    template <class InputIt>
    vector(InputIt first, InputIt last, const Allocator &alloc = Allocator());
    vector(const vector &other);

    // Destructors
    ~vector() {}

    // Other member functions
    vector &operator=(const vector &other);
    void assign(size_type count, const T &value);
    template <class InputIt>
    void assign(InputIt first, InputIt last) {}
    allocator_type get_allocator() const {
      return (allocator_type(this->m_alloc));
    }
  };
}
// SOURCE CODE:
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01069_source.html
// VECTOR DETAILS:
// https://hadibrais.wordpress.com/2013/11/10/dissecting-the-c-stl-vector-part-1-introduction/
// DOCUMENTATION:	https://en.cppreference.com/w/cpp/container/vector
//  LIST
//  *
//  * MEMBER FUNCTIONS
//  * 		CONSTRUCTORS
//  * 			1.	vector();
//  * 			2.	explicit vector( const Allocator& alloc );
//  * 			3.	explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
//  * 			5.	template< class InputIt >
//  * 					vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
//  * 			6.	vector( const vector& other );
//  *
//  * 		DESTRUCTORS
//  * 			1.	~vector();
//  *
//  * 		OTHER MEMBER FUNCTIONS
//  * 			1.	vector& operator=( const vector& other );
//  * 			1.	void assign( size_type count, const T& value );
//  * 			2.	template< class InputIt > void assign( InputIt first, InputIt last );
//  * 			1.	allocator_type get_allocator() const;
//  *
//  * 		ELEMENT ACCESS
//  * 			1.	reference at( size_type pos );
//  * 			2.	const_reference at( size_type pos ) const;
//  * 			1.	reference front();
//  * 			2.	const_reference front() const;
//  * 			1.	reference back();
//  * 			2.	const_reference back() const;
//  * 			1.	T* data();
//  * 			2.	const T* data() const;
//  *
//  * 		ITERATORS
//  * 			1.	iterator begin();
//  * 			2.	const_iterator begin() const;
//  * 			1.	iterator end();
//  * 			2.	const_iterator end() const;
//  * 			1.	reverse_iterator rbegin();
//  * 			2.	const_reverse_iterator rbegin() const;
//  * 			1.	reverse_iterator rend();
//  * 			2.	const_reverse_iterator rend() const;
//  *
//  * 		CAPACITY
//  * 			1.	bool empty() const;
//  * 			1.	size_type size() const;
//  * 			1.	size_type max_size() const;
//  * 			1.	void reserve( size_type new_cap );
//  * 			1.	size_type capacity() const;
//  *
//  * 		MODIFIERS
//  * 			1.	void clear();
//  * 			1.	iterator insert( iterator pos, const T& value );
//  * 			3.	void insert( iterator pos, size_type count, const T& value );
//  * 			4.	template< class InputIt >
//  * 					void insert( iterator pos, InputIt first, InputIt last );
//  * 			1.	iterator erase( iterator pos );
//  * 			2.	iterator erase( iterator first, iterator last );
//  * 			1.	void push_back( const T& value );
//  * 			1.	void pop_back();
//  * 			2.	void resize( size_type count, T value = T() );
//  * 			1.	void swap( vector& other );
//  *
//  * 	NON-MEMBER FUNCTIONS
//  *		1.	template< class T, class Alloc >
//  *				bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//  *		2.	template< class T, class Alloc >
//  *				bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//  *		3.	template< class T, class Alloc >
//  *				bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//  *		4.	template< class T, class Alloc >
//  *				bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//  *		5.	template< class T, class Alloc >
//  *				bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//  *		6.	template< class T, class Alloc >
//  *				bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
//  *		1.	template< class T, class Alloc >
//  *				void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );
