/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:23:21 by memartin          #+#    #+#             */
/*   Updated: 2021/01/21 18:09:39 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include "ListNode.hpp"

namespace ft {
	template <class T>
	class ListIterator {
		public:
			typedef T         			value_type;
    		typedef T					*pointer;
    		typedef T					&reference;
    		typedef std::ptrdiff_t  	difference_type;
			typedef Node<T>				*node_ptr;

		protected:
			node_ptr					ptr;
	
		public:
			ListIterator(void) {}
			ListIterator(const ListIterator &other) : ptr(other.ptr) {}
			ListIterator(const node_ptr list) : ptr(list) {}
			~ListIterator(void) {}
			
			ListIterator& operator=(const ListIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ListIterator& operator++(void) {
				this->ptr = this->ptr->next;
				return (*this);
			}

			ListIterator operator++(int) {
				ListIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ListIterator& operator--(void) {
				this->ptr = this->ptr->prev;
				return (*this);
			}

			ListIterator operator--(int) {
				ListIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ListIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ListIterator &other) const {
				return (this->ptr != other.ptr);
			}

			reference operator*(void) {
				return (this->ptr->data);
			}
			
			pointer operator->(void) {
				return (&(this->ptr->data));
			}

			node_ptr getptr(void) {
				return (ptr);
			}
	};

	template <class T>
	class ConstListIterator {
		public:
			typedef T         			value_type;
    		typedef T					*pointer;
    		typedef T					&reference;
    		typedef std::ptrdiff_t  	difference_type;
			typedef Node<T>				*node_ptr;

		protected:
			node_ptr					ptr;
	
		public:
			ConstListIterator(void) {}
			ConstListIterator(const ConstListIterator &other) : ptr(other.ptr) {}
			ConstListIterator(const node_ptr list) : ptr(list) {}
			~ConstListIterator(void) {}
			
			ConstListIterator& operator=(const ConstListIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ConstListIterator& operator++(void) {
				this->ptr = this->ptr->next;
				return (*this);
			}

			ConstListIterator operator++(int) {
				ConstListIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ConstListIterator& operator--(void) {
				this->ptr = this->ptr->prev;
				return (*this);
			}

			ConstListIterator operator--(int) {
				ConstListIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ConstListIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ConstListIterator &other) const {
				return (this->ptr != other.ptr);
			}

			const T& operator*(void) {
				return (this->ptr->data);
			}
			
			pointer operator->(void) {
				return (&(this->ptr->data));
			}

			node_ptr getptr(void) {
				return (ptr);
			}
	};

	template <class T>
	class ReverseListIterator {
		public:
			typedef T         			value_type;
    		typedef T					*pointer;
    		typedef T					&reference;
    		typedef std::ptrdiff_t  	difference_type;
			typedef Node<T>				*node_ptr;

		protected:
			node_ptr					ptr;
	
		public:
			ReverseListIterator(void) {}
			ReverseListIterator(const ReverseListIterator &other) : ptr(other.ptr) {}
			ReverseListIterator(const node_ptr list) : ptr(list) {}
			~ReverseListIterator(void) {}
			
			ReverseListIterator& operator=(const ReverseListIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ReverseListIterator& operator++(void) {
				this->ptr = this->ptr->prev;
				return (*this);
			}

			ReverseListIterator operator++(int) {
				ReverseListIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ReverseListIterator& operator--(void) {
				this->ptr = this->ptr->next;
				return (*this);
			}

			ReverseListIterator operator--(int) {
				ReverseListIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ReverseListIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ReverseListIterator &other) const {
				return (this->ptr != other.ptr);
			}

			reference operator*(void) {
				return (this->ptr->data);
			}
			
			pointer operator->(void) {
				return (&(this->ptr->data));
			}
			
			node_ptr getptr(void) {
				return (ptr);
			}
	};

	template <class T>
	class ConstReverseListIterator {
		public:
			typedef T         			value_type;
    		typedef T					*pointer;
    		typedef T					&reference;
    		typedef std::ptrdiff_t  	difference_type;
			typedef Node<T>				*node_ptr;

		protected:
			node_ptr					ptr;
	
		public:
			ConstReverseListIterator(void) {}
			ConstReverseListIterator(const ConstReverseListIterator &other) : ptr(other.ptr) {}
			ConstReverseListIterator(const node_ptr list) : ptr(list) {}
			~ConstReverseListIterator(void) {}
			
			ConstReverseListIterator& operator=(const ConstReverseListIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ConstReverseListIterator& operator++(void) {
				this->ptr = this->ptr->prev;
				return (*this);
			}

			ConstReverseListIterator operator++(int) {
				ConstReverseListIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ConstReverseListIterator& operator--(void) {
				this->ptr = this->ptr->next;
				return (*this);
			}

			ConstReverseListIterator operator--(int) {
				ConstReverseListIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ConstReverseListIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ConstReverseListIterator &other) const {
				return (this->ptr != other.ptr);
			}

			const T& operator*(void) {
				return (this->ptr->data);
			}
			
			pointer operator->(void) {
				return (&(this->ptr->data));
			}
			
			node_ptr getptr(void) {
				return (ptr);
			}
	};
	
};

#endif
