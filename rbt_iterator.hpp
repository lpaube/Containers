#pragma once

#include <iostream>
#include "rbt_node.hpp"

namespace ft {
  template<typename T, typename Compare>
    class rbt_iterator
    {
      public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

      private:
        typedef rbt_node<value_type> tree_node;
        typedef tree_node*            tree_node_ptr;

      protected:
        tree_node_ptr current_;

      private:
        Compare comp_;

      public:

        rbt_iterator(const tree_node_ptr node) : current_(node), comp_(Compare()) {}

        reference operator*() const {
          return current_->data;
        }

        pointer operator->() const { return &current_->data; }

        rbt_iterator& operator=(const rbt_iterator& other)
        {
          current_ = other.current_;
          return *this;
        }

        rbt_iterator operator++() {
          //return tree_increment(current_);
          if (current_ == NULL)
            return NULL;
          if (current_->right != NULL)
          {
            current_ = current_->right;
            while (current_->left != NULL)
            {
              current_ = current_->left;
            }
            return rbt_iterator(current_);
          }
          else
          {
            while (current_->parent != NULL
                && comp_(current_->data.first < current_->parent->data.first) == 1)
            {
              current_ = current_->parent;
            }
            return rbt_iterator(current_->parent);
          }
        }

        rbt_iterator operator++(int) { return rbt_iterator(current_++); }

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
