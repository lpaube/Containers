/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:11:36 by laube             #+#    #+#             */
/*   Updated: 2022/02/13 22:26:04 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
class VectorIterator
{
	public:
		VectorIterator(): p(nullptr) {} // Default constructor
		VectorIterator(pointer p): p(p) {}
		VectorIterator(const VectorIterator& other): p(other.p) {} // Copy constructor
		virtual ~VectorIterator() {} // Destructor

		VectorIterator &operator=(const VectorIterator& other) {
			this->p = other.p;
			return (*this);
		}

		T&	operator*() {
			return (*this->p);
		}
		const T& operator*() const {
			return (*this->p);
		}
};

template<typename T>
class Vector
{
	private:
		T* m_container;
		unsigned long	m_capacity;
		unsigned long	m_size;

	public:
		Vector(): m_container(nullptr), m_capacity(0), m_size(0) {}
		Vector(unsigned long n, const T & val=T()): m_container(nullptr), m_capacity(0), m_size(0) {
			this->assign(n, val);
		}
		void assign(iterator first, iterator last) {
			size_t
		}
};
