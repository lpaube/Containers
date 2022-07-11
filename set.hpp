#pragma once

#include "tree/rb_tree.hpp"
#include "iterator.hpp"

namespace ft {

  template <typename Key
    , typename Compare = std::less<Key>
    , typename Allocator = std::allocator<Key> >
    class set
    {
      public:
        typedef Key key_type;
        typedef Key value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef rbt_iterator<value_type, Compare> iterator;
        typedef rbt_const_iterator<value_type, Compare> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef rb_tree<value_type, Compare, Allocator> rb_tree;

      private:
        rb_tree tree_;
        allocator_type alloc_;
        Compare comp_;

      public:
        // Constructors
        set()
          : alloc_(Allocator())
            , comp_(Compare())
        {
          tree_ = rb_tree(comp_, alloc_);
        }

        explicit set(const Compare& comp, const Allocator& alloc = Allocator())
          : alloc_(alloc)
            , comp_(comp)
        {
          tree_ = rb_tree(comp, alloc);
        }

        template <typename InputIt>
          set(InputIt first
              , InputIt last
              , const Compare& comp = Compare()
              , const Allocator& alloc = Allocator())
          : alloc_(alloc)
            , comp_(comp)
      {
        tree_ = rb_tree(first, last, comp, alloc);
      }

        set(const set& other) : tree_(other.tree_)
      {
      }

        // Set destructor
        ~set()
        {
        }

        // Set assignment operator overload
        set& operator=(const set& other)
        {
          tree_ = other.tree_;
          return *this;
        }

        // Set allocator getter
        allocator_type get_allocator() const
        {
          return alloc_;
        }

        // Iterators
        iterator begin()
        {
          return tree_.begin();
        }

        const_iterator begin() const
        {
          return tree_.begin();
        }

        iterator end()
        {
          return tree_.end();
        }

        const_iterator end() const
        {
          return tree_.end();
        }

        reverse_iterator rbegin()
        {
          return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
          return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
          return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
          return const_reverse_iterator(begin());
        }

        // Capacity
        bool empty() const
        {
          return tree_.empty();
        }

        size_type size() const
        {
          return tree_.size();
        }

        size_type max_size() const
        {
          return tree_.max_size();
        }

        // Modifiers
        void clear()
        {
          tree_.clear();
        }

        pair<iterator, bool> insert(const value_type& value)
        {
          return tree_.insert(value);
        }

        iterator insert(iterator hint, const value_type& value)
        {
          return tree_.insert(hint, value);
        }

        template <typename InputIt>
          void insert(InputIt first, InputIt last)
          {
            tree_.insert(first, last);
          }

        void erase(iterator pos)
        {
          tree_.erase(pos);
        }

        void erase(iterator first, iterator last)
        {
          tree_.template erase<Key>(first, last);
        }

        size_type erase(const Key& key)
        {
          return tree_.erase(key);
        }

        void swap(set& other)
        {
          tree_.swap(other.tree_);
        }

        // Lookup
        size_type count(const Key& key) const
        {
          return tree_.count(key);
        }

        iterator find(const Key& key)
        {
          return tree_.find(key);
        }

        const_iterator find(const Key& key) const
        {
          return tree_.find(key);
        }

        pair<iterator, iterator> equal_range(const Key& key)
        {
          return tree_.equal_range(key);
        }

        pair<const_iterator, const_iterator> equal_range(const Key& key) const
        {
          return tree_.equal_range(key);
        }

        iterator lower_bound(const Key& key)
        {
          return tree_.lower_bound(key);
        }

        const_iterator lower_bound(const Key& key) const
        {
          return tree_.lower_bound(key);
        }

        iterator upper_bound(const Key& key)
        {
          return tree_.upper_bound(key);
        }

        const_iterator upper_bound(const Key& key) const
        {
          return tree_.upper_bound(key);
        }

        // Observers
        key_compare key_comp() const
        {
          return Compare();
        }

        value_compare value_comp() const
        {
          return value_compare(Compare());
        }
    };

  // ======================= Non-member functions =====================
  template<typename Key, typename Compare, typename Alloc>
    bool operator==(const ft::set<Key, Compare, Alloc>& lhs
        ,const ft::set<Key, Compare, Alloc>& rhs)
    {
      typename ft::set<Key, Compare, Alloc>::const_iterator lhs_it = lhs.begin();
      typename ft::set<Key, Compare, Alloc>::const_iterator rhs_it = rhs.begin();

      if (lhs.size() != rhs.size())
        return 0;
      while (lhs_it != lhs.end())
      {
        if (*lhs_it != *rhs_it)
          return 0;
        ++lhs_it;
        ++rhs_it;
      }
      return 1;
    }

  template<typename Key, typename Compare, typename Alloc>
    bool operator!=( const ft::set<Key, Compare, Alloc>& lhs,
        const ft::set<Key, Compare, Alloc>& rhs )
    {
      return !(lhs == rhs);
    }

  template<typename Key, typename Compare, typename Alloc>
    bool operator<( const ft::set<Key, Compare, Alloc>& lhs,
        const ft::set<Key, Compare, Alloc>& rhs )
    {
      return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

  template<typename Key, typename Compare, typename Alloc>
    bool operator<=( const ft::set<Key, Compare, Alloc>& lhs,
        const ft::set<Key, Compare, Alloc>& rhs )
    {
      return (lhs < rhs || lhs == rhs);
    }

  template<typename Key, typename Compare, typename Alloc>
    bool operator>( const ft::set<Key, Compare, Alloc>& lhs,
        const ft::set<Key, Compare, Alloc>& rhs )
    {
      return (!(lhs < rhs) && !(lhs == rhs));
    }

  template<typename Key, typename Compare, typename Alloc>
    bool operator>=( const ft::set<Key, Compare, Alloc>& lhs,
        const ft::set<Key, Compare, Alloc>& rhs )
    {
      return (lhs > rhs || lhs == rhs);
    }

  template<typename Key, typename Compare, typename Alloc>
    void swap( ft::set<Key, Compare, Alloc>& lhs,
        ft::set<Key, Compare, Alloc>& rhs )
    {
      lhs.swap(rhs);
    }
}
