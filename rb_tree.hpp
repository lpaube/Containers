#pragma once

#include "iterator.hpp"
#include "rbt_iterator.hpp"
#include "rbt_node.hpp"
#include "utils.hpp"
#include <iostream>

namespace ft {
  template <typename value_type, typename Compare, typename Allocator>
    class rb_tree {
      /*
       * Member types
       */
      public:
        typedef typename Allocator::template rebind<rbt_node<value_type> >::other
          node_allocator;
        typedef rbt_node<value_type> tree_node;
        typedef tree_node *tree_node_ptr;
        typedef Allocator pair_allocator;
        typedef rbt_iterator<value_type, Compare> iterator;
        typedef rbt_const_iterator<value_type, Compare> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

        typedef typename node_allocator::size_type size_type;
        typedef Compare value_compare;

        /*
         * Member variables
         */
      private:
        tree_node_ptr end_node_;
        tree_node_ptr root_node_;
        node_allocator node_alloc_;
        pair_allocator pair_alloc_;
        Compare comp_;

        /*
         * Member functions
         */
      public:
        // tree constructor
        rb_tree(const Compare &comp = Compare(),
            const pair_allocator &alloc = pair_allocator())
          : root_node_(NULL), end_node_(construct_node()), pair_alloc_(alloc),
          node_alloc_(node_allocator()), comp_(comp) {}

        template <typename InputIt>
          rb_tree(InputIt first, InputIt last, const Compare &comp = Compare(),
              const pair_allocator &alloc = pair_allocator())
          : root_node_(NULL), end_node_(construct_node()), pair_alloc_(alloc),
          node_alloc_(node_allocator()), comp_(comp) {
            insert(first, last);
          }

        pair<iterator, bool> insert(const value_type &value) {
          tree_node_ptr node_constructed;
          bool can_construct;

          // #1 - If tree is empty, create new root black
          if (root_node_ == NULL) {
            root_node_ = construct_node(value, end_node_);
            root_node_->is_black = true;
            end_node_->left = root_node_;
            node_constructed = root_node_;
            can_construct = true;
            return pair<iterator, bool>(node_constructed, can_construct);
          }


          // If key already exists, parent_node is existing node and bool is false
          pair<tree_node_ptr, bool> parent_node = find_parent_pos(value, root_node_);

          if (parent_node.second == false) {
            node_constructed = parent_node.first;
            can_construct = false;
            return pair<iterator, bool>(iterator(node_constructed), can_construct);
          }

          // Add new node to tree
          if (comp_(value.first, parent_node.first->data.first) == true) {
            parent_node.first->left = construct_node(value, parent_node.first);
            node_constructed = parent_node.first->left;
            can_construct = true;
          } else {
            parent_node.first->right = construct_node(value, parent_node.first);
            node_constructed = parent_node.first->right;
            can_construct = true;
          }

          // #2 - If tree is not empty, make new node red

          if (node_constructed->parent->is_black == true)
          {
            return pair<iterator, bool>(iterator(node_constructed), can_construct);
          }
          rb_insertion_check(node_constructed);
          return pair<iterator, bool>(iterator(node_constructed), can_construct);
        }

        void rb_insertion_check(tree_node_ptr node)
        {
          std::cerr << "Checking insertion_check" << std::endl;
          while (node->parent->is_black == false)
          {
            tree_node_ptr uncle = get_uncle(node);
            // If parent is a left child
            if (node->parent == node->parent->parent->left)
            {
              // CASE #1
              // If color of uncle is red
              if (uncle && uncle->is_black == false)
              {
                node->parent->is_black = true;
                uncle->is_black = true;
                node->parent->parent->is_black = false;
              }
              // If color of uncle is black
              else
              {
                // CASE #2
                // If subtree form a triangle
                if (node == node->parent->right)
                {
                  node = node->parent;
                  left_rotation(node);
                }
                // CASE #3
                // If subtree form a line
                node->parent->is_black = true;
                node->parent->parent->is_black = false;
                right_rotation(node->parent->parent);
              }
            }
            // If parent is a right child
            else
            {
              // CASE #1
              // If color of uncle is red
              if (uncle && uncle->is_black == false)
              {
                node->parent->is_black = true;
                uncle->is_black = true;
                node->parent->parent->is_black = false;
              }
              // If color of uncle is black
              else
              {
                // CASE #2
                // If subtree form a triangle
                if (node == node->parent->left)
                {
                  node = node->parent;
                  right_rotation(node);
                }
                // CASE #3
                // If subtree form a line
                node->parent->is_black = true;
                node->parent->parent->is_black = false;
                left_rotation(node->parent->parent);
              }
            }
          }
        }

        int left_rotation(tree_node_ptr node_x)
        {
          if (node_x->right == NULL)
            return 0;
          tree_node_ptr node_y = node_x->right;
          // Move node_y to root of subtree
          if (node_x->parent->left == node_x)
            node_x->parent->left = node_y;
          else if (node_x->parent->right == node_x)
            node_x->parent->right = node_y;
          node_y->parent = node_x->parent;

          // Previous left child of node_y becomes right child of x
          node_x->right = node_y->left;

          // node_x becomes left child of node_y
          node_y->left = node_x;
          node_x->parent = node_y;

          return 1;
        }

        int right_rotation(tree_node_ptr node_x)
        {
          if (node_x->left == NULL)
            return 0;
          tree_node_ptr node_y = node_x->left;
          // Move node_y to root of subtree
          if (node_x->parent->left == node_x)
            node_x->parent->left = node_y;
          else if (node_x->parent->right == node_x)
            node_x->parent->right = node_y;
          node_y->parent = node_x->parent;

          // Previous left child of node_y becomes right child of x
          node_x->left = node_y->right;

          // node_x becomes left child of node_y
          node_y->right = node_x;
          node_x->parent = node_y;

          return 1;
        }

        void change_color(tree_node_ptr node)
        {
          if (node)
          {
            if (node->is_black == true)
              node->is_black = false;
            else
              node->is_black = true;
          }
        }

        tree_node_ptr get_uncle(const tree_node_ptr node) const
        {
          tree_node_ptr parent = node->parent;

          if (parent == root_node_)
            return NULL;
          if (parent == parent->parent->right)
            return parent->parent->left;
          else
            return parent->parent->right;
        }

        iterator insert(iterator hint, const value_type &value) {}

        template <typename InputIt> void insert(InputIt first, InputIt last) {
          while (first != last) {
            insert(*first);
            ++first;
          }
        }

        void destroy_node(tree_node_ptr node) {
          pair_alloc_.destroy(&node->data);
          node_alloc_.deallocate(node, 1);
        }

        void erase(iterator pos) {
          tree_node_ptr node = pos.base();

          // If the node has no children
          if (!node->left && !node->right) {
            if (node == node->parent->left) {
              node->parent->left = NULL;
            } else {
              node->parent->right = NULL;
            }
            destroy_node(node);
          }
          // If the node to delete only has a right child
          else if (!node->left && node->right) {
            if (node == node->parent->left) {
              node->parent->left = node->right;
            } else {
              node->parent->right = node->right;
            }
            destroy_node(node);
          }
          // If the node to delete only has a left child
          else if (node->left && !node->right) {
            if (node == node->parent->left) {
              node->parent->left = node->left;
            } else {
              node->parent->right = node->left;
            }
            destroy_node(node);
          }
          // If the node to delete has 2 children
          else {
            tree_node_ptr next_node = get_next_node(node);

            destroy_node(node);
            node = construct_node(next_node->data);
            erase(++pos);
          }
        }

        void erase(iterator first, iterator last) {}

        template <typename Key> size_type erase(const Key &key) {}

        iterator begin() { return iterator(get_first_node(root_node_)); }

        const_iterator begin() const {
          return const_iterator(get_first_node(root_node_));
        }

        iterator end() { return iterator(end_node_); }

        const_iterator end() const { return const_iterator(end_node_); }

        template <typename Key> iterator find(const Key &key) {
          iterator tmp_it = begin();
          while (tmp_it != end()) {
            if (tmp_it->first == key)
              return tmp_it;
            ++tmp_it;
          }
          return end();
        }

        template <typename Key, typename Value> Value &at(const Key &key) {
          iterator it = find(key);

          if (it == end())
            throw std::out_of_range("Error: at: cannot find element");
          return it->second;
        }

        bool empty() const {
          if (end_node_->left == NULL && end_node_->right == NULL)
            return true;
          return false;
        }

        size_type size() const {
          size_type counter = 0;
          const_iterator it = begin();

          while (it != end()) {
            ++it;
            ++counter;
          }
          return counter;
        }

        size_type max_size() const { return node_alloc_.max_size(); }

        void print_tree() { inorder(root_node_, &rb_tree::print_node); }

      private:
        tree_node_ptr get_next_node(tree_node_ptr node) {
          if (node->right != NULL) {
            node = node->right;
            while (node->left != NULL) {
              node = node->left;
            }
            return node;
          } else {
            while (node->parent != NULL && node->parent->right == node) {
              node = node->parent;
            }
            node = node->parent;
            return node;
          }
        }

        tree_node_ptr get_prev_node(tree_node_ptr node) {
          if (node->left != NULL) {
            node = node->left;
            while (node->right != NULL) {
              node = node->right;
            }
            return *this;
          } else {
            while (node->parent != NULL && node->parent->left == node) {
              node = node->parent;
            }
            node = node->parent;
            return *this;
          }
        }

        tree_node_ptr get_first_node(tree_node_ptr node) const {
          if (node == NULL || node->left == NULL)
            return node;
          return get_first_node(node->left);
        }

        tree_node_ptr get_last_node(tree_node_ptr node) const {
          if (node == NULL || node->right == NULL)
            return node;
          return get_last_node(node->right);
        }

        tree_node_ptr construct_node() {
          tree_node_ptr new_node = node_alloc_.allocate(1);
          new_node->parent = NULL;
          new_node->left = NULL;
          new_node->right = NULL;
          new_node->is_black = true;
          return new_node;
        }

        tree_node_ptr construct_node(const value_type &new_value) {
          tree_node_ptr new_node = node_alloc_.allocate(1);
          new_node->parent = NULL;
          new_node->left = NULL;
          new_node->right = NULL;
          new_node->is_black = false;
          pair_alloc_.construct(&new_node->data, new_value);
          return new_node;
        }

        tree_node_ptr construct_node(const value_type &new_value,
            const tree_node_ptr parent) {
          tree_node_ptr new_node = node_alloc_.allocate(1);
          new_node->parent = parent;
          new_node->left = NULL;
          new_node->right = NULL;
          new_node->is_black = false;
          pair_alloc_.construct(&new_node->data, new_value);
          return new_node;
        }

        // Returns the parent node of the new (non-existant) node with value
        // bool is true when we can add node; bool is false when value.first already
        // exists
        pair<tree_node_ptr, bool> find_parent_pos(const value_type &value,
            tree_node_ptr node) {
          if (value.first == node->data.first)
            return pair<tree_node_ptr, bool>(end_node_, false);
          if (comp_(value.first, node->data.first) == true) {
            if (node->left == NULL)
              return pair<tree_node_ptr, bool>(node, true);
            else
              return find_parent_pos(value, node->left);
          } else {
            if (node->right == NULL)
              return pair<tree_node_ptr, bool>(node, true);
            else
              return find_parent_pos(value, node->right);
          }
        }

        static void print_node(const tree_node_ptr node) {
          std::cout << "Key: " << node->data.first
            << " | Value: " << node->data.second << std::endl;
        }

        void inorder(tree_node_ptr node, void (*f)(tree_node_ptr)) {
          if (node == NULL)
            return;
          inorder(node->left, f);
          f(node);
          inorder(node->right, f);
        }
    };
} // namespace ft
