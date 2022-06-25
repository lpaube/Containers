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

        rbt_iterator(const tree_node_ptr node) : current_(node), comp_(Compare()) { }

        reference operator*() const {
          return current_->data;
        }

        pointer operator->() const { return &current_->data; }

        rbt_iterator& operator=(const rbt_iterator& other)
        {
          current_ = other.current_;
          return *this;
        }

        rbt_iterator& operator++() {
          if (current_->right != NULL)
          {
            current_ = current_->right;
            while (current_->left != NULL)
            {
              current_ = current_->left;
            }
            return *this;
          }
          else
          {
            while (current_->parent != NULL
                && current_->parent->right == current_)
            {
              current_ = current_->parent;
            }
            current_ = current_->parent;
            return *this;
          }
        }

        rbt_iterator operator++(int) {
          rbt_iterator tmp_it = *this;
          ++(*this);
          return tmp_it;
        }

        rbt_iterator& operator--() {
          if (current_->left != NULL)
          {
            current_ = current_->left;
            while (current_->right != NULL)
            {
              current_ = current_->right;
            }
            return *this;
          }
          else
          {
            while (current_->parent != NULL
                && current_->parent->left == current_)
            {
              current_ = current_->parent;
            }
            current_ = current_->parent;
            return *this;
          }
        }

        rbt_iterator operator--(int) {
          rbt_iterator tmp_it = *this;
          --(*this);
          return tmp_it;
        }

        bool operator==(const rbt_iterator& other)
        {
          return current_ == other.base();
        }

        bool operator!=(const rbt_iterator& other)
        {
          return !(*this == other);
        }

        const tree_node_ptr base() const { return current_; }

    };
}
