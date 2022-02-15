/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:11:36 by laube             #+#    #+#             */
/*   Updated: 2022/02/15 17:20:22 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

template<class T, class Allocator = std::allocator<T>>


// https://en.cppreference.com/w/cpp/container/vector
/* LIST 
 *
 * MEMBER FUNCTIONS
 * 		CONSTRUCTORS
 * 			1.	vector();
 * 			2.	explicit vector( const Allocator& alloc );
 * 			3.	explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
 * 			5.	template< class InputIt >vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
 * 			6.	vector( const vector& other );
 *
 * 		DESTRUCTORS
 * 			1.	~vector();
 *
 * 		OTHER MEMBER FUNCTIONS
 * 			1.	vector& operator=( const vector& other );
 * 			1.	void assign( size_type count, const T& value );
 * 			2.	template< class InputIt >void assign( InputIt first, InputIt last );
 * 			1.	allocator_type get_allocator() const;
 *
 * 		ELEMENT ACCESS
 * 			1.	reference at( size_type pos );
 * 			2.	const_reference at( size_type pos ) const;
 * 			1.	reference front();
 * 			2.	const_reference front() const;
 * 			1.	reference back();
 * 			2.	const_reference back() const;
 * 			1.	T* data();
 * 			2.	const T* data() const;
 *
 * 		ITERATORS
 * 			1.	iterator begin();
 * 			2.	const_iterator begin() const;
 * 			1.	iterator end();
 * 			2.	const_iterator end() const;
 * 			1.	reverse_iterator rbegin();
 * 			2.	const_reverse_iterator rbegin() const;
 * 			1.	reverse_iterator rend();
 * 			2.	const_reverse_iterator rend() const;
