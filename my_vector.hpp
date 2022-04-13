/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:11:36 by laube             #+#    #+#             */
/*   Updated: 2022/04/04 12:19:03 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>

namespace ft {
template <typename Iterator>
struct iterator_traits {
  typedef typename Iterator::iterator_category iterator_category;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
};

template <typename Tp>
struct iterator_traits<Tp*> {
  typedef std::random_access_iterator_tag iterator_category;
  typedef Tp value_type;
  typedef std::ptrdiff_t difference_type;
  typedef Tp* pointer;
  typedef Tp& reference;
};

// What's the point of having this specialization if it's the same as the prev
// one?
template <typename Tp>
struct iterator_traits<const Tp*> {
  typedef std::random_access_iterator_tag iterator_category;
  typedef Tp value_type;
  typedef std::ptrdiff_t difference_type;
  typedef Tp* pointer;
  typedef Tp& reference;
};

template <typename Iterator_type>
class normal_iterator {
 protected:
  Iterator_type m_current;

  typedef iterator_traits<Iterator_type> traits_type;

 public:
  typedef typename traits_type::iterator_category iterator_category;
  typedef typename traits_type::value_type value_type;
  typedef typename traits_type::difference_type difference_type;
  typedef typename traits_type::reference reference;
  typedef typename traits_type::pointer pointer;

  normal_iterator() : m_current(Iterator_type()) {}
  normal_iterator(const Iterator_type& i) : m_current(i) {}

  // Forward iterator overloads
  reference operator*() const { return *m_current; }

  pointer operator->() const { return m_current; }

  normal_iterator& operator++() {
    ++m_current;
    return *this;
  }

  normal_iterator operator++(int) { return normal_iterator(m_current++); }

  // Bidirectional iterator overloads

  normal_iterator operator--() {
    --m_current;
    return *this;
  }

  normal_iterator operator--(int) {
    return normal_iterator(m_current++);
  }

  // How can it create an Iterator when returns integer?(iter1 - iter2 = 2)
  normal_iterator operator-(difference_type elem) {
    return normal_iterator(m_current - elem);
  }

  normal_iterator operator+(difference_type elem) {
    return normal_iterator(m_current + elem);
  }
};

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  // Member Types
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef normal_iterator<value_type> iterator;
  typedef normal_iterator<const value_type> const_iterator;
  // typedef reverse_iterator<iterator>       reverse_iterator;
  // typedef reverse_iterator<const_iterator> const_reverse_iterator;

  bool empty() const;
  size_type size() const;
  size_type max_size() const { return (get_allocator().max_size()); }
  void reserve(size_type new_cap);
  size_type capacity() const;

 private:
  pointer m_start;
  pointer m_finish;
  pointer m_end_of_storage;
  allocator_type m_alloc;

  // Allocates memory of size count using the allocator, then
  // sets m_start and m_finish
  pointer allocate(allocator_type& alloc, size_type count) {
    return alloc.allocate(count);
  }

  void vallocate(size_type count) {
    if (count > max_size()) std::cout << "error......." << std::endl;
    // this->throw_length_error();
    this->m_start = allocate(this->m_alloc, count);
    this->m_finish = this->m_start + count;
  }

  // Constructs the elements in the memory allocated and initialize it with
  // value
  void construct_at_end(size_type count, const_reference value) {
    for (size_type i = 0; i < count; i++)
      this->m_alloc.construct(this->m_start + i, value);
  }

  template <typename InputIt>
  void construct_at_end(InputIt firstIt, InputIt lastIt, size_type count) {}

 public:
  // MEMBER FUNCTIONS--
  // Constructors
  vector() : m_start(), m_finish(), m_end_of_storage(), m_alloc() {}
  explicit vector(const Allocator& alloc)
      : m_start(), m_finish(), m_end_of_storage(), m_alloc(alloc) {}
  explicit vector(size_type count, const T& value = T(),
                  const Allocator& alloc = Allocator())
      : m_alloc(alloc) {
    if (count > 0) {
      vallocate(count);
      construct_at_end(count, value);
    }
  }
  template <typename InputIt>
  vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {
    size_type count = last - first;
  }

  vector(const vector& other);

  // Destructors
  ~vector() {}

  // Other member functions
  vector& operator=(const vector& other);

  void assign(size_type count, const T& value);

  template <class InputIt>
  void assign(InputIt first, InputIt last) {}
  allocator_type get_allocator() const {
    return (allocator_type(this->m_alloc));
  }

  reference operator[](size_type pos) { return *(this->m_start + pos); }
};
}  // namespace ft
// SOURCE CODE:
// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html
// DOCUMENTATION:
// https://en.cppreference.com/w/cpp/container/vector
//  LIST
//  *
//  * MEMBER FUNCTIONS
//  *   CONSTRUCTORS
//  *     - [x] 1.  vector();
//  *     - [x] 2.  explicit vector( const Allocator& alloc );
//  *     - [x] 3.  explicit vector( size_type count, const T& value = T(),
//  const Allocator& alloc = Allocator());
//  *     - [ ] 5.  template< class InputIt >
//  *         vector( InputIt first, InputIt last, const Allocator& alloc =
//  Allocator() );
//  *     - [ ] 6.  vector( const vector& other );
//  *
//  *   DESTRUCTORS
//  *     - [ ] 1.  ~vector();
//  *
//  *   OTHER MEMBER FUNCTIONS
//  *     - [ ] 1.  vector& operator=( const vector& other );
//  *     - [ ] 1.  void assign( size_type count, const T& value );
//  *     - [ ] 2.  template< class InputIt > void assign( InputIt first,
//  InputIt last );
//  *     - [ ] 1.  allocator_type get_allocator() const;
//  *
//  *   ELEMENT ACCESS
//  *     - [ ] 1.  reference at( size_type pos );
//  *     - [ ] 2.  const_reference at( size_type pos ) const;
//  *     - [ ] 1.  reference front();
//  *     - [ ] 2.  const_reference front() const;
//  *     - [ ] 1.  reference back();
//  *     - [ ] 2.  const_reference back() const;
//  *     - [ ] 1.  T* data();
//  *     - [ ] 2.  const T* data() const;
//  *
//  *   ITERATORS
//  *     - [ ] 1.  iterator begin();
//  *     - [ ] 2.  const_iterator begin() const;
//  *     - [ ] 1.  iterator end();
//  *     - [ ] 2.  const_iterator end() const;
//  *     - [ ] 1.  reverse_iterator rbegin();
//  *     - [ ] 2.  const_reverse_iterator rbegin() const;
//  *     - [ ] 1.  reverse_iterator rend();
//  *     - [ ] 2.  const_reverse_iterator rend() const;
//  *
//  *   CAPACITY
//  *     - [ ] 1.  bool empty() const;
//  *     - [ ] 1.  size_type size() const;
//  *     - [ ] 1.  size_type max_size() const;
//  *     - [ ] 1.  void reserve( size_type new_cap );
//  *     - [ ] 1.  size_type capacity() const;
//  *
//  *   MODIFIERS
//  *     - [ ] 1.  void clear();
//  *     - [ ] 1.  iterator insert( iterator pos, const T& value );
//  *     - [ ] 3.  void insert( iterator pos, size_type count, const T& value
//  );
//  *     - [ ] 4.  template< class InputIt >
//  *         void insert( iterator pos, InputIt first, InputIt last );
//  *     - [ ] 1.  iterator erase( iterator pos );
//  *     - [ ] 2.  iterator erase( iterator first, iterator last );
//  *     - [ ] 1.  void push_back( const T& value );
//  *     - [ ] 1.  void pop_back();
//  *     - [ ] 2.  void resize( size_type count, T value = T() );
//  *     - [ ] 1.  void swap( vector& other );
//  *
//  * NON-MEMBER FUNCTIONS
//  *   - [ ] 1.  template< class T, class Alloc >
//  *       bool operator==( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [ ] 2.  template< class T, class Alloc >
//  *       bool operator!=( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [ ] 3.  template< class T, class Alloc >
//  *       bool operator<( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [ ] 4.  template< class T, class Alloc >
//  *       bool operator<=( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [ ] 5.  template< class T, class Alloc >
//  *       bool operator>( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [ ] 6.  template< class T, class Alloc >
//  *       bool operator>=( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [ ] 1.  template< class T, class Alloc >
//  *       void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );
