/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:19:05 by memartin          #+#    #+#             */
/*   Updated: 2021/02/16 11:18:13 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "VectorIterator.hpp"
# include <stdexcept>
# include <iostream>
# include <cstddef>
# include <string.h>

namespace ft {
	template <class T>
	class Vector {
		public:
			typedef T											value_type;
			typedef value_type									&reference;
			typedef const value_type							&const_reference;
			typedef value_type									*pointer;
			typedef const value_type							*const_pointer;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
			typedef VectorIterator<value_type>					iterator;
			typedef ConstVectorIterator<value_type>				const_iterator;
			typedef ReverseVectorIterator<value_type>			reverse_iterator;
			typedef ConstReverseVectorIterator<value_type>		const_reverse_iterator;
		
		private:
			pointer		_array;
			size_type	_size;
			size_type	_capacity;

		public:
			/* Constructor */
			explicit Vector(void) : _array(NULL), _size(0), _capacity(0) {
				this->_array = new value_type[0];
			}

			explicit Vector(size_type n, const value_type& val = value_type()) : _array(NULL), _size(n), _capacity(n) {
				this->_array = new value_type[n];
				this->assign(n, val);
			}

			template <class InputIterator>
			Vector(InputIterator first, InputIterator last) : _array(NULL), _size(0), _capacity(0) {
				this->_capacity = ft::distance(first, last);
				this->_size = this->_capacity;
				this->_array = new value_type[this->_capacity];
				this->assign(first, last);
			}

			Vector(const Vector& other) : _array(NULL), _size(other._size), _capacity(other._capacity) {
				this->_array = new value_type[this->_capacity];
				*this = other;
			}

			/* Destructor */
			virtual ~Vector(void) {
				delete[] this->_array;
			}

			/* Assign */
			Vector& operator=(const Vector& other) {
				if (*this != other) {
					delete[] this->_array;
					this->_capacity = other._capacity;
					this->_size = 0;
					this->_array = new value_type[this->_capacity];
					this->assign(other.begin(), other.end());
				}
				return (*this);
			}

			/* Iterators member functions */
			iterator begin(void) {
				return (iterator(this->_array));
			}

			const_iterator begin(void) const {
				return (const_iterator(this->_array));
			}

			iterator end(void) {
				return (iterator(&this->_array[this->_size]));
			}

			const_iterator end(void) const {
				return (const_iterator(&this->_array[this->_size]));
			}

			reverse_iterator rbegin(void) {
				return (reverse_iterator(&this->_array[this->_size - 1]));
			}
			
			const_reverse_iterator rbegin(void) const {
				return (const_reverse_iterator(&this->_array[this->_size - 1]));
			}

			reverse_iterator rend(void) {
				return (reverse_iterator(this->_array - 1));
			}
			
			const_reverse_iterator rend(void) const {
				return (const_reverse_iterator(this->_array - 1));
			}
			
			/* Capacity member functions */
			size_type size() const {
				return (this->_size);
			}

			size_type max_size(void) const {
				return (std::numeric_limits<size_type>::max()/sizeof(value_type));
			}

			void resize(size_type n, const value_type& val = value_type()) {
				if (n > this->_capacity)
					this->reserve(n);
				while (n > this->_size)
					this->push_back(val);
				while (n < this->_size)
					this->pop_back();
			}

			size_type capacity(void) const {
				return (this->_capacity);
			}

			bool empty(void) const {
				return (!this->_size);
			}

			void reserve(size_type n) {
				if (n > this->max_size())
					throw (std::length_error("max_size reached"));
				if (n >= this->_capacity) {
					this->_capacity = (n > this->_capacity * 2) ? n : this->_capacity * 2;
					pointer tmp = new value_type[this->_capacity];
					for (size_type i = 0; i < this->_size; i++) {
						tmp[i] = this->_array[i];
					}
					delete[] this->_array;
					this->_array = tmp;
				}
			}

			/* Element acces member functions */
			reference operator[](size_type n) {
				if (n >= this->_size)
					throw (std::out_of_range("out of range"));
				return (this->_array[n]);
			}			
			
			const_reference operator[](size_type n) const {
				if (n >= this->_size)
					throw (std::out_of_range("out of range"));
				return (this->_array[n]);
			}

			reference at(size_type n) {
				if (n >= this->_size)
					throw (std::out_of_range("out of range"));
				return (this->_array[n]);
			}			
			
			const_reference at(size_type n) const {
				if (n >= this->_size)
					throw (std::out_of_range("out of range"));
				return (this->_array[n]);
			}

			reference front(void) {
				return (this->_array[0]);
			}			
			
			const_reference front(void) const {
				return (this->_array[0]);
			}

			reference back(void) {
				return (this->_array[this->_size - 1]);
			}			
			
			const_reference back(void) const {
				return (this->_array[this->_size - 1]);
			}

			/* Modifiers member functions */
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last) {
				this->clear();
				this->reserve(ft::distance(first, last));
				while (first != last) {
					push_back(*first);
					++first;
				}
			}

			void assign(size_type n, const value_type& val = value_type()) {
				this->clear();
				this->reserve(n);
				while (n--)
					push_back(val);
			}

			void push_back(const value_type& val) {
				if (this->_size == this->_capacity) {
					this->reserve(this->_capacity * 2);
				}
				this->_array[this->_size] = val;
				++this->_size;
			}

			void pop_back(void) {
				if (this->_size)
					--this->_size;
			}

			iterator insert(iterator position, const value_type &val) {
				size_type n = ft::distance(begin(), position);
				insert(position, static_cast<size_type>(1), static_cast<value_type>(val));
				return (iterator(&this->_array[n]));
			}

			void insert(iterator position, size_type n, const value_type &val) {
				if (this->_size + n > this->_capacity)
					this->reserve(this->_size + n);
				Vector tmp(position, this->end());
				this->_size -= ft::distance(position, this->end());
				while (n) {
					this->push_back(val);
					--n;
				}
				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}
			}

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last) {
				size_type lenght = ft::distance(first, last);
				if (this->_size + lenght > this->_capacity)
					this->reserve(this->_size + lenght);
				Vector tmp(position, this->end());
				this->_size -= ft::distance(position, this->end());
				while (first != last) {
					this->push_back(*first);
					++first;
				}
				iterator it = tmp.begin();
				while (it != tmp.end()) {
					push_back(*it);
					++it;
				}	
			}

			iterator erase(iterator position) {
				iterator ret = position;
				while (position != this->end() - 1) {
					*position = *(position + 1);
					++position;
				}
				--this->_size;
				return (ret);
			}

			iterator erase(iterator first, iterator last) {
				iterator			tmp2;
				iterator			tmp;
	
				tmp2 = last;
				tmp = first;
				while (last != this->end())
				{
					*tmp = *last;
					tmp++;
					last++;
				}
				last = tmp2;
				tmp = first;
				while (tmp != last)
				{
					tmp++;
					this->_size--;
				}
				return (first);
			}

			void swap(Vector& other) {
				ft::swap_item(this->_array, other._array);
				ft::swap_item(this->_size, other._size);
				ft::swap_item(this->_capacity, other._capacity);
			}

			void clear(void) {
				while (this->_size)
					this->pop_back();
			}
	};

	/* Relational operators (vector) */
	template <class T>
	bool operator==(const ft::Vector<T>& lhs, const ft::Vector<T>& rhs) {
		return (lhs.size() == rhs.size() && ft::is_equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T>
	bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
		return (!(lhs == rhs));
	}
	
	template <class T>
	bool operator<(const Vector<T>& lhs, const Vector<T>& rhs) {
		return ft::compare_containers(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template <class T>
	bool operator>(const Vector<T>& lhs, const Vector<T>& rhs) {
		return (rhs < lhs);
	}
	
	template <class T>
	bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs) {
		return !(rhs < lhs);
	}
	
	template <class T>
	bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs) {
		return !(lhs < rhs);
	}
	
	template <class T>
	void swap (Vector<T>& x, Vector<T>& y) {
		x.swap(y);
	}
};

#endif
