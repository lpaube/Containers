#include <iterator>

namespace ft {
  template <typename Iterator>
    struct iterator_traits {
      typedef typename Iterator::iterator_category iterator_category;
      typedef typename Iterator::value_type value_type;
      typedef typename Iterator::difference_type difference_type;
      typedef typename Iterator::pointer pointer;
      typedef typename Iterator::reference reference;
    };

  template <typename Tp>
    struct iterator_traits<Tp*> {
      typedef std::random_access_iterator_tag iterator_category;
      typedef Tp value_type;
      typedef std::ptrdiff_t difference_type;
      typedef Tp* pointer;
      typedef Tp& reference;

    };

  template <typename Tp>
    struct iterator_traits<const Tp*> {
      typedef std::random_access_iterator_tag iterator_category;
      typedef Tp value_type;
      typedef std::ptrdiff_t difference_type;
      typedef const Tp* pointer;
      typedef const Tp& reference;
    };


  template<typename Iterator_type>
    class reverse_iterator : std::iterator<
                             typename iterator_traits<Iterator_type>::iterator_category,
                             typename iterator_traits<Iterator_type>::value_type,
                             typename iterator_traits<Iterator_type>::difference_type,
                             typename iterator_traits<Iterator_type>::pointer,
                             typename iterator_traits<Iterator_type>::reference
                             >
  {
    protected:
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
        }

      Iterator_type base() const {
        return m_current;
      }

      reference operator*() const {
        return *m_current;
      }

      pointer operator->() const {
        return m_current;
      }

      Iterator_type operator[](difference_type n) const {
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

      reverse_iterator& operator++(int) {
        return reverse_iterator(m_current--);
      }

      reverse_iterator& operator--(int) {
        return reverse_iterator(m_current++);
      }

      reverse_iterator operator+(difference_type n) const {
        return reverse_iterator(m_current - n);
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
      return it.base() - n;
    }

  template<class Iter>
    reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
    {
      return it.base() + n;
    }

  template <typename Iterator_type>
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

        // Forward iterator overloads
        reference operator*() const {
          return *m_current;
        }

        pointer operator->() const { return m_current; }

        normal_iterator& operator++() {
          ++m_current;
          return *this;
        }

        normal_iterator operator++(int) { return normal_iterator(m_current++); }

        // Bidirectional iterator overloads
        normal_iterator operator--() {
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

        normal_iterator operator+(difference_type elem) {
          return normal_iterator(m_current + elem);
        }

        normal_iterator& operator-=(difference_type n) {
          m_current -= n;
          return *this;
        }

        normal_iterator operator-(difference_type elem) {
          return normal_iterator(m_current - elem);
        }

        // This base function is a getter since m_current is protected
        const Iterator_type& base() const { return m_current; }
    };

  // Non-member overloads
  // Forward iterator non-member overloads
  template <typename IteratorL, typename IteratorR>
    bool operator==(const normal_iterator<IteratorL>& lhs,
        const normal_iterator<IteratorR>& rhs) {
      return lhs.base() == rhs.base();
    }

  template <typename IteratorL, typename IteratorR>
    bool operator!=(const normal_iterator<IteratorL>& lhs,
        const normal_iterator<IteratorR>& rhs) {
      return lhs.base() != rhs.base();
    }

  // Random access iterator non-member overloads
  template <typename IteratorL, typename IteratorR>
    bool operator>(const normal_iterator<IteratorL>& lhs,
        const normal_iterator<IteratorR>& rhs) {
      return lhs.base() > rhs.base();
    }

  template <typename IteratorL, typename IteratorR>
    bool operator<(const normal_iterator<IteratorL>& lhs,
        const normal_iterator<IteratorR>& rhs) {
      return lhs.base() < rhs.base();
    }

  template <typename IteratorL, typename IteratorR>
    bool operator>=(const normal_iterator<IteratorL>& lhs,
        const normal_iterator<IteratorR>& rhs) {
      return lhs.base() <= rhs.base();
    }

  template <typename IteratorL, typename IteratorR>
    bool operator<=(const normal_iterator<IteratorL>& lhs,
        const normal_iterator<IteratorR>& rhs) {
      return lhs.base() <= rhs.base();
    }

  template <typename Iterator>
    typename normal_iterator<Iterator>::difference_type operator-(
        const normal_iterator<Iterator>& lhs,
        const normal_iterator<Iterator>& rhs) {
      return lhs.base() - rhs.base();
    }

  template <typename Iterator>
    typename normal_iterator<Iterator>::difference_type operator+(
        typename normal_iterator<Iterator>::difference_type lhs,
        const normal_iterator<Iterator>& rhs) {
      return normal_iterator<Iterator>(rhs.base() + lhs);
    }
}
