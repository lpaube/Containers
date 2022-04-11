Using the GNU ISO C++ Library

On Iterators:


The vector class definition:

    template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
        class vector : protected _Vector_base<_Tp, _Alloc>
        {
          ...
          typedef _Vector_base<_Tp, _Alloc>                        _Base;
          ...
        public:
          ...
          typedef typename _Base::pointer                        pointer;
          typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;
          ...
        }

To understand the source of the Vector member type ``iterator``, we need to dig though the layers of its defining classes.


Top layer:

          typedef __gnu_cxx::__normal_iterator<pointer, vector> iterator;

  ``normal_iterator`` template arguments:



  **pointer**:  Comes from ``_Vector_base<_Tp, _Alloc>::pointer``

  ``_Vector_base`` template arguments:


      

The class __normal_iterator takes for template arguments an iterator (_Iterator), and a container (_Container):
  
    template<typename _Iterator, typename _Container>
        class __normal_iterator
        {
          typedef iterator_traits<_Iterator>                __traits_type;
        public:
          typedef _Iterator                                        iterator_type;
          typedef typename __traits_type::iterator_category iterator_category;
          typedef typename __traits_type::value_type          value_type;
          typedef typename __traits_type::difference_type         difference_type;
          typedef typename __traits_type::reference         reference;
          typedef typename __traits_type::pointer           pointer;
        }

Two points need to be addressed regarding the class __normal_iterator:
  1.  It uses the member types of the class ``iterator_traits`` to define the details of the iterator. However, these types are defined differently
      based on the type of ``_Iterator`` passed to its template parameter:

      Default iterator_traits definition:

        template<typename _Iterator>
          struct iterator_traits
          {
            typedef typename _Iterator::iterator_category iterator_category;
            typedef typename _Iterator::value_type        value_type;
            typedef typename _Iterator::difference_type   difference_type;
            typedef typename _Iterator::pointer           pointer;
            typedef typename _Iterator::reference         reference;
          };

      Partial specialization for pointer types:

        template<typename _Tp>
          struct iterator_traits<_Tp*>
          {
            typedef random_access_iterator_tag iterator_category;
            typedef _Tp                         value_type;
            typedef ptrdiff_t                   difference_type;
            typedef _Tp*                        pointer;
            typedef _Tp&                        reference;
          };

      Partial specialization for const pointer types:

        template<typename _Tp>
            struct iterator_traits<const _Tp*>
            {
              typedef random_access_iterator_tag iterator_category;
              typedef _Tp                         value_type;
              typedef ptrdiff_t                   difference_type;
              typedef const _Tp*                  pointer;
              typedef const _Tp&                  reference;
            };
    
  2.  The template parameter ``_Iterator``


The allocator is defined by the type of variable which we pass to its template parameter:

  template<typename _Tp, typename _Alloc = std::allocator<_Tp> >
      class vector : protected _Vector_base<_Tp, _Alloc>
      {
        ...
      }





Iterators originate from regular pointers defined by the allocator.
