#include <iostream>


namespace ft {
  /*
   * This is the implementation of a red-black tree.
   * The template paramenter Tp is a pair<key, value>.
   */
  template <typename Tp>
    class rb_tree
    {
      public:
        typedef Tp value_type;
        //typedef rb_tree_iterator<value_type> iterator;

        struct tree_node 
        {
          tree_node* parent;
          tree_node* left;
          tree_node* right;
          Tp value;
          bool  is_black;
        };

      private:
        tree_node*  root_node;

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

          new_node = std::allocator<tree_node>::allocate(1);
          new_node->value = pair;
          new_node->parent = nullptr;
          new_node->left = nullptr;
          new_node->right = nullptr;

          // Will need to change this to a real red/black checker!
          new_node->is_black = 1;
          return new_node;
        }

        tree_node* insert(value_type pair)
        {
          tree_node* tmp = root_node;

          while (tmp != nullptr)
          {
            if (pair.first < tmp->value.first)
            {
              if (tmp->left == nullptr)
                return tmp->left = create_node(pair);
              tmp = tmp->left;
            }
            else if (pair.first > tmp->value.first)
            {
              if (tmp->right == nullptr)
                return tmp->right = create_node(pair);
              tmp = tmp->right;
            }
          }
          return tmp = create_node(pair);
        }

        void print_tree(tree_node* node, int& x)
        {
          if (node == nullptr)
            return ;
          x++;
          print_tree(node->left);
          print_tree(node->right);
          std::cout << "Level: " << x << " | "
                    << "Key: " << (node->value).first << std::endl;
        }

        void print_tree()
        {
          int x = 0;

          print_tree(root_node, x);
        }

    };
}
