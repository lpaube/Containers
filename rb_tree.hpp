#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>

#include "iterator.hpp"
#include "rbt_iterator.hpp"
#include "rbt_node.hpp"
#include "utils.hpp"

//#include "Timer.hpp"


namespace ft {
  template <typename value_type, typename Compare, typename Allocator>
    class rb_tree {
      /*
       * Member types
       */
      public:
        typedef rbt_node<value_type> tree_node;
        typedef tree_node *tree_node_ptr;
        typedef Allocator pair_allocator;
        typedef typename pair_allocator::difference_type pair_difference_type;
        typedef typename Allocator::template rebind<rbt_node<value_type> >::other node_allocator;
        typedef typename node_allocator::difference_type node_difference_type;
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
        size_type size_;

        /*
         * Member functions
         */
      public:

        // tree constructors
        rb_tree(const Compare &comp = Compare(),
            const pair_allocator &alloc = pair_allocator())
          : end_node_(construct_node())
            , root_node_(NULL)
            , node_alloc_(node_allocator())
            , pair_alloc_(alloc)
            , comp_(comp)
            , size_(0)
      {}

        template <typename InputIt>
          rb_tree(InputIt first, InputIt last, const Compare &comp = Compare(),
              const pair_allocator &alloc = pair_allocator())
          : end_node_(construct_node())
            , root_node_(NULL)
            , node_alloc_(node_allocator())
            , pair_alloc_(alloc)
            , comp_(comp)
            , size_(0)
      {
        insert(first, last);
      }

        rb_tree(const rb_tree& other)
          : end_node_(construct_node())
            ,root_node_(NULL)
            , node_alloc_(other.node_alloc_)
            , pair_alloc_(other.pair_alloc_)
            , comp_(other.comp_)
            , size_(0)
      {
        insert(other.begin(), other.end());
      }

        ~rb_tree()
        {
          destroy_tree(end_node_);
          node_alloc_.deallocate(end_node_, 1);
        }


        rb_tree& operator=(const rb_tree& other)
        {
          rb_tree tmp(other);
          swap(tmp);

          return *this;
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
            return pair<iterator, bool>(iterator(node_constructed), can_construct);
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
          check_rb_insertion(node_constructed);
          return pair<iterator, bool>(iterator(node_constructed), can_construct);
        }

        iterator insert(iterator hint, const value_type &value) {
          tree_node_ptr hint_node = hint.base();

          if (hint == end())
            return insert(value).first;
          if (root_node_ == NULL)
          {
            root_node_ = construct_node(value, end_node_);
            return iterator(root_node_);
          }
          if (comp_(hint->first, value.first)
              && comp_(value.first, get_next_node(hint_node)->data.first))
          {
            if (!hint_node->right)
            {
              hint_node->right = construct_node(value, hint_node);
              return iterator(hint_node->right);
            }
            else
            {
              hint_node->right->left = construct_node(value, hint_node->right);
              return iterator(hint_node->right->left);
            }
          }
          else
          {
            return insert(value).first;
          }
        }

        template <typename InputIt> void insert(InputIt first, InputIt last) {
          while (first != last) {
            insert(*first);
            ++first;
          }
        }

        iterator erase(iterator pos) {
          if (pos == end())
            return pos;

          tree_node_ptr node = pos.base();

          // If the node has no children
          if (!node->left && !node->right) {
            check_double_black(node);

            tree_node_ptr next_node = get_next_node(node);

            destroy_node(node);
            return iterator(next_node);
          }

          // If the node to delete has at least a child,
          // replace current node with child and call erase again
          else {
            tree_node_ptr next_node = get_next_node(node);
            tree_node_ptr prev_node = get_prev_node(node);

            if (next_node == end_node_ || next_node->data.first == node->data.first) {
              pair_alloc_.destroy(&node->data);
              pair_alloc_.construct(&node->data, prev_node->data);
              erase(--pos);
              return end();
            } else {
              pair_alloc_.destroy(&node->data);
              pair_alloc_.construct(&node->data, next_node->data);
              erase(++pos);
              return iterator(node);
            }
          }
        }

        template <typename Key>
          void erase(iterator first, iterator last) {

            Key last_key;

            if (last != end())
              last_key = last->first;

            while (first != last)
            {
              first = erase(first);
              if (last != end())
                last = find(last_key);
            }
          }

        template <typename Key> size_type erase(const Key &key) {
          iterator it = find(key);
          if (it == end())
            return 0;
          erase(it);
          return 1;
        }

        void swap(rb_tree& other)
        {
          std::swap(end_node_, other.end_node_);
          std::swap(root_node_, other.root_node_);
          std::swap(node_alloc_, other.node_alloc_);
          std::swap(pair_alloc_, other.pair_alloc_);
          std::swap(comp_, other.comp_);
          std::swap(size_, other.size_);
        }

        template <typename Key>
          size_type count(const Key& key) const
          {
            if (find(key) != end())
              return 1;
            return 0;
          }

        iterator begin() {
          return iterator(get_first_node(root_node_));
        }

        const_iterator begin() const {
          return const_iterator(get_first_node(root_node_));
        }

        iterator end() { 
          return iterator(end_node_);
        }

        const_iterator end() const {
          return const_iterator(end_node_);
        }

        template <typename Key>
          iterator find(const Key &key) {

            tree_node_ptr node = root_node_;

            while (node != NULL)
            {
              if (comp_(key, node->data.first))
                node = node->left;
              else if (comp_(node->data.first, key))
                node = node->right;
              else
                return iterator(node);
            }
            return end();
          }

        template <typename Key>
          const_iterator find(const Key &key) const {

            tree_node_ptr node = root_node_;

            while (node != NULL)
            {
              if (comp_(key, node->data.first))
                node = node->left;
              else if (comp_(node->data.first, key))
                node = node->right;
              else
                return const_iterator(node);
            }
            return end();
          }

        template <typename Key, typename T>
          T& operator[](const Key& key)
          {
            try {
              return at<Key, T>(key);
            }
            catch (std::out_of_range e) {
              return insert(ft::make_pair(key, T())).first->second;
            }
          }


        template <typename Key, typename Value>
          Value &at(const Key &key) {
            iterator it = find(key);

            if (it == end())
              throw std::out_of_range("Error: at: cannot find element");
            return it->second;
          }

        template <typename Key, typename Value>
          const Value &at(const Key &key) const {
            const_iterator it = find(key);

            if (it == end())
              throw std::out_of_range("Error: at: cannot find element");
            return it->second;
          }

        template <typename Key>
          pair<iterator, iterator> equal_range(const Key& key)
          {
            return pair<iterator, iterator>(lower_bound(key), upper_bound(key));
          }

        template <typename Key>
          pair<const_iterator, const_iterator> equal_range(const Key& key) const
          {
            return pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
          }

        // Returns the element that is equal or greater than key
        template <typename Key>
          iterator lower_bound(const Key& key)
          {
            tree_node_ptr curr_node = root_node_;
            tree_node_ptr lower_node = end_node_;

            while (curr_node != NULL && curr_node != end_node_)
            {
              if (curr_node->data.first == key)
                return iterator(curr_node);
              if (comp_(key, curr_node->data.first))
              {
                lower_node = curr_node;
                curr_node = curr_node->left;
              }
              else
                curr_node = curr_node->right;
            }
            return iterator(lower_node);
          }

        template <typename Key>
          const_iterator lower_bound(const Key& key) const
          {
            tree_node_ptr curr_node = root_node_;
            tree_node_ptr lower_node = end_node_;

            while (curr_node != NULL && curr_node != end_node_)
            {
              if (curr_node->data.first == key)
                return const_iterator(curr_node);
              if (comp_(key, curr_node->data.first))
              {
                lower_node = curr_node;
                curr_node = curr_node->left;
              }
              else
                curr_node = curr_node->right;
            }
            return const_iterator(lower_node);
          }

        template <typename Key>
          iterator upper_bound(const Key& key)
          {
            tree_node_ptr curr_node = root_node_;
            tree_node_ptr upper_node = end_node_;

            while (curr_node != NULL && curr_node != end_node_)
            {
              if (comp_(key, curr_node->data.first))
              {
                upper_node = curr_node;
                curr_node = curr_node->left;
              }
              else
                curr_node = curr_node->right;
            }
            return iterator(upper_node);
          }

        template <typename Key>
          const_iterator upper_bound(const Key& key) const
          {
            tree_node_ptr curr_node = root_node_;
            tree_node_ptr upper_node = end_node_;

            while (curr_node != NULL && curr_node != end_node_)
            {
              if (comp_(key, curr_node->data.first))
              {
                upper_node = curr_node;
                curr_node = curr_node->left;
              }
              else
                curr_node = curr_node->right;
            }
            return const_iterator(upper_node);
          }

        bool empty() const {
          if (end_node_->left == NULL && end_node_->right == NULL)
            return true;
          return false;
        }

        size_type size() const {
          return size_;
        }

        size_type max_size() const {
          return std::min(node_alloc_.max_size()
              , static_cast<size_type>(std::numeric_limits<node_difference_type>::max()));
        }

        void clear()
        {
          destroy_tree(end_node_);
        }

      private:
        void destroy_tree(tree_node_ptr node)
        {
          if (node != NULL)
          {
            destroy_tree(node->left);
            destroy_tree(node->right);
            if (node != end_node_)
            {
              pair_alloc_.destroy(&node->data);
              node_alloc_.deallocate(node, 1);
            }
            else if (node == end_node_)
              end_node_->left = NULL;
            if (node == root_node_)
              root_node_ = NULL;
          }
          size_ = 0;
        }

        void check_rb_insertion(tree_node_ptr node)
        {
          if (node == root_node_)
            node->is_black = true;

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
                check_rb_insertion(node->parent->parent);
                return;
              }
              // If color of uncle is black
              else
              {
                // CASE #2
                // If subtree form a triangle
                if (node == node->parent->right)
                {
                  node = node->parent;
                  rotate_left(node);
                }
                // CASE #3
                // If subtree form a line
                node->parent->is_black = true;
                node->parent->parent->is_black = false;
                rotate_right(node->parent->parent);
                root_node_->is_black = true;
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
                check_rb_insertion(node->parent->parent);
                return;
              }
              // If color of uncle is black
              else
              {
                // CASE #2
                // If subtree form a triangle
                if (node == node->parent->left)
                {
                  node = node->parent;
                  rotate_right(node);
                }
                // CASE #3
                // If subtree form a line
                node->parent->is_black = true;
                // TODO: We might need to call recolorization here with parent->parent
                node->parent->parent->is_black = false;
                rotate_left(node->parent->parent);
                root_node_->is_black = true;
              }
            }
          }
        }

        int rotate_left(tree_node_ptr node_x)
        {
          if (node_x->right == NULL)
            return 0;
          tree_node_ptr node_y = node_x->right;
          // Move node_y to root of subtree
          if (node_x->parent->left == node_x)
            node_x->parent->left = node_y;
          else if (node_x->parent->right == node_x)
          {
            node_x->parent->right = node_y;
          }
          node_y->parent = node_x->parent;

          // Previous left child of node_y becomes right child of x
          node_x->right = node_y->left;
          if (node_x->right)
            node_x->right->parent = node_x;

          // node_x becomes left child of node_y
          node_y->left = node_x;
          node_x->parent = node_y;

          root_node_ = end_node_->left;
          return 1;
        }

        int rotate_right(tree_node_ptr node_x)
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
          if (node_x->left)
            node_x->left->parent = node_x;

          // node_x becomes left child of node_y
          node_y->right = node_x;
          node_x->parent = node_y;

          root_node_ = end_node_->left;
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

        tree_node_ptr get_sibbling(const tree_node_ptr node) const
        {
          if (node == end_node_ || node == root_node_)
            return NULL;
          else if (node == node->parent->left)
            return node->parent->right;
          else
            return node->parent->left;
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


        void destroy_node(tree_node_ptr node) {
          if (node == node->parent->left) {
            node->parent->left = NULL;
          } else {
            node->parent->right = NULL;
          }
          if (node == root_node_)
            root_node_ = NULL;

          pair_alloc_.destroy(&node->data);
          node_alloc_.deallocate(node, 1);
          size_--;
        }

        void check_double_black(tree_node_ptr node)
        {
          tree_node_ptr sibbling = get_sibbling(node);
          tree_node_ptr far_sib_child = NULL;
          tree_node_ptr near_sib_child = NULL;

          // Case #1: If node is red, delete
          if (node->is_black == false)
            return;

          // Case #2: If node is black and is root: delete
          if (node == root_node_)
            return;

          // Setting far and near sibbling children
          if (sibbling && node == node->parent->left)
          {
            far_sib_child = sibbling->right;
            near_sib_child = sibbling->left;
          }
          else if (sibbling && node == node->parent->right)
          {
            far_sib_child = sibbling->left;
            near_sib_child = sibbling->right;
          }
          // Case #3: If node is black and sibbling is black:
          if (sibbling && sibbling->is_black)
          {
            // Case #3.1: If sibbling (black) has black (or NULL) children
            if ((!sibbling->left || sibbling->left->is_black)
                && (!sibbling->right || sibbling->right->is_black))
            {
              sibbling->is_black = false;
              if (!node->parent->is_black)
              {
                node->parent->is_black = true;
              }
              else if (node->parent->is_black)
              {
                check_double_black(node->parent);
              }
            }
            // Case #5: If sibbling (black) has near child red, and far child black
            else if (near_sib_child 
                && !near_sib_child->is_black
                && (!far_sib_child || far_sib_child->is_black))
            {
              sibbling->is_black = false;
              near_sib_child->is_black = true;
              if (node == node->parent->left)
                rotate_right(sibbling);
              else if (node == node->parent->right)
                rotate_left(sibbling);
              check_double_black(node);
            }
            // Case #6: Sibbling is black, far child is red
            else if ((!near_sib_child || near_sib_child->is_black)
                && (far_sib_child && !far_sib_child->is_black))
            {
              bool tmp_color = node->parent->is_black;

              node->parent->is_black = sibbling->is_black;
              sibbling->is_black = tmp_color;
              far_sib_child->is_black = true;
              if (node == node->parent->left)
                rotate_left(node->parent);
              else if (node == node->parent->right)
                rotate_right(node->parent);
            }
          }

          // Case #4: If node is black and sibbling is red:
          else if (sibbling && !sibbling->is_black)
          {
            // Case #4.1: If sibbling (red) has black (or NULL) children
            if ((!sibbling->left || sibbling->left->is_black)
                && (!sibbling->right || sibbling->right->is_black))
            {
              node->parent->is_black = false;
              sibbling->is_black = true;
              if (node == node->parent->left)
                rotate_left(node->parent);
              else if (node == node->parent->right)
                rotate_right(node->parent);
              check_double_black(node);
            }
          }
        }

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
            if (node == end_node_)
              return end_node_;
            return node;
          }
        }

        tree_node_ptr get_prev_node(tree_node_ptr node) {
          if (node->left != NULL) {
            node = node->left;
            while (node->right != NULL) {
              node = node->right;
            }
            return node;
          } else {
            while (node->parent != NULL && node->parent->left == node) {
              node = node->parent;
            }
            node = node->parent;
            return node;
          }
        }

        tree_node_ptr get_first_node(tree_node_ptr node) const {
          if (!node)
            return end_node_;
          if (node->left == NULL)
            return node;
          return get_first_node(node->left);
        }

        tree_node_ptr get_last_node(tree_node_ptr node) const {
          if (!node)
            return end_node_;
          if (node->right == NULL)
            return node;
          return get_last_node(node->right);
        }

        tree_node_ptr construct_node() {
          tree_node_ptr new_node = node_alloc_.allocate(1);
          new_node->parent = NULL;
          new_node->left = NULL;
          new_node->right = NULL;
          new_node->is_black = true;
          size_++;
          return new_node;
        }

        tree_node_ptr construct_node(const value_type &new_value) {
          tree_node_ptr new_node = node_alloc_.allocate(1);
          new_node->parent = NULL;
          new_node->left = NULL;
          new_node->right = NULL;
          new_node->is_black = false;
          pair_alloc_.construct(&new_node->data, new_value);
          size_++;
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
          size_++;
          return new_node;
        }

        // Returns the parent node of the new (non-existant) node with value
        // bool is true when we can add node; bool is false when value.first already
        // exists.
        // If node already exists, returns the existing node
        pair<tree_node_ptr, bool> find_parent_pos(const value_type &value,
            tree_node_ptr node) {
          if (value.first == node->data.first)
            return pair<tree_node_ptr, bool>(node, false);
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

        // FUNCTIONS FOR PRINTING AND DEBUGGING PURPOSES
        void print_tree() const { 
          std::cout << "===== PRINTING TREE =====" << std::endl;
          print_tree(root_node_);
          std::cout << "===== END OF PRINTING TREE =====" << std::endl;
        }

        void print_tree(const tree_node_ptr node) const
        {
          if (node == NULL)
            return;
          print_tree(node->left);
          print_node(node);
          print_tree(node->right);
        }

        void print_node(const tree_node_ptr node) const {
          std::cout << "Key: " << node->data.first
            << " | Value: " << node->data.second
            << " | Parent: " << ((node == root_node_) ? 9999999 : node->parent->data.first)
            << std::endl;
        }

        /* USES C++11

           void print_levels()
           {
           std::cout << "=====PRINTING LEVELS=====" << std::endl;
           print_levels(root_node_);
           std::cout << "=====END OF PRINTING LEVELS=====" << std::endl;
           std::cout << std::endl;
           }

           void print_levels(tree_node_ptr node)
           {
           std::stringstream node_value_ss;
           std::stringstream node_parent_ss;

           if (node == NULL) {
           std::cout << "print_levels: tree is empty" << std::endl;
           return;
           }

           std::queue<tree_node_ptr> qu;
           qu.push(node);
           qu.push(NULL);
           int level = 1;
           std::cout << std::setw(2) << level << " - ";
           while (true)
           {
           tree_node_ptr curr = qu.front();
           qu.pop();
           if (curr != NULL) {
           std::cout << "("
           << "\33[32m";
           node_value_ss << (curr->left ? std::to_string(curr->left->data.first) + "<=" : "")
           << "\33[36m" << std::to_string(curr->data.first) << "\33[32m"
           << (curr->right ? "=>" + std::to_string(curr->right->data.first) : "");
           std::cout << std::setw(23) << node_value_ss.str()
           << "\33[0m|"
           << "Par: \33[34m";
           node_parent_ss << ((curr == curr->parent->left) ? std::to_string(curr->data.first) + "<=" : "")
           << ((curr != root_node_) ? std::to_string(curr->parent->data.first) : "endn")
           << ((curr == curr->parent->right) ? "=>" + std::to_string(curr->data.first) : "");
           std::cout << std::setw(9) << node_parent_ss.str()
           << "\33[0m|\33[35m"
           << (curr->is_black ? "BLA" : "RED")
           << "\33[0m"
           << ")"
           << " ";
           node_value_ss.str(std::string());
           node_parent_ss.str(std::string());
           if (curr->left != NULL) {
           qu.push(curr->left);
           }
           if (curr->right != NULL) {
           qu.push(curr->right);
           }
           }
           else
           {
           std::cout << std::endl;
           if (qu.empty())
           break;
           ++level;
           std::cout << std::setw(2) << level << " - ";
           qu.push(NULL);
           }
           }
           }
           */
    };
} // namespace ft
