#pragma once

namespace ft {
  // Implementation of enable-if
  template <bool, typename T = void>
    struct enable_if
    {};

  template <typename T>
    struct enable_if<true, T> {
      typedef T type;
    };

  // Implementation of type_traits
  struct true_type {};
  struct false_type {};

  // Implementation for is_same
  template <typename, typename>
    struct is_same
    {
      typedef bool value_type;
      typedef false_type type;

      static const bool value = false;
      operator bool() {
        return value;
      }
    };

  template <typename T>
    struct is_same<T, T>
    {
      typedef bool value_type;
      typedef false_type type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  // Implementation of is_integral
  template <typename T>
    struct is_integral
    {
      typedef false_type type;
      typedef bool value_type;

      static const bool value = false;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<bool>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<char>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<char16_t>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<char32_t>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<wchar_t>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<short>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<int>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<long>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  template <>
    struct is_integral<long long>
    {
      typedef true_type type;
      typedef bool value_type;

      static const bool value = true;
      operator bool() {
        return value;
      }
    };

  /*
   * lexicographical_compare and equal
   */
  template <typename InputIterator1, typename InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
    {
      for (; first1 != last1 && first2 != last2; ++first1, ++first2)
      {
        if (*first1 < *first2)
          return 1;
        else if (*first1 > *first2)
          return 0;
      }
      if (first2 != last2)
        return 1;
      return 0;
    }

  template <typename InputIterator1, typename InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
  {
    for (; first1 != last1; ++first1, ++first2)
    {
      if (*first1 != *first2)
        return 0;
    }
    return 1;
  }
}
