namespace ft {
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
        tree_node*  node_begin;

      public:

        rb_tree() : node_begin()
      {

      }

        tree_node* root()
        {
          return this->node_begin;
        }

        tree_node* root() const
        {
          return this->node_begin;
        }

        tree_node* leftmost()
        {
          tree_node* tmp = node_begin;

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
          tree_node* tmp = node_begin;

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

        tree_node create_node(value_type pair)
        {
          tree_node new_node;

          new_node.value = pair;
          new_node.parent = nullptr;
          new_node.left = nullptr;
          new_node.right = nullptr;

          // Will need to change this to a real red/black checker!
          new_node.is_black = 1;
          return new_node;
        }

        void insert(value_type pair)
        {
          tree_node tmp = node_begin;
          tree_node new_node;

          if (node_begin == nullptr)
            node_begin = create_node(pair);

          else
          {
            while (tmp != nullptr)
            if (tmp && pair.first < tmp.first)
            {
              if (tmp->left == nullptr)
              {
                new_node = create_node(pair);
                
              }
              tmp = tmp->left;
            }
            else if (tmp && pair.first > tmp.first)
            {
              tmp = tmp->right;
            }
          }
        }
    };
}
