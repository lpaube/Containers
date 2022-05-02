#pragma once

#include <functional>
#include <iostream>
#include <iterator>

//#include "bst_iterator.hpp"
#include "iterator.hpp"

namespace ft {

template <typename Key, typename T,
          typename Alloc = std::allocator<std::pair<const Key, T>>>
class bst {
 public:
  /* BST Node:
   * Used to store the pairs stored in the class map.
   * Each node contains a pair, and pointers to its sibblings.
   * To traverse a bst, the nodes must be traversed
   */

  struct bst_node {
    typedef typename std::pair<Key, T> data_type;

    data_type data;
    bst_node* parent;
    bst_node* left;
    bst_node* right;
  };

  /*
   * BST Iterator:
   * It is the iterator returned to map.begin().
   * It contains a node of the bst, and uses that node
   * to return the pair stored in its variable "data".
   * It also contains the bst of which the node is a part of.
   */

  class bst_iterator {
   public:
    typedef std::pair<Key, T> data_type;
    typedef std::pair<Key, T>& reference;
    typedef std::pair<Key, T>* pointer;

    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;

   private:
    bst_node* node;
    bst bst_map;

   public:
    bst_iterator() { node = new bst_node; }

    explicit bst_iterator(bst_node* x, bst& bst_map)
        : node(x), bst_map(bst_map) {}

    data_type operator*() const { return node->data; }

    pointer operator->() const { return &(node->data); }

    bst_iterator operator++() {
      return bst_iterator(bst_map.next_inorder(node));
    }

    bst_iterator operator++(int) {
      bst_iterator tmp = *this;
      node = bst_iterator(bst_map.next_inorder(node));
      return bst_iterator(this->node);
    }

    bst_iterator& operator--() {

    }
  };

  /*
   * Binary Search Tree:
   * Used as the underlying algorithm to read/write elements
   * from the map class. This class along with its nested classes
   * are the hidden implementation of the map class
   */

 public:
  bst_node* root;

  bst() : root() {
    std::cout << "Regular Constructor of bst" << std::endl;
    std::cout << std::endl;
  }
  bst(typename bst_node::data_type data) {
    std::cout << "Data Constructor of bst" << std::endl;
    std::cout << std::endl;
    root = nullptr;
    root = insert(data, root);
  }

  void insert(typename bst_node::data_type x) { insert(x, root); }

  template <typename InputIt>
  void insert(InputIt first, InputIt last) {}

  void insert(typename bst_node::data_type x, bst_node*& node) {
    if (node == nullptr) {
      node = new bst_node;
      node->data = x;
      node->left = nullptr;
      node->right = nullptr;
    } else if (x.first <= node->data.first) {
      insert(x, node->left);
    } else if (x.first > node->data.first) {
      insert(x, node->right);
    }
  }

  int remove_leaf(Key key_name, bst_node* node) {
    if (node->left && key_name == node->left->data.first) {
      if (node->left->left == nullptr && node->left->right == nullptr) {
        delete node->left;
        node->left = nullptr;
        return 1;
      }
    } else if (node->right && key_name == node->right->data.first) {
      if (node->right->left == nullptr && node->right->right == nullptr) {
        delete node->right;
        node->right = nullptr;
        return 1;
      }
    }
    return 0;
  }

  int rm_one_child(Key key_name, bst_node* node) {
    if (node->left && key_name == node->left->data.first) {
      if (node->left->left == nullptr && node->left->right != nullptr) {
        delete node->left;
        node->left = node->left->right;
        return 1;
      } else if (node->left->left != nullptr && node->left->right == nullptr) {
        delete node->left;
        node->left = node->left->left;
        return 1;
      }
    } else if (node->right && key_name == node->right->data.first) {
      if (node->right->left == nullptr && node->right->right != nullptr) {
        delete node->right;
        node->right = node->right->right;
        return 1;
      } else if (node->right->left != nullptr &&
                 node->right->right == nullptr) {
        delete node->right;
        node->right = node->right->left;
        return 1;
      }
    }
    return 0;
  }

  int rm_two_child(Key key_name, bst_node* node) {
    typename bst_node::data_type tmp_pair;

    if (node && key_name == node->data.first) {
      if (node->left != nullptr && node->right != nullptr) {
        tmp_pair = next_inorder(node)->data;
        remove(next_inorder(node)->data.first);
        node->data = tmp_pair;
        return 1;
      }
    }
    if (node->left && key_name == node->left->data.first) {
      if (node->left->left != nullptr && node->left->right != nullptr) {
        tmp_pair = next_inorder(node->left)->data;
        remove(next_inorder(node->left)->data.first);
        node->left->data = tmp_pair;
        return 1;
      }
    } else if (node->right && key_name == node->right->data.first) {
      if (node->right->left != nullptr && node->right->right != nullptr) {
        tmp_pair = next_inorder(node->right)->data;
        remove(next_inorder(node->right)->data.first);
        node->right->data = tmp_pair;
        return 1;
      }
    }
    return 0;
  }

  void remove(Key key_name) { remove(key_name, root); }

  void remove(Key key_name, bst_node* node) {
    if (!node) return;
    if (key_name <= node->data.first) {
      if (!remove_leaf(key_name, node) && !rm_one_child(key_name, node) &&
          !rm_two_child(key_name, node))
        remove(key_name, node->left);
    } else if (key_name > node->data.first) {
      if (!remove_leaf(key_name, node) && !rm_one_child(key_name, node) &&
          !rm_two_child(key_name, node))
        remove(key_name, node->right);
    }
  }

  bst_node* get_min() {
    bst_node* tmp_node = root;

    while (tmp_node->left != nullptr) tmp_node = tmp_node->left;
    return tmp_node;
  }

  bst_node* get_max() {
    bst_node* tmp_node = root;

    while (tmp_node->right != nullptr) tmp_node = tmp_node->right;
    return tmp_node;
  }

  bst_node* get_node(Key key_name) { return get_node(key_name, root); }

  bst_node* get_node(Key key_name, bst_node* t) {
    if (!t || t->data.first == key_name)
      return t;
    else if (key_name < t->data.first)
      return get_node(key_name, t->left);
    else if (key_name > t->data.first)
      return get_node(key_name, t->right);
    return t;
  }

  bst_node* next_inorder(bst_node* src) {
    bst_node* dst = nullptr;
    next_inorder(src->data.first, root, dst);
    return dst;
  }

  void next_inorder(Key key_name, bst_node* t, bst_node*& dst) {
    if (!t) return;
    next_inorder(key_name, t->left, dst);
    if (t->data.first > key_name && !dst) dst = t;
    next_inorder(key_name, t->right, dst);
  }

  void inorder() {
    int depth = 0;

    std::cout << "-----INORDER TRAVERSAL-----" << std::endl;
    inorder(root, depth);
    std::cout << std::endl;
  }

  void inorder(bst_node* t, int depth) {
    if (t == nullptr) return;
    inorder(t->left, depth + 1);
    std::cout << "depth: " << depth << " | key: " << t->data.first
              << " | value: " << t->data.second << std::endl;
    inorder(t->right, depth + 1);
  }
};
}  // namespace ft
