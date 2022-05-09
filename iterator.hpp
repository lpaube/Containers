#pragma once

#include <iterator>
#include "utils.hpp"

namespace ft {
  /*
   * normal_iterator passes a pointer to type T (type T is passed by vector).
   * reverse_iterator passes normal_iterator<pointer> (as passed by vector).
   */
  template <typename Iterator>
    struct iterator_traits {
      typedef typename Iterator::iterator_category iterator_category;
      typedef typename Iterator::value_type value_type;
      typedef typename Iterator::difference_type difference_type;
      typedef typename Iterator::pointer pointer;
      typedef typename Iterator::reference reference;
    };

  /*
   * normal_iterator passes a pointer to type T (type T is passed by vector).
   */
  template <typename Tp>
    struct iterator_traits<Tp*> {
      typedef std::random_access_iterator_tag iterator_category;
      typedef Tp value_type;
      typedef std::ptrdiff_t difference_type;
      typedef Tp* pointer;
      typedef Tp& reference;
    };

  /*
   * Gets used when a normal_iterator is created with a const_pointer (i.e. cbegin() and cend())
   * const Tp* is a pointer to a const T passed from vector.
   */
  template <typename Tp>
    struct iterator_traits<const Tp*> {
      typedef std::random_access_iterator_tag iterator_category;
      typedef Tp value_type;
      typedef std::ptrdiff_t difference_type;
      typedef const Tp* pointer;
      typedef const Tp& reference;
    };

  /*
   * Iterator_type is a pointer to the type T passed to vector.
   */
  template <typename Iterator_type, typename Container>
    class normal_iterator {
      protected:
        Iterator_type m_current;

        typedef iterator_traits<Iterator_type> traits_type;

      public:
        typedef typename traits_type::iterator_category iterator_category;
        typedef typename traits_type::value_type value_type;
        typedef typename traits_type::difference_type difference_type;
        typedef typename traits_type::reference reference;
        typedef typename traits_type::pointer pointer;

        normal_iterator() : m_current(Iterator_type()) {}

        normal_iterator(const Iterator_type& i) : m_current(i) {}

        template <typename Iter>
          normal_iterator(const normal_iterator<Iter, typename enable_if<(is_same<Iter, typename Container::pointer>::value),
              Container>::type>& i)
          : m_current(i.base()) {}

        // Forward iterator overloads
        reference operator*() const {
          return *m_current;
        }

        pointer operator->() const { return m_current; }

        normal_iterator& operator++() {
          ++m_current;
          return *this;
        }

        normal_iterator& operator=(const normal_iterator& other)
        {
          m_current = other.m_current;
          return *this;
        }

        normal_iterator operator++(int) { return normal_iterator(m_current++); }

        // Bidirectional iterator overloads
        normal_iterator& operator--() {
          --m_current;
          return *this;
        }

        normal_iterator operator--(int) {
          return normal_iterator(m_current--);
        }

        // Random access iterator overloads
        reference operator[](difference_type n) const { return m_current[n]; }

        normal_iterator& operator+=(difference_type n) {
          m_current += n;
          return *this;
        }

        normal_iterator operator+(difference_type elem) const {
          return normal_iterator(m_current + elem);
        }

        normal_iterator& operator-=(difference_type n) {
          m_current -= n;
          return *this;
        }

        normal_iterator operator-(difference_type elem) const {
          return normal_iterator(m_current - elem);
        }

        const Iterator_type& base() const { return m_current; }
    };

  // Non-member overloads
  // Forward iterator non-member overloads
  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator==(const normal_iterator<IteratorL, Container>& lhs,
        const normal_iterator<IteratorR, Container>& rhs) {
      return lhs.base() == rhs.base();
    }

  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator!=(const normal_iterator<IteratorL, Container>& lhs,
        const normal_iterator<IteratorR, Container>& rhs) {
      return lhs.base() != rhs.base();
    }

  // Random access iterator non-member overloads
  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator>(const normal_iterator<IteratorL, Container>& lhs,
        const normal_iterator<IteratorR, Container>& rhs) {
      return lhs.base() > rhs.base();
    }

  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator<(const normal_iterator<IteratorL, Container>& lhs,
        const normal_iterator<IteratorR, Container>& rhs) {
      return lhs.base() < rhs.base();
    }

  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator>=(const normal_iterator<IteratorL, Container>& lhs,
        const normal_iterator<IteratorR, Container>& rhs) {
      return lhs.base() <= rhs.base();
    }

  template <typename IteratorL, typename IteratorR, typename Container>
    bool operator<=(const normal_iterator<IteratorL, Container>& lhs,
        const normal_iterator<IteratorR, Container>& rhs) {
      return lhs.base() <= rhs.base();
    }

  template <typename Iter1, typename Iter2, typename Container>
    typename normal_iterator<Iter1, Container>::difference_type operator-(
        const normal_iterator<Iter1, Container>& lhs,
        const normal_iterator<Iter2, Container>& rhs) {
      return lhs.base() - rhs.base();
    }

  template <typename Iterator, typename Container>
    normal_iterator<Iterator, Container> operator+(
        typename normal_iterator<Iterator, Container>::difference_type lhs,
        const normal_iterator<Iterator, Container>& rhs) {
      return normal_iterator<Iterator, Container>(rhs.base() + lhs);
    }

  /*
   * Iterator_type is normal_iterator<pointer> passed by vector
   */
  template<typename Iterator_type>
    class reverse_iterator : std::iterator<
                             typename iterator_traits<Iterator_type>::iterator_category,
                             typename iterator_traits<Iterator_type>::value_type,
                             typename iterator_traits<Iterator_type>::difference_type,
                             typename iterator_traits<Iterator_type>::pointer,
                             typename iterator_traits<Iterator_type>::reference
                             >
  {
    public:
      Iterator_type m_current;

      typedef iterator_traits<Iterator_type> traits_type;

    public:
      typedef Iterator_type                           Iter;
      typedef typename traits_type::iterator_category iterator_category;
      typedef typename traits_type::value_type        value_type;
      typedef typename traits_type::difference_type   difference_type;
      typedef typename traits_type::pointer           pointer;
      typedef typename traits_type::reference         reference;

      // MEMBER FUNCTIONS
      reverse_iterator() : m_current() {}

      explicit reverse_iterator(Iterator_type x) : m_current(x) {}

      template<typename U>
        reverse_iterator(const reverse_iterator<U>& other) : m_current(other.m_current) {}

      template<typename U>
        reverse_iterator& operator=(const reverse_iterator<U>& other) {
          m_current = other.m_current;
          return *this;
        }

      Iterator_type base() const {
        return m_current;
      }

      reference operator*() const {
        return *(m_current - 1);
      }

      pointer operator->() const {
        return m_current.base() - 1;
      }

      reference operator[](difference_type n) const {
        return *(m_current - n - 1);
      }

      reverse_iterator& operator++() {
        --m_current;
        return *this;
      }

      reverse_iterator& operator--() {
        ++m_current;
        return *this;
      }

      reverse_iterator operator++(int) {
        return reverse_iterator(m_current--);
      }

      reverse_iterator operator--(int) {
        return reverse_iterator(m_current++);
      }

      reverse_iterator operator+(difference_type n) const {
        return reverse_iterator(m_current - n);
      }

      difference_type operator+(reverse_iterator n) const {
        return m_current - n;
      }

      reverse_iterator operator-(difference_type n) const {
        return reverse_iterator(m_current + n);
      }

      reverse_iterator& operator+=(difference_type n) {
        m_current -= n;
        return *this;
      }

      reverse_iterator& operator-=(difference_type n) {
        m_current += n;
        return *this;
      }
  };

  // REVERSE ITERATOR NON-MEMBER FUNCTIONS
  template<typename Iterator1, typename Iterator2>
    bool operator==(const reverse_iterator<Iterator1>& lhs,
        const reverse_iterator<Iterator2>& rhs)
    {
      return lhs.base() == rhs.base();
    }

  template<typename Iterator1, typename Iterator2>
    bool operator!=(const reverse_iterator<Iterator1>& lhs,
        const reverse_iterator<Iterator2>& rhs)
    {
      return lhs.base() != rhs.base();
    }

  template<typename Iterator1, typename Iterator2>
    bool operator<(reverse_iterator<Iterator1>& lhs,
        reverse_iterator<Iterator2>& rhs)
    {
      return lhs.base() < rhs.base();
    }

  template<typename Iterator1, typename Iterator2>
    bool operator<=(reverse_iterator<Iterator1>& lhs,
        reverse_iterator<Iterator2>& rhs)
    {
      return lhs.base() <= rhs.base();
    }

  template<typename Iterator1, typename Iterator2>
    bool operator>(reverse_iterator<Iterator1>& lhs,
        reverse_iterator<Iterator2>& rhs)
    {
      return lhs.base() > rhs.base();
    }

  template<typename Iterator1, typename Iterator2>
    bool operator>=(reverse_iterator<Iterator1>& lhs,
        reverse_iterator<Iterator2>& rhs)
    {
      return lhs.base() >= rhs.base();
    }

  template<class Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
      return reverse_iterator<Iter>(it.base() - n);
    }

  template<class Iter>
    reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
      return it.base() + n;
    }

  template <typename Iterator>
    typename reverse_iterator<Iterator>::difference_type
      operator-(const reverse_iterator<Iterator>& lhs,
                const reverse_iterator<Iterator>& rhs)
      {
        return (rhs.base() - lhs.base());
      }

  template <typename Iter1, typename Iter2>
    typename reverse_iterator<Iter1>::difference_type
      operator-(const reverse_iterator<Iter1>& lhs,
                const reverse_iterator<Iter2>& rhs)
      {
        return (rhs.base() - lhs.base());
      }
}
