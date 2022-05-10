#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft {
  template <typename T, typename Container = ft::vector<T> >
    class stack
    {
      public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type   size_type;
        typedef typename Container::reference   reference;
        typedef typename Container::const_reference const_reference;

      protected:
        container_type c;

      public:

        /*
         * Stack constructors:
         * Constructs the stack.
         */
        explicit stack(const Container& cont = Container()) : c(cont) {}

        stack(const stack& other) {
          c(other);
        }

        /*
         * Stack destructor:
         * Destructs the stack.
         */
        ~stack()
        {
        }

        /*
         * Assignment operator overload:
         * Assigns values to the container adaptor.
         */
        stack& operator=(const stack& other)
        {
          c = other.c;
          return *this;
        }

        /*
         * Accesses the top element.
         */
        reference top()
        {
          return c.back();
        }

        const_reference top() const
        {
          return c.back();
        }

        /*
         * Checks whether the underlying container is empty
         */
        bool empty() const
        {
          return c.empty();
        }

        /*
         * Returns the number of elements
         */
        size_type size() const
        {
          return c.size();
        }

        /*
         * Inserts element at the top
         */
        void push(const value_type& value)
        {
          c.push_back(value);
        }

        /*
         * Removes the top element
         */
        void pop()
        {
          c.pop_back();
        }

        template <typename T1, typename C1>
          friend bool operator==(const stack<T1, C1>& x, const stack<T1, C1>& y);

        template <typename T1, typename C1>
          friend bool operator<(const stack<T1, C1>& x, const stack<T1, C1>& y);
    };

  /*
   * Stack non-member functions and overloads
   */

  template< class T, class Container >
    bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
      return lhs.c == rhs.c;
    }

  template< class T, class Container >
    bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
      return !(lhs == rhs);
    }

  template< class T, class Container >
    bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
      return lhs.c < rhs.c;
    }

  template< class T, class Container >
    bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
      return (lhs < rhs || lhs == rhs);
    }

  template< class T, class Container >
    bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
      return !(lhs <= rhs);
    }

  template< class T, class Container >
    bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
    {
      return (lhs > rhs || lhs == rhs);
    }
}

