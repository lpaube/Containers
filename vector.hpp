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

#pragma once

#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <algorithm>
#include "iterator.hpp"

namespace ft {

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

  /*
  template <typename InputIterator>
  void create_storage_dispatch(InputIterator first, InputIterator last, std::input_iterator_tag)
  {
    for (int i = 0; 
  }
  */

  iterator m_construct_storage(const T& value) {
    for (int i = 0; m_start + i != m_end_of_storage; i++) {
      m_alloc.construct(m_start + i, value);
    }
    m_finish = m_end_of_storage;
    return m_finish;
  }

  pointer m_construct_storage(pointer dst, iterator ite1, iterator ite2)
  {
      int i = 0;
      for (; ite1 + i != ite2; ++i)
      {
          *(dst + i) = *(ite1 + i);
      }
      return dst + i;
  }

  void destroy_storage(iterator ite1, iterator ite2)
  {
    for (; ite1 != ite2; ++ite1)
    {
        m_alloc.destroy(ite1.base());
    }
  }

  /*
   * Allocates twice the current storage until total storage is greater
   * than new_cap. new_cap represents the total storage elements needed
   */
  void grow_capacity(size_type new_cap)
  {
    if (new_cap == 0)
      new_cap = 1;
    while (m_end_of_storage - m_start < static_cast<long>(new_cap))
    {
        reserve((m_end_of_storage - m_start) * 2);
    }
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
        m_create_storage(1);
        typedef typename iterator_traits<InputIt>::iterator_category Iter_category;
      insert_dispatch(begin(), first, last, Iter_category());
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
    clear();
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
    return *this;
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
    int i = 0;
    InputIt tmp = first;

    while (tmp != last)
    {
      i++;
      tmp++;
    }
    m_alloc.deallocate(m_start, m_end_of_storage - m_start);
    m_create_storage(i);
    for (size_type i = 0; first != last; ++first, ++i)
      *(m_start + i) = *(first);
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
    return *(end() - 1);
  }

  const_reference back() const {
    return *(end() - 1);
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
    if (empty())
      return reverse_iterator(this->m_finish);
    return reverse_iterator(this->m_finish - 1);
  }

  const_reverse_iterator rbegin() const
  {
    if (empty())
      return reverse_iterator(this->m_finish);
    return const_reverse_iterator(this->m_finish - 1);
  }

  reverse_iterator rend() {
    return reverse_iterator(this->m_start - 1);
  }

  const_reverse_iterator rend() const
  {
    return const_reverse_iterator(this->m_start - 1);
  }

  bool empty() const {
    return begin() == end();
  }

  size_type size() const {
    return std::distance(begin(), end());
  }

  size_type max_size() const {
    return (get_allocator().max_size());
  }
  size_type capacity() const {
    return m_end_of_storage - m_start;
  }

  void reserve(size_type new_cap) {
    if (new_cap == 0)
      new_cap = 1;
    if (new_cap <= capacity())
        return;
    if (new_cap > max_size())
        throw std::length_error("Can't reserve vector size: bigger than max_size()");

    pointer new_m_start;
    pointer new_m_finish;

    new_m_start = m_alloc.allocate(new_cap);
    new_m_finish = m_construct_storage(new_m_start, m_start, m_finish);
    //destroy_storage(m_start, m_finish);
    m_alloc.deallocate(m_start, capacity());
    m_start = new_m_start;
    m_finish = new_m_finish;
    m_end_of_storage = m_start + new_cap;
  }

  void clear()
  {
    destroy_storage(m_start, m_finish);
    m_finish = m_start;
  }

  template <typename InputIt>
  void insert_dispatch(iterator pos, InputIt first, InputIt last, std::input_iterator_tag)
  {
    difference_type offset = pos - begin();
    vector<value_type> tmp(begin(), end());
    iterator ite = tmp.begin();

    clear();
    for (difference_type i = 0; i < offset; ++i, ++ite)
      push_back(*ite);
    for (; first != last; ++first)
      push_back(*first);
    for (; ite != tmp.end(); ++ite)
      push_back(*ite);
  }

  template <typename InputIt>
  void insert_dispatch(iterator pos, InputIt first, InputIt last, std::forward_iterator_tag)
  {
    difference_type offset = pos - begin();
    difference_type count = 0;

    for (InputIt tmp = first; tmp != last; ++tmp)
      ++count;
    grow_capacity(count + offset);
    for (iterator ite = end() + count - 1; ite != begin() + offset + count - 1; --ite)
        *ite = *(ite - count);
    for (; first != last; ++first, ++offset)
      *(begin() + offset) = *first;
    m_finish += count;
  }

  void insert(iterator pos, size_type count, const T& value)
  {
    difference_type offset = pos - begin();
    
    grow_capacity(m_end_of_storage - m_start + count);
    for (iterator ite = end() + count - 1; ite != begin() + offset + count - 1; --ite)
        *ite = *(ite - count);
    for (size_type i = 0; i < count; ++i)
        *(begin() + offset + i) = value;
    m_finish += count;
  }

  iterator insert(iterator pos, const T& value)
  {
    grow_capacity(m_end_of_storage - m_finish + 1);
    for (iterator ite = end(); ite != begin() && ite != pos; --ite)
        *ite = *(ite - 1);
    m_finish++;
    if (!pos.base())
    {
      *begin() = value;
      return begin();
    }
    else
    {
      *pos = value;
      return pos;
    }
  }

  template <typename InputIt>
    void insert(iterator pos, typename std::enable_if<!(std::is_integral<InputIt>::value), InputIt>::type first, InputIt last)
    {
      typedef typename iterator_traits<InputIt>::iterator_category Iter_category;
      insert_dispatch(pos, first, last, Iter_category());
    }

  iterator erase(iterator pos)
  {
    destroy_storage(pos, pos);
    for (iterator ite = pos; ite != end(); ++ite)
    {
      *ite = *(ite + 1);
    }
    m_finish--;
    return pos;
  }

  iterator erase(iterator first, iterator last)
  {
    destroy_storage(first, last);
    for (iterator ite = first; ite != end(); ++ite)
    {
      *ite = *(ite + (last - first));
    }
    m_finish -= (last - first);
    return first;
  }

  void push_back(const T& value)
  {
    grow_capacity(size() + 1);
    *m_finish = value;
    m_finish++;
  }

  void pop_back()
  {
    erase(end() - 1);
  }

  void resize(size_type count, T value = T())
  {
    if (count > size())
    {
      grow_capacity(count);
      for (iterator ite = end(); static_cast<size_type>(ite - begin()) <= count; ++ite)
      {
        *ite = value;
      }
      m_finish = begin().base() + count;
    }
    else if (count < size())
    {
      destroy_storage(begin() + count, end());
      m_finish = begin().base() + count;
    }
  }
  
  void swap(vector& other)
  {
    std::swap(m_start, other.m_start);
    std::swap(m_finish, other.m_finish);
    std::swap(m_end_of_storage, other.m_end_of_storage);
  }
};

  template <typename T, typename Alloc>
bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
  typename vector<T, Alloc>::size_type i = 0;
  for (; lhs.begin() + i != lhs.end(); ++i)
  {
    if (lhs.begin() + i != rhs.begin() + i)
      return 0;
  }
  if (rhs.begin() + i != rhs.end())
    return 0;
  return 1;
}

  template <typename T, typename Alloc>
bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
  if (!(lhs == rhs))
    return 1;
  return 0;
}

  template <typename T, typename Alloc>
bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
  if (lhs.last() - lhs.begin() > rhs.last() - rhs.begin())
    return 0;
  if (lhs.last() - lhs.begin() < rhs.last() - rhs.begin())
    return 1;
  for (typename vector<T, Alloc>::size_type i = 0; lhs.begin + i != lhs.end(); ++i)
  {
    if (lhs.begin() + i < rhs.begin() + i)
      return 1;
    if (lhs.begin() + i > rhs.begin() + i)
      return 0;
  }
  return 0;
}

  template <typename T, typename Alloc>
bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
  if (lhs.last() - lhs.begin() > rhs.last() - rhs.begin())
    return 0;
  if (lhs.last() - lhs.begin() < rhs.last() - rhs.begin())
    return 1;
  for (typename vector<T, Alloc>::size_type i = 0; lhs.begin + i != lhs.end(); ++i)
  {
    if (lhs.begin() + i < rhs.begin() + i)
      return 1;
    if (lhs.begin() + i > rhs.begin() + i)
      return 0;
  }
  return 1;
}

  template <typename T, typename Alloc>
bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
  if (lhs.last() - lhs.begin() < rhs.last() - rhs.begin())
    return 0;
  if (lhs.last() - lhs.begin() > rhs.last() - rhs.begin())
    return 1;
  for (typename vector<T, Alloc>::size_type i = 0; lhs.begin + i != lhs.end(); ++i)
  {
    if (lhs.begin() + i > rhs.begin() + i)
      return 1;
    if (lhs.begin() + i < rhs.begin() + i)
      return 0;
  }
  return 0;
}

  template <typename T, typename Alloc>
bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
{
  if (lhs.last() - lhs.begin() < rhs.last() - rhs.begin())
    return 0;
  if (lhs.last() - lhs.begin() > rhs.last() - rhs.begin())
    return 1;
  for (typename vector<T, Alloc>::size_type i = 0; lhs.begin + i != lhs.end(); ++i)
  {
    if (lhs.begin() + i > rhs.begin() + i)
      return 1;
    if (lhs.begin() + i < rhs.begin() + i)
      return 0;
  }
  return 1;
}

  template <typename T, typename Alloc>
void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
{
  lhs.swap(rhs);
}

}
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
//  *     - [x] 1.  bool empty() const;
//  *     - [x] 1.  size_type size() const;
//  *     - [x] 1.  size_type max_size() const;
//  *     - [x] 1.  void reserve( size_type new_cap );
//  *     - [x] 1.  size_type capacity() const;
//  *
//  *   MODIFIERS
//  *     - [x] 1.  void clear();
//  *     - [x] 1.  iterator insert( iterator pos, const T& value );
//  *     - [x] 3.  void insert( iterator pos, size_type count, const T& value);
//  *     - [x] 4.  template< class InputIt >
//  *                   void insert( iterator pos, InputIt first, InputIt last );
//  *     - [x] 1.  iterator erase( iterator pos );
//  *     - [x] 2.  iterator erase( iterator first, iterator last );
//  *     - [x] 1.  void push_back( const T& value );
//  *     - [x] 1.  void pop_back();
//  *     - [x] 2.  void resize( size_type count, T value = T() );
//  *     - [x] 1.  void swap( vector& other );
//  *
//  * NON-MEMBER FUNCTIONS
//  *   - [x] 1.  template< class T, class Alloc >
//  *       bool operator==( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [x] 2.  template< class T, class Alloc >
//  *       bool operator!=( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [x] 3.  template< class T, class Alloc >
//  *       bool operator<( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [x] 4.  template< class T, class Alloc >
//  *       bool operator<=( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [x] 5.  template< class T, class Alloc >
//  *       bool operator>( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [x] 6.  template< class T, class Alloc >
//  *       bool operator>=( const std::vector<T,Alloc>& lhs, const
//  std::vector<T,Alloc>& rhs );
//  *   - [x] 1.  template< class T, class Alloc >
//  *       void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );
