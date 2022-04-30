#pragma once

#include <iostream>
#include <iterator>
#include <functional>
#include "iterator.hpp"


namespace ft {

  template <typename Key, typename T>
    class bst {
      public:

        struct bst_node {

          public:
            typedef typename std::pair<Key, T>  data_type;

            data_type  data;
            bst_node*  parent;
            bst_node*  left;
            bst_node*  right;
        };

        bst_node* root;

        bst() : root(nullptr) {
          std::cout << "Regular Constructor of bst" << std::endl;
        }
        bst(typename bst_node::data_type data) {
          root = nullptr;
          root = insert(data, root);
        }

        bst_node* insert(typename bst_node::data_type x, bst_node* node)
        {
          if (node == nullptr)
          {
            node = new bst_node;
            node->data = x;
            node->left = nullptr;
            node->right = nullptr;
          }
          else if (x.first <= node->data.first)
            node = insert(node->left);
          else if (x.first > node->data.first)
            node = insert(node->right);
          return node;
        }

        void remove_leaf(Key key_name, bst_node* node)
        {
          if (key_name == node->left->data.first)
          {
            if (node->left == nullptr && node->right == nullptr)
            {
              delete node->left;
              node->left = nullptr;
            }
          }
          else if (key_name == node->right->data.first)
          {
            if (node->left == nullptr && node->right == nullptr)
            {
              delete node->right;
              node->right = nullptr;
            }
          }
        }

        void remove(Key key_name, bst_node* node) {

          if (key_name < node->data.first)
          {
            remove_leaf(key_name, node);
          }
          if (key_name > node->data.first)
          {
            remove_leaf(key_name, node);
          }
        }
    };

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

      bool        color;
      pointer     parent;
      pointer     left;
      pointer     right;
      key_compare compare;

      map() : color(), parent(), left(){}

    };
}
