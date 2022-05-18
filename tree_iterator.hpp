#pragma once

#include <iostream>

#include "rb_tree.hpp"
#include "map.hpp"

namespace ft {
  template <typename Tp>
    class tree_iterator
    {
      typedef std::bidirectional_iterator_tag category;
      typedef ptrdiff_t                       difference_type;
      typedef Tp                              value_type;
      typedef Tp*                             pointer;
      typedef Tp&                             reference;

      pointer current;

      tree_iterator() : current(pointer()) {}

      tree_iterator(const pointer& i) : current(i) {}

      /*
       * Forward iterator overloads
       */
      reference operator*() const {
        return *current;
      }

      const tree_iterator& base() const { return current; }

      pointer operator->() const { return current; }

      tree_iterator& operator++()
      {
        ++current;
        return *this;
      }

      tree_iterator& operator=(const tree_iterator& other)
      {
        current = other.current;
        return *this;
      }

      tree_iterator operator++(int) { return tree_iterator(current++); }

      /*
       * Bidirectional iterator overloads
       */
        tree_iterator& operator--() {
          --current;
          return *this;
        }

        tree_iterator operator--(int) {
          return tree_iterator(current--);
        }
    };

  /*
   * Forward iterator non-member oberloads
   */
  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator==(const tree_iterator<IteratorL>& lhs,
        const tree_iterator<IteratorR>& rhs) {
      return lhs.base() == rhs.base();
    }

  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator!=(const tree_iterator<IteratorL>& lhs,
        const tree_iterator<IteratorR>& rhs) {
      return lhs.base() != rhs.base();
    }
}
