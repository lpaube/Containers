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
                   return comp(lhs.first, rhs.first);
                 }
               };

                 // ======================= Member functions =====================

                 explicit map(const Compare& comp = Compare(),
                     const Allocator& alloc = Allocator())
                   : comp_(comp)
                     , alloc_(alloc)
               {
                 tree_ = rb_tree(comp, alloc);
               }

                 template<typename InputIt>
                   map(InputIt first, InputIt last,
                       const Compare& comp = Compare(),
                       const Allocator& alloc = Allocator())
                   : comp_(comp)
                     , alloc_(alloc)
               {
                 tree_ = rb_tree(first, last, comp, alloc);
               }

                 map(const map& other)
                 {
                 }

                 // Map destructor
                 ~map()
                 {
                 }

                 // Map assignment operator overload
                 map& operator=(const map& other)
                 {
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
                 }

                 T& operator[](const Key& key)
                 {
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
                 }

                 reverse_iterator rbegin()
                 {
                 }

                 const_reverse_iterator rbegin() const
                 {
                 }

                 reverse_iterator rend()
                 {
                 }

                 const_reverse_iterator rend() const
                 {
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
                   tree_.erase(first, last);
                 }

                 size_type erase(const Key& key)
                 {
                   tree_.erase(key);
                 }

                 void swap(map& other)
                 {

                 }

                 // Lookup
                 size_type count(const Key& key) const
                 {
                 }

                 iterator find(const Key& key)
                 {
                   return tree_.find(key);
                 }

                 const_iterator find(const Key& key) const
                 {
                 }

                 std::pair<iterator, iterator> equal_range(const Key& key)
                 {
                 }

                 std::pair<const_iterator, const_iterator> equal_range(const Key& key) const
                 {
                 }

                 iterator lower_bound(const Key& key)
                 {
                 }

                 const_iterator lower_bound(const Key& key) const
                 {
                 }

                 iterator upper_bound(const Key& key)
                 {
                 }

                 const_iterator upper_bound(const Key& key) const
                 {
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
             };

  // ======================= Non-member functions =====================
  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
        const ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }

  template<typename Key, typename T, typename Compare, typename Alloc>
    void swap( ft::map<Key,T,Compare,Alloc>& lhs,
        ft::map<Key,T,Compare,Alloc>& rhs )
    {
    }
}
