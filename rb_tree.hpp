#pragma once

#include <iostream>
#include "tree_iterator.hpp"

namespace ft {


  template <typename value_type>
    class rbt_node
    {
      public:
        rbt_node* parent;
        rbt_node* left;
        rbt_node* right;
        value_type data;
        bool  is_red;
    };

  template <typename value_type,
           typename Compare,
           typename Allocator>
             class rb_tree
             {
               typedef typename Allocator::template rebind<rbt_node<value_type> >::other node_allocator;
               typedef rbt_node<value_type> tree_node;
               typedef tree_node*           tree_node_ptr;

               private:
               tree_node_ptr  end_node_;
               tree_node_ptr  root_node_;
               node_allocator node_alloc_;
               Compare comp;

               private:
                tree_node_ptr construct_node()
                {
                  tree_node_ptr new_node = node_alloc_.allocate(1);
                  new_node->parent = NULL;
                  new_node->left = NULL;
                  new_node->right = NULL;
                  new_node->is_red = false;
                  return new_node;
                }

                tree_node_ptr construct_node(value_type new_value)
                {
                  tree_node_ptr new_node = node_alloc_.allocate(1);
                  new_node->parent = NULL;
                  new_node->left = NULL;
                  new_node->right = NULL;
                  new_node->is_red = false;
                  node_alloc_.consturct(new_node, new_value);
                  return new_node;
                }

                public:

               rb_tree() : node_alloc_(node_allocator())
               {
                  end_node_ = construct_node();
               }

               void insert(const value_type& value)
               {
                  if (root_node_ == NULL)
                  {
                    root_node_ = construct_node(value);
                  }
                  else
                  {

                  }
               }
             };
}
