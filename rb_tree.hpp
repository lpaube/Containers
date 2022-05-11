namespace ft {
  template <typename Tp>
  class rb_tree
  {
    public:
      typedef Tp value_type;
      //typedef rb_tree_iterator<value_type> iterator;

    struct tree_node 
    {
      bool  is_black;
      tree_node* parent;
      tree_node* left;
      tree_node* right;
      Tp value;
    };

    private:
      tree_node*  begin_node;
  };
}
