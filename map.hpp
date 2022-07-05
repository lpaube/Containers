
#pragma once

#include <iostream>
#include <map>
#include "iterator.hpp"
#include "rb_tree.hpp"
#include "rbt_iterator.hpp"
#include "utils.hpp"

namespace ft
{

  template <typename Key,
           typename T,
           typename Compare = std::less<Key>,
           typename Allocator = std::allocator<ft::pair<const Key, T> > >
             class map
             {    
                 // ======================= Member types =====================
               public:
                 typedef  Key                                                       key_type;                                                      
                 typedef  T                                                         mapped_type;                                                   
                 typedef  pair<const Key, T>                                        value_type;
                 typedef  std::size_t                                               size_type;                                                     
                 typedef  std::ptrdiff_t                                            difference_type;                                               
                 typedef  Compare                                                   key_compare;                                                   
                 typedef  Allocator                                                 allocator_type;                                                
                 typedef  value_type&                                               reference;                                                     
                 typedef  const value_type&                                         const_reference;         
                 typedef  typename Allocator::pointer                               pointer;                 
                 typedef  typename Allocator::const_pointer                         const_pointer;           
                 typedef  rbt_iterator<value_type, Compare>            iterator;
                 typedef  rbt_const_iterator<value_type, Compare>      const_iterator;
                 typedef  typename ft::reverse_iterator<iterator>                   reverse_iterator;        
                 typedef  typename ft::reverse_iterator<const_iterator>             const_reverse_iterator;  
                 typedef  rb_tree<value_type, Compare, Allocator>                   rb_tree;

               private:
                 rb_tree tree_;
                 allocator_type alloc_;
                 Compare comp_;

               public:
                 // ======================= Member classes =====================
                 class value_compare : std::binary_function<value_type, value_type, bool>
               {

                 friend class map;

                 public:
                 typedef bool        result_type;
                 typedef value_type  first_argument_type;
                 typedef value_type  second_argument_type;

                 protected:
                 Compare comp_;

                 value_compare(Compare c) : comp_(c)
                 {
                 }

                 public:
                 bool operator()(const value_type& lhs, const value_type& rhs) const
                 {
                   return comp_(lhs.first, rhs.first);
                 }
               };

                 // ======================= Member functions =====================

                 explicit map(const Compare& comp = Compare(),
                     const Allocator& alloc = Allocator())
                   : alloc_(alloc)
                     , comp_(comp)
               {
                 tree_ = rb_tree(comp, alloc);
               }

                 template<typename InputIt>
                   map(InputIt first, InputIt last,
                       const Compare& comp = Compare(),
                       const Allocator& alloc = Allocator())
                   : alloc_(alloc)
                     , comp_(comp)
               {
                 tree_ = rb_tree(first, last, comp, alloc);
               }

                 map(const map& other) : tree_(other.tree_)
                 {
                 }

                 // Map destructor
                 ~map()
                 {
                 }

                 // Map assignment operator overload
                 map& operator=(const map& other)
                 {
                   tree_ = other.tree_;
                   return *this;
                 }

                 // Map allocator getter
                 allocator_type get_allocator() const
                 {
                   return alloc_;
                 }

                 // Element access
                 T& at(const Key& key)
                 {
                   return tree_.at(key);
                 }

                 const T& at(const Key& key) const
                 {
                   return tree_.at(key);
                 }

                 T& operator[](const Key& key)
                 {
                   return tree_.template operator[]<T, Key>(key);
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

                 void swap(map& other)
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

                 /*
                  * Custom member functions (to remove when submitting)
                  */
                 void print_map()
                 {
                   tree_.print_tree();
                 }

                 /*
                 void print_levels()
                 {
                   tree_.print_levels();
                 }
                 */
             };

  // ======================= Non-member functions =====================
  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
      typename ft::map<Key, T, Compare, Alloc>::const_iterator lhs_it = lhs.begin();
      typename ft::map<Key, T, Compare, Alloc>::const_iterator rhs_it = rhs.begin();

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

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
      return !(lhs == rhs);
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
      return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
      return (lhs < rhs || lhs == rhs);
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
      return (!(lhs < rhs) && !(lhs == rhs));
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
      return (lhs > rhs || lhs == rhs);
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    void swap( ft::map<Key,T,Compare,Alloc>& lhs,
        ft::map<Key,T,Compare,Alloc>& rhs )
    {
      lhs.swap(rhs);
    }
}
