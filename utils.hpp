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

// Implementation for are_same
template <typename, typename>
struct are_same
{
  bool value = false;
  typedef false_type type;
};

template <typename T>
struct are_same<T, T>
{
  bool value = true;
  typedef true_type type;
};

// Implementation of is_integral
template <typename T>
struct is_integral
{
  typedef false_type type;
  typedef bool value_type;

  bool value = false;
  operator bool() {
    return value;
  }
};

template <>
struct is_integral<bool>
{
  typedef true_type type;
  typedef bool value_type;

  bool value = true;
  operator bool() {
    return value;
  }
};
