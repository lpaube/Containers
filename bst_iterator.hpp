#pragma once

#include "bst.hpp"

class bst_node;

namespace ft {
  template <typename T>
    class bst_iterator {
      public:
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;

        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t                       difference_type;

      private:
        bst_node* node;

      public:

        bst_iterator() {
node = new bst_node;
        }

        explicit bst_iterator(bst_node* x) : node(x) {}
    };
}
