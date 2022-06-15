#pragma once

#include <iostream>
#include "tree_iterator.hpp"

namespace ft {


  template <typename value_type>
    class tree_node
    {
      public:
        tree_node* parent;
        tree_node* left;
        tree_node* right;
        value_type data;
        bool  is_red;
    };

  template <typename value_type,
           typename Compare,
           typename Allocator>
             class rb_tree
             {
               typedef typename Allocator::template rebind<tree_node<value_type>>::other node_allocator;
               typedef tree_node<value_type> tree_node;

               private:
               tree_node  end_node;
               tree_node  root_node;
               node_allocator node_alloc;
               Compare comp;

               private:
                tree_node construct_node()
                {
                  tree_node new_node = node_alloc.allocate(1);
                  new_node->parent = NULL;
                  new_node->left = NULL;
                  new_node->right = NULL;
                  new_node->data = value_type();
                  new_node->is_red = false;
                }

                public:

               rb_tree() : node_alloc(node_allocator())
               {
                  end_node = construct_node();
               }

               void insert(const value_type& value)
               {
                
               }


             };
}
