/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:11:36 by laube             #+#    #+#             */
/*   Updated: 2022/04/26 15:33:26 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
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

template <typename Tp>
struct iterator_traits<const Tp*> {
  typedef std::random_access_iterator_tag iterator_category;
  typedef Tp value_type;
  typedef std::ptrdiff_t difference_type;
  typedef const Tp* pointer;
  typedef const Tp& reference;
};


template<typename Iterator_type>
class reverse_iterator : std::iterator<
                            typename iterator_traits<Iterator_type>::iterator_category,
                            typename iterator_traits<Iterator_type>::value_type,
                            typename iterator_traits<Iterator_type>::difference_type,
                            typename iterator_traits<Iterator_type>::pointer,
                            typename iterator_traits<Iterator_type>::reference
                         >
{
    protected:
        Iterator_type m_current;

        typedef iterator_traits<Iterator_type> traits_type;

    public:
        typedef Iterator_type                           Iter;
        typedef typename traits_type::iterator_category iterator_category;
        typedef typename traits_type::value_type        value_type;
        typedef typename traits_type::difference_type   difference_type;
        typedef typename traits_type::pointer           pointer;
        typedef typename traits_type::reference         reference;

        // MEMBER FUNCTIONS
        reverse_iterator() : m_current() {}

        explicit reverse_iterator(Iterator_type x) : m_current(x) {}

        template<typename U>
        reverse_iterator(const reverse_iterator<U>& other) : m_current(other.m_current) {}

        template<typename U>
        reverse_iterator& operator=(const reverse_iterator<U>& other) {
            m_current = other.m_current;
        }

        Iterator_type base() const {
            return m_current;
        }

        reference operator*() const {
            return *m_current;
        }

        pointer operator->() const {
            return m_current;
        }

        Iterator_type operator[](difference_type n) const {
            return *(m_current - n - 1);
        }

        reverse_iterator& operator++() {
            --m_current;
            return *this;
        }

        reverse_iterator& operator--() {
            ++m_current;
            return *this;
        }

        reverse_iterator& operator++(int) {
            return reverse_iterator(m_current--);
        }

        reverse_iterator& operator--(int) {
            return reverse_iterator(m_current++);
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator(m_current - n);
        }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator(m_current + n);
        }

        reverse_iterator& operator+=(difference_type n) {
            m_current -= n;
            return *this;
        }

        reverse_iterator& operator-=(difference_type n) {
            m_current += n;
            return *this;
        }
};

// REVERSE ITERATOR NON-MEMBER FUNCTIONS
    template<typename Iterator1, typename Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs,
        const reverse_iterator<Iterator2>& rhs)
{
    return lhs.base() == rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs)
{
    return lhs.base() != rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<(reverse_iterator<Iterator1>& lhs,
                reverse_iterator<Iterator2>& rhs)
{
    return lhs.base() < rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<=(reverse_iterator<Iterator1>& lhs,
                reverse_iterator<Iterator2>& rhs)
{
    return lhs.base() <= rhs.base();
}
                                            
template<typename Iterator1, typename Iterator2>
bool operator>(reverse_iterator<Iterator1>& lhs,
                reverse_iterator<Iterator2>& rhs)
{
    return lhs.base() > rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>=(reverse_iterator<Iterator1>& lhs,
                reverse_iterator<Iterator2>& rhs)
{
    return lhs.base() >= rhs.base();
}

template<class Iter>
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
{
    return it.base() - n;
}

template<class Iter>
reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
{
    return it.base() + n;
}

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
  reference operator*() const {
      return *m_current;
  }

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
    return normal_iterator(m_current--);
  }

  // Random access iterator overloads
  reference operator[](difference_type n) const { return m_current[n]; }

  normal_iterator& operator+=(difference_type n) {
    m_current += n;
    return *this;
  }

  normal_iterator operator+(difference_type elem) {
    return normal_iterator(m_current + elem);
  }

  normal_iterator& operator-=(difference_type n) {
    m_current -= n;
    return *this;
  }

  normal_iterator operator-(difference_type elem) {
    return normal_iterator(m_current - elem);
  }

  // This base function is a getter since m_current is protected
  const Iterator_type& base() const { return m_current; }
};

// Non-member overloads
// Forward iterator non-member overloads
template <typename IteratorL, typename IteratorR>
bool operator==(const normal_iterator<IteratorL>& lhs,
                const normal_iterator<IteratorR>& rhs) {
  return lhs.base() == rhs.base();
}

template <typename IteratorL, typename IteratorR>
bool operator!=(const normal_iterator<IteratorL>& lhs,
                const normal_iterator<IteratorR>& rhs) {
  return lhs.base() != rhs.base();
}

// Random access iterator non-member overloads
template <typename IteratorL, typename IteratorR>
bool operator>(const normal_iterator<IteratorL>& lhs,
               const normal_iterator<IteratorR>& rhs) {
  return lhs.base() > rhs.base();
}

template <typename IteratorL, typename IteratorR>
bool operator<(const normal_iterator<IteratorL>& lhs,
               const normal_iterator<IteratorR>& rhs) {
  return lhs.base() < rhs.base();
}

template <typename IteratorL, typename IteratorR>
bool operator>=(const normal_iterator<IteratorL>& lhs,
                const normal_iterator<IteratorR>& rhs) {
  return lhs.base() <= rhs.base();
}

template <typename IteratorL, typename IteratorR>
bool operator<=(const normal_iterator<IteratorL>& lhs,
                const normal_iterator<IteratorR>& rhs) {
  return lhs.base() <= rhs.base();
}

template <typename Iterator>
typename normal_iterator<Iterator>::difference_type operator-(
    const normal_iterator<Iterator>& lhs,
    const normal_iterator<Iterator>& rhs) {
  return lhs.base() - rhs.base();
}

template <typename Iterator>
typename normal_iterator<Iterator>::difference_type operator+(
    typename normal_iterator<Iterator>::difference_type lhs,
    const normal_iterator<Iterator>& rhs) {
  return normal_iterator<Iterator>(rhs.base() + lhs);
}

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  // Member Types
  typedef T                                      value_type;
  typedef Allocator                              allocator_type;
  typedef std::size_t                            size_type;
  typedef std::ptrdiff_t                         difference_type;
  typedef value_type&                            reference;
  typedef const value_type&                      const_reference;
  typedef T*                                     pointer;
  typedef const T*                               const_pointer;
  typedef normal_iterator<pointer>               iterator;
  typedef normal_iterator<const_pointer>         const_iterator;
  typedef ft::reverse_iterator<iterator>         reverse_iterator;
  typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;

  // The fuck is this?
  //size_type max_size() const { return (get_allocator().max_size()); }

 private:
  pointer m_start;
  pointer m_finish;
  pointer m_end_of_storage;
  allocator_type m_alloc;

  void m_create_storage(size_t count) {
    // ADD ERROR IF COUNT IS NEGATIVE
    m_start = m_alloc.allocate(count);
    m_finish = m_start;
    m_end_of_storage = m_start + count;
  }

  void m_construct_storage(const T& value) {
    for (int i = 0; m_start + i != m_end_of_storage; i++) {
      m_alloc.construct(m_start + i, value);
    }
    m_finish = m_end_of_storage;
  }

 public:
  // MEMBER FUNCTIONS
  // Constructors
  vector() : m_start(), m_finish(), m_end_of_storage(), m_alloc() {}

  explicit vector(const Allocator& alloc)
      : m_start(), m_finish(), m_end_of_storage(), m_alloc(alloc) {}

  explicit vector(size_type count, const T& value = T(),
                  const Allocator& alloc = Allocator())
      : m_alloc(alloc) {
    m_create_storage(count);
    m_construct_storage(value);
  }

  template <typename InputIt>
  vector(typename std::enable_if<!(std::is_integral<InputIt>::value),
                                 InputIt>::type first,
         InputIt last, const Allocator& alloc = Allocator())
      : m_alloc(alloc) {
    m_create_storage(last - first);
    for (int i = 0; first != last; ++first, ++i) {
      *(m_start + i) = *first;
    }
    m_finish = m_end_of_storage;
  }

  vector(const vector& other) {
    m_create_storage(other.end() - other.begin());
    for (size_type i = 0; other.begin() + i != other.end(); ++i) {
      *(m_start + i) = *(other.begin() + i);
    }
    m_finish = m_end_of_storage;
    m_alloc = other.get_allocator();
  }
  // Destructors
  ~vector() {
    m_alloc.deallocate(m_start, m_end_of_storage - m_start);
    m_start = nullptr;
    m_finish = nullptr;
    m_end_of_storage = nullptr;
  }

  // Other member functions
  vector& operator=(const vector& other) {
    m_alloc.deallocate(m_start, m_end_of_storage - m_start);
    m_create_storage(other.end() - other.begin());
    for (size_type i = 0; other.begin() + i != other.end(); ++i) {
      *(m_start + i) = *(other.begin() + i);
    }
    m_finish = m_end_of_storage;
  }

  void assign(size_type count, const T& value) {
    m_alloc.deallocate(m_start, m_end_of_storage - m_start);
    m_create_storage(count);
    m_construct_storage(value);
  }

  template <class InputIt>
  void assign(typename std::enable_if<!std::is_integral<InputIt>::value,
                                      InputIt>::type first,
              InputIt last) {
    m_alloc.deallocate(m_start, m_end_of_storage - m_start);
    m_create_storage(last - first);
    for (size_type i = 0; first + i != last; ++i) {
      *(m_start + i) = *(first + i);
    }
    m_finish = m_end_of_storage;
  }

  allocator_type get_allocator() const { return (this->m_alloc); }

  // Element accesses
  reference at(size_type pos) {
    if (pos >= size()) {
      throw std::out_of_range("at(): position is greater or equal to size");
    }
    return *(m_start + pos);
  }

  const_reference at(size_type pos) const {
    if (pos >= size()) {
      throw std::out_of_range("at(): position is greater or equal to size");
    }
    return *(m_start + pos);
  }

  reference front() {
    return *begin();
  }

  const_reference front() const {
    return *begin();
  }

  reference back() {
    return *end();
  }

  const_reference back() const {
    return *end();
  }

  T* data() {
    return m_start;
  }

  const T* data() const {
    return m_start;
  }

  reference operator[](size_type pos) { return *(this->m_start + pos); }

  iterator begin() { return iterator(this->m_start); }

  const_iterator begin() const { return const_iterator(this->m_start); }

  iterator end() { return iterator(this->m_finish); }

  const_iterator end() const { return const_iterator(this->m_finish); }

  reverse_iterator rbegin() {
    return reverse_iterator(this->m_finish);
  }

  const_reverse_iterator rbegin() const
  {
    return const_reverse_iterator(this->m_finish);
  }

  reverse_iterator rend() {
    return reverse_iterator(this->m_start);
  }

  const_reverse_iterator rend() const
  {
    return const_reverse_iterator(this->m_start);
  }

  bool empty() const {
    return begin() == end();
  }

  size_type size() const {
    return std::distance(begin(), end());
  }

  size_type max_size() const {
    return std::numeric_limits<difference_type>::max();
  }
  size_type capacity() const {
    return m_end_of_storage - m_start;
  }

  void reserve(size_type new_cap) {
    if (new_cap <= capacity())
        return;
    if (new_cap > max_size())
        throw std::length_error("Can't reserve vector size: bigger than max_size()");

  }
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
//  *     - [x] 5.  template< class InputIt >
//  *         vector( InputIt first, InputIt last, const Allocator& alloc =
//  Allocator() );
//  *     - [x] 6.  vector( const vector& other );
//  *
//  *   DESTRUCTORS
//  *     - [x] 1.  ~vector();
//  *
//  *   OTHER MEMBER FUNCTIONS
//  *     - [x] 1.  vector& operator=( const vector& other );
//  *     - [x] 1.  void assign( size_type count, const T& value );
//  *     - [x] 2.  template< class InputIt > void assign( InputIt first,
//  InputIt last );
//  *     - [x] 1.  allocator_type get_allocator() const;
//  *
//  *   ELEMENT ACCESS
//  *     - [x] 1.  reference at( size_type pos );
//  *     - [x] 2.  const_reference at( size_type pos ) const;
//  *     - [x] 1.  reference front();
//  *     - [x] 2.  const_reference front() const;
//  *     - [x] 1.  reference back();
//  *     - [x] 2.  const_reference back() const;
//  *     - [x] 1.  T* data();
//  *     - [x] 2.  const T* data() const;
//  *
//  *   ITERATORS
//  *     - [x] 1.  iterator begin();
//  *     - [x] 2.  const_iterator begin() const;
//  *     - [x] 1.  iterator end();
//  *     - [x] 2.  const_iterator end() const;
//  *     - [x] 1.  reverse_iterator rbegin();
//  *     - [x] 2.  const_reverse_iterator rbegin() const;
//  *     - [x] 1.  reverse_iterator rend();
//  *     - [x] 2.  const_reverse_iterator rend() const;
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
