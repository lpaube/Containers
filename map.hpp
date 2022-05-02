#pragma once

#include <functional>
#include <iostream>
#include <iterator>

#include "bst.hpp"
#include "iterator.hpp"

namespace ft {
template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<std::pair<const Key, T>>>
class map {
 public:
    typedef  Key                                            key_type;                                                      
    typedef  T                                              mapped_type;                                                   
    typedef  std::pair<const Key,T>                         value_type;
    typedef  std::size_t                                    size_type;                                                     
    typedef  std::ptrdiff_t                                 difference_type;                                               
    typedef  Compare                                        key_compare;                                                   
    typedef  Allocator                                      allocator_type;                                                
    typedef  value_type&                                    reference;                                                     
    typedef  const value_type&                              const_reference;         
    typedef  typename Allocator::pointer                    pointer;                 
    typedef  typename Allocator::const_pointer              const_pointer;           
    typedef  typename bst<Key, T>::bst_iterator             iterator;                
    //typedef  typename bst<Key, T>::bst_iterator           const_iterator;
    //typedef  typename ft::reverse_iterator<iterator>      reverse_iterator;        
    //typedef  typename ft::reverse_iterator<const_iterator>  const_reverse_iterator;  

    class value_compare
      : public std::binary_function<value_type, value_type, bool> {
        typedef  bool        result_type;
        typedef  value_type  first_argument_type;
        typedef  value_type  second_argument_type;
  };

  bst<Key, T, Allocator> bst_map;
  key_compare compare;
  Allocator alloc;
  

  explicit map(const key_compare& comp = key_compare(),
               const Allocator& alloc = Allocator()) : alloc(alloc), compare(comp) {
  }

  template <class InputIt>
  map(InputIt first, InputIt last, const Compare& comp = Compare(),
      const Allocator& alloc = Allocator()) {
    for (int i = 0; first + i != last; ++i)
    {
      *(begin() + i) = *(first + i);
    }
  }

  map(const map& other) {}

  iterator begin()
  {
    return iterator(bst_map.get_mix()->data);
  }

  iterator end()
  {
    return iterator(bst_map.get_max()->data);
  }
};
}  // namespace ft
