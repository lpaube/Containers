#pragma once

#include <iostream>
#include <map>
#include "iterator.hpp"
#include "rb_tree.hpp"
#include "tree_iterator.hpp"

namespace ft {

  template <typename Key,
            typename T,
            typename Compare = std::less<Key>,
            typename Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {    
      public:

       //* ======================= Member types ===================== *
      typedef  Key                                                       key_type;                                                      
      typedef  T                                                         mapped_type;                                                   
      typedef  pair<const Key, T>                                        value_type;
      typedef  std::size_t                                               size_type;                                                     
      typedef  std::ptrdiff_t                                            difference_type;                                               
      typedef  Compare                                                   key_compare;                                                   
      typedef  Allocator                                                 allocator_type;                                                
      typedef  value_type&                                               reference;                                                     
      typedef  const value_type&                                         const_reference;         
      typedef  typename Allocator::pointer                               pointer;                 
      typedef  typename Allocator::const_pointer                         const_pointer;           
      typedef  tree_iterator<value_type>                                 iterator;                
      typedef  tree_iterator<const value_type>                           const_iterator;
      typedef  typename ft::reverse_iterator<iterator>                   reverse_iterator;        
      typedef  typename ft::reverse_iterator<const_iterator>             const_reverse_iterator;  

      private:
      rb_tree<value_type, allocator_type> tree;
      Allocator alloc;
      Compare compare;

      public:
       //* ======================= Member functions ===================== *
       
       // Map constructors 
      map()
      {
      }

      explicit map(const Compare& comp,
          const Allocator& alloc = Allocator())
      {
      }

      template<typename InputIt>
        map(InputIt first, InputIt last,
            const Compare& comp = Compare(),
            const Allocator& alloc = Allocator())
        {
        }

      map(const map& other)
      {
      }

      // Map destructor
      ~map()
      {
      }

      // Map assignment operator overload
      map& operator=(const map& other)
      {
      }

      // Map allocator getter
      allocator_type get_allocator() const
      {
      }

      // Element access
      T& at(const Key& key)
      {
      }

      const T& at(const Key& key) const
      {
      }

      T& operator[](const Key& key)
      {
      }

      // Iterators
      iterator begin()
      {
      }
      
      const_iterator begin() const
      {
      }

      iterator end()
      {
      }

      const_iterator end() const
      {
      }

      reverse_iterator rbegin()
      {
      }

      const_reverse_iterator rbegin() const
      {
      }

      reverse_iterator rend()
      {
      }

      const_reverse_iterator rend() const
      {
      }

      // Capacity
      bool empty() const
      {
      }

      size_type size const
      {
      }
      
      size_type max_size() const
      {
      }

      // Modifiers
      void clear()
      {
      }

      ft::pair
      
      
      
      
      void insert(const value_type& value)
      {
      }

      /*
       * Lookup
       */
      iterator find(const Key& key)
      {
        return tree.find(key);
      }

      const_iterator find(const Key& key) const
      {
        return tree.find(key);
      }


      /*
       * Testing purposes
       */
      void print_map()
      {
        tree.print_tree();
      }
    };
}
