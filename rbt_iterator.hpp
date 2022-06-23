#pragma once

#include <iostream>

namespace ft {
  template<typename T>
    class rbt_iterator
    {
      public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

      protected:

        pointer current_;

      public:

        rbt_iterator(const pointer elem) : current_(elem) {}

        reference operator*() const {
          return *current_;
        }

        pointer operator->() const { return current_; }

        rbt_iterator& operator=(const rbt_iterator& other)
        {
          current_ = other.current_;
          return *this;
        }

        rbt_iterator& operator++() {
          ++current_;
          return *this;
        }

        rbt_iterator operator++(int) { return rbt_iterator(current_++); }

        // Bidirectional iterator overloads
        rbt_iterator& operator--() {
          --current_;
          return *this;
        }

        rbt_iterator operator--(int) {
          return rbt_iterator(current_--);
        }

        const pointer& base() const { return current_; }

    };
}
