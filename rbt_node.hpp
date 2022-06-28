#pragma once

namespace ft {
  template <typename value_type>
    class rbt_node
    {
      public:
        rbt_node* parent;
        rbt_node* left;
        rbt_node* right;
        value_type data;
        bool  is_black;
    };
}
