#pragma once

#include <iostream>
#include "tree_iterator.hpp"

namespace ft {

  /*
   * This is the implementation of a red-black tree.
   * The template paramenter Tp is a pair<key, value>.
   */
  template <typename Tp, typename Allocator>
    class rb_tree
    {
      public:
        typedef Tp value_type;
        typedef tree_iterator<Tp> iterator;

        struct tree_node 
        {
          tree_node* parent;
          tree_node* left;
          tree_node* right;
          Tp        value;
          bool      is_black;
        };

      private:
        tree_node*                root_node;
        Allocator                 alloc;
        std::allocator<tree_node> node_alloc;

      public:

        rb_tree() : root_node()
      {
        
      }

        tree_node* root()
        {
          return this->root_node;
        }

        tree_node* root() const
        {
          return this->root_node;
        }

        tree_node* leftmost()
        {
          tree_node* tmp = root_node;

          while (tmp->left)
            tmp = tmp->left;
          return tmp;
        }

        tree_node* leftmost(tree_node* start)
        {
          tree_node* tmp = start;

          while (tmp->left)
            tmp = tmp->left;
          return tmp;
        }

        tree_node* rightmost()
        {
          tree_node* tmp = root_node;

          while (tmp->right)
            tmp = tmp->right;
          return tmp;
        }

        tree_node* rightmost(tree_node* start)
        {
          tree_node* tmp = start;

          while (tmp->right)
            tmp = tmp->right;
          return tmp;
        }

        tree_node* create_node(value_type pair)
        {
          tree_node* new_node;

          new_node = node_alloc.allocate(1);
          new_node->value = pair;
          new_node->parent = NULL;
          new_node->left = NULL;
          new_node->right = NULL;

          // Will need to change this to a real red/black checker!
          new_node->is_black = 1;
          return new_node;
        }

        tree_node* insert(const value_type& pair)
        {
          tree_node* tmp = root_node;

          while (tmp != NULL)
          {
            if (pair.first < tmp->value.first)
            {
              if (tmp->left == NULL)
                return tmp->left = create_node(pair);
              tmp = tmp->left;
            }
            else if (pair.first > tmp->value.first)
            {
              if (tmp->right == NULL)
                return tmp->right = create_node(pair);
              tmp = tmp->right;
            }
          }
          return root_node = create_node(pair);
        }

        template <typename InputIt>
        void insert(InputIt first, InputIt last)
        {
          for (; first != last; ++first)
            insert(*first);
        }

        template <typename Key>
        iterator find(const Key& key)
        {
          tree_node* tmp = root_node;

          while (tmp != NULL)
          {
            if (key < tmp->value.first)
            {
              tmp = tmp->left;
            }
            else if (key > tmp->value.first)
            {
              tmp = tmp->right;
            }
            else
              return tree_iterator<value_type>(tmp);
          }
        }

        void print_tree(tree_node* node, int x)
        {
          if (node == NULL)
            return ;
          x++;
          print_tree(node->left, x);
          print_tree(node->right, x);
          std::cout << "Level: " << x << " | "
                    << "Key: " << (node->value).first << " | "
                    << "Value: " << (node->value).second
                    << std::endl;
        }

        void print_tree()
        {
          int x = 0;

          print_tree(root_node, x);
        }

    };
}
