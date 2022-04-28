#include <iterator>
#include <functional>
#include "iterator.hpp"

namespace ft {
  template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>>>
    class map {
      typedef Key                                            key_type;
      typedef T                                              mapped_type;
      typedef std::pair<const Key, T>                        value_type;
      typedef std::size_t                                    size_type;
      typedef std::ptrdiff_t                                 difference_type;
      typedef Compare                                        key_compare;
      typedef Allocator                                      allocator_type;
      typedef value_type&                                    reference;
      typedef const value_type&                              const_reference;
      typedef typename Allocator::pointer                    pointer;
      typedef typename Allocator::const_pointer              const_pointer;
      typedef typename ft::normal_iterator<value_type>       iterator;
      typedef typename ft::normal_iterator<const value_type> const_iterator;
      typedef typename ft::reverse_iterator<iterator>        reverse_iterator;
      typedef typename ft::reverse_iterator<const_iterator>  const_reverse_iterator;

      class value_compare {
        
      };
      
      pointer   m_start;
      pointer   m_finish;
      pointer   m_end_of_storage;
      Allocator m_alloc;
      key_compare compare;

      map() : m_start(), m_finish(), m_end_of_storage(), m_alloc(), compare() {}

      explicit map(const Compare& comp, const Allocator& alloc = Allocator())
        : m_start(), m_finish(), m_end_of_storage(), m_alloc(), compare(comp) {}


    };
}
