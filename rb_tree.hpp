#pragma once

#include <iostream>
#include "rbt_node.hpp"
#include "rbt_iterator.hpp"
#include "iterator.hpp"
#include "utils.hpp"


namespace ft {
  template <typename value_type,
           typename Compare,
           typename Allocator>
             class rb_tree
             {
               /*
                * Member types
                */
               public:
                 typedef typename Allocator::template rebind<rbt_node<value_type> >::other node_allocator;
                 typedef rbt_node<value_type> tree_node;
                 typedef tree_node*           tree_node_ptr;
                 typedef Allocator            pair_allocator;
                 typedef  rbt_iterator<value_type, Compare>                                 iterator;                
                 typedef  rbt_iterator<const value_type, Compare>                           const_iterator;
                 typedef  typename ft::reverse_iterator<iterator>                   reverse_iterator;        
                 typedef  typename ft::reverse_iterator<const_iterator>             const_reverse_iterator;  

                 typedef Compare      value_compare;


                 /*
                  * Member variables
                  */
               private:
                 tree_node_ptr  end_node_;
                 tree_node_ptr  root_node_;
                 node_allocator node_alloc_;
                 pair_allocator pair_alloc_;
                 Compare comp_;

                 /*
                  * Member functions
                  */
               public:
                 // tree constructor
                 rb_tree()
                   : root_node_(NULL)
                     , node_alloc_(node_allocator())
                     , pair_alloc_(pair_allocator())
                     , comp_(Compare())
               {
                 end_node_ = construct_node();
               }

                 void insert(const value_type& value)
                 {
                   if (root_node_ == NULL)
                   {
                     root_node_ = construct_node(value, end_node_);
                     end_node_->left = root_node_;
                     return;
                   }
                   tree_node_ptr parent_node = find_parent_pos(value, root_node_);
                   if (parent_node == end_node_)
                     return;
                   if (comp_(value.first, parent_node->data.first) == true)
                   {
                     parent_node->left = construct_node(value, parent_node);
                   }
                   else
                   {
                     parent_node->right = construct_node(value, parent_node);
                   }
                 }

                 iterator begin()
                 {
                   return iterator(get_first_node(root_node_));
                 }

                 iterator end()
                 {
                   return end_node_;
                 }

                template <typename Key>
                  iterator find(const Key& key)
                  {
                    iterator tmp_it = begin();
                    while (tmp_it != end())
                    {
                      if (tmp_it->data.first == key)
                        return tmp_it;
                      ++tmp_it;
                    }
                    return end();
                  }

                 void print_tree()
                 {
                   inorder(root_node_, &rb_tree::print_node);
                 }

               private:

                 tree_node_ptr get_first_node(tree_node_ptr node)
                 {
                   if (node == NULL || node->left == NULL)
                     return node;
                   return get_first_node(node->left);
                 }

                 tree_node_ptr get_last_node(tree_node_ptr node)
                 {
                   if (node == NULL || node->right == NULL)
                     return node;
                   return get_last_node(node->right);
                 }

                 tree_node_ptr construct_node()
                 {
                   tree_node_ptr new_node = node_alloc_.allocate(1);
                   new_node->parent = NULL;
                   new_node->left = NULL;
                   new_node->right = NULL;
                   new_node->is_red = false;
                   return new_node;
                 }

                 tree_node_ptr construct_node(const value_type& new_value)
                 {
                   tree_node_ptr new_node = node_alloc_.allocate(1);
                   new_node->parent = NULL;
                   new_node->left = NULL;
                   new_node->right = NULL;
                   new_node->is_red = false;
                   pair_alloc_.construct(&new_node->data, new_value);
                   return new_node;
                 }

                 tree_node_ptr construct_node(const value_type& new_value, const tree_node_ptr parent)
                 {
                   tree_node_ptr new_node = node_alloc_.allocate(1);
                   new_node->parent = parent;
                   new_node->left = NULL;
                   new_node->right = NULL;
                   new_node->is_red = false;
                   pair_alloc_.construct(&new_node->data, new_value);
                   return new_node;
                 }

                 // Returns the parent node of the new (non-existant) node with value
                 tree_node_ptr find_parent_pos(const value_type& value, tree_node_ptr node)
                 {
                   if (value.first == node->data.first)
                     return end_node_;
                   if (comp_(value.first, node->data.first) == true)
                   {
                     if (node->left == NULL)
                       return node;
                     else
                       return find_parent_pos(value, node->left);
                   }
                   else
                   {
                     if (node->right == NULL)
                       return node;
                     else
                       return find_parent_pos(value, node->right);
                   }
                 }

                 static void print_node(const tree_node_ptr node)
                 {
                   std::cout << "Key: " << node->data.first << " | Value: " << node->data.second << std::endl;
                 }


                 void inorder(tree_node_ptr node, void (*f)(tree_node_ptr))
                 {
                   if (node == NULL)
                     return;
                   inorder(node->left, f);
                   f(node);
                   inorder(node->right, f);
                 }

             };
}
