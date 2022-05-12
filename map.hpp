#include <iostream>
#include <map>
#include "rb_tree.hpp"

namespace ft {
  template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T> > >
    class map
    {    
      public:

      /*
       * Member types
       */
      typedef  Key                                            key_type;                                                      
      typedef  T                                              mapped_type;                                                   
      typedef  std::pair<const Key, T>                        value_type;
      typedef  std::size_t                                    size_type;                                                     
      typedef  std::ptrdiff_t                                 difference_type;                                               
      typedef  Compare                                        key_compare;                                                   
      typedef  Allocator                                      allocator_type;                                                
      typedef  value_type&                                    reference;                                                     
      typedef  const value_type&                              const_reference;         
      typedef  typename Allocator::pointer                    pointer;                 
      typedef  typename Allocator::const_pointer              const_pointer;           
      typedef  typename bst<Key, T>::bst_iterator             iterator;                
      typedef  typename bst<Key, T>::bst_iterator           const_iterator;
      typedef  typename ft::reverse_iterator<iterator>      reverse_iterator;        
      typedef  typename ft::reverse_iterator<const_iterator>  const_reverse_iterator;  

      private:
      ft::rb_tree tree;
        Allocator alloc;

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

      /*
       * Map constructors
       */

      std::map<int, int> test();

    };
}
