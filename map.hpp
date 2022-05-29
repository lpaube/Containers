#pragma once

#include <iostream>
#include <map>
#include "iterator.hpp"
#include "rb_tree.hpp"
#include "tree_iterator.hpp"

namespace ft {

  template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {    
      public:

      /*
       * Member types
       */
      typedef  Key                                                       key_type;                                                      
      typedef  T                                                         mapped_type;                                                   
      typedef  std::pair<const Key, T>                                   value_type;
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

      /*
       * std::map::value_compare is a function object that compares objects 
       * of type std::map::value_type (key-value pairs) by comparing of the
       * first components of the pairs.
       */
      class value_compare
      {
        protected:
          Compare comp;

        public:
          typedef bool result_type;
          typedef value_type first_argument_type;
          typedef value_type second_argument_type;

        protected:
          value_compare(Compare c) : comp(c) {}

        public:
          bool operator()(const value_type& lhs, const value_type& rhs) const
          {
            comp(lhs.first, rhs.first);
          }
      };

      public:
      /*
       * Map constructors
       */
      map() : tree()
      {
      }

      explicit map(const Compare& comp,
          const Allocator& alloc = Allocator())
        : tree(), compare(comp), alloc(alloc)
      {
      }

      template<typename InputIt>
        map(InputIt first, InputIt last,
            const Compare& comp = Compare(),
            const Allocator& alloc = Allocator())
        : tree(), compare(comp), alloc(alloc)
        {
          tree.insert(first, last);
        }

      map(const map& other) : tree(other.tree)
      {
      }

      /*
       * Map destructor
       */
      ~map()
      {
        tree.destroy();
      }

      /*
       * Map copy assignment operator
       */
      map& operator=(const map& other)
      {
        tree = other.tree;
        return *this;
      }

      /*
       * Returns the allocator associated with the container
       */
      allocator_type get_allocator() const
      {
        return alloc;
      }

      /*
       * Element access
       */
      T& at(const Key& key)
      {
        // Need to do error checking here (std::out_of_range)
        iterator ite = find(key);
        return (*ite).second;
      }

      /*
       * Iterators
       */
      


      /*
       * Modifiers
       */
      void insert(value_type value)
      {
        tree.insert(value);
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
