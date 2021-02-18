/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:07:15 by memartin          #+#    #+#             */
/*   Updated: 2021/02/01 17:00:17 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include <cstddef>
#include <limits>
#include "../utils/utils.hpp"

namespace ft {
	template <class T>
	class VectorIterator {
		public:
			typedef T					value_type;
			typedef T					*pointeur;
			typedef T					&reference;
			typedef std::ptrdiff_t		difference_type;

		protected:
			pointeur					ptr;
		
		public:
			VectorIterator(void) {}
			VectorIterator(const VectorIterator &other) : ptr(other.ptr) {}
			VectorIterator(const pointeur other) : ptr(other) {}
			~VectorIterator(void) {}

			VectorIterator& operator=(const VectorIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			VectorIterator &operator++(void) {
				this->ptr++;
				return (*this);
			}

			VectorIterator operator++(int) {
				VectorIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			VectorIterator &operator--(void) {
				this->ptr--;
				return (*this);
			}

			VectorIterator operator--(int) {
				VectorIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const VectorIterator &other) {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const VectorIterator &other) {
				return (this->ptr != other.ptr);
			}

			reference operator*(void) {
				return (*this->ptr);
			}

			pointeur operator->(void) {
				return *(&(this->ptr));
			}

			VectorIterator operator+(int n) {
				VectorIterator out(*this);
				out.ptr += n;
				return (out);
			}

			VectorIterator operator+=(int n) {
				this->ptr += n;
				return (*this);
			}

			VectorIterator operator-(int n) {
				VectorIterator out(*this);
				out.ptr -= n;
				return (out);
			}

			VectorIterator operator-(VectorIterator other) {
				return (this->ptr - other.ptr);
			}

			VectorIterator operator-=(int n) {
				this->ptr -= n;
				return (*this);
			}
			bool operator<(const VectorIterator other) {
				return (this->ptr < other.ptr);
			}
			
			bool operator<=(const VectorIterator other) {
				return (this->ptr <= other.ptr);
			}
						
			bool operator>(const VectorIterator other) {
				return (this->ptr > other.ptr);
			}
						
			bool operator>=(const VectorIterator other) {
				return (this->ptr >= other.ptr);
			}

			reference operator[](int n) {
				return (*(this->ptr + n));
			}
	};

	template <class T>
	class ReverseVectorIterator {
		public:
			typedef T					value_type;
			typedef T					*pointeur;
			typedef T					&reference;
			typedef std::ptrdiff_t		difference_type;

		protected:
			pointeur					ptr;
		
		public:
			ReverseVectorIterator(void) {}
			ReverseVectorIterator(const ReverseVectorIterator &other) : ptr(other.ptr) {}
			ReverseVectorIterator(const pointeur other) : ptr(other) {}
			~ReverseVectorIterator(void) {}

			ReverseVectorIterator& operator=(const ReverseVectorIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ReverseVectorIterator &operator++(void) {
				this->ptr--;
				return (*this);
			}

			ReverseVectorIterator operator++(int) {
				ReverseVectorIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ReverseVectorIterator &operator--(void) {
				this->ptr++;
				return (*this);
			}

			ReverseVectorIterator operator--(int) {
				ReverseVectorIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ReverseVectorIterator &other) {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ReverseVectorIterator &other) {
				return (this->ptr != other.ptr);
			}

			reference operator*(void) {
				return (*this->ptr);
			}

			pointeur operator->(void) {
				return *(&(this->ptr));
			}

			ReverseVectorIterator operator+(int n) {
				ReverseVectorIterator out(*this);
				out.ptr -= n;
				return (out);
			}

			ReverseVectorIterator operator+=(int n) {
				this->ptr -= n;
				return (*this);
			}

			ReverseVectorIterator operator-(int n) {
				ReverseVectorIterator out(*this);
				out.ptr += n;
				return (out);
			}

			ReverseVectorIterator operator-=(int n) {
				this->ptr += n;
				return (*this);
			}
			bool operator<(const ReverseVectorIterator other) {
				return (this->ptr < other.ptr);
			}
			
			bool operator<=(const ReverseVectorIterator other) {
				return (this->ptr <= other.ptr);
			}
						
			bool operator>(const ReverseVectorIterator other) {
				return (this->ptr > other.ptr);
			}
						
			bool operator>=(const ReverseVectorIterator other) {
				return (this->ptr >= other.ptr);
			}

			reference operator[](int n) {
				return (*(this->ptr + n));
			}
	};

	template <class T>
	class ConstVectorIterator {
		public:
			typedef T					value_type;
			typedef T					*pointeur;
			typedef T					&reference;
			typedef std::ptrdiff_t		difference_type;

		protected:
			pointeur					ptr;
		
		public:
			ConstVectorIterator(void) {}
			ConstVectorIterator(const ConstVectorIterator &other) : ptr(other.ptr) {}
			ConstVectorIterator(const pointeur other) : ptr(other) {}
			~ConstVectorIterator(void) {}

			ConstVectorIterator& operator=(const ConstVectorIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ConstVectorIterator &operator++(void) {
				this->ptr++;
				return (*this);
			}

			ConstVectorIterator operator++(int) {
				ConstVectorIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ConstVectorIterator &operator--(void) {
				this->ptr--;
				return (*this);
			}

			ConstVectorIterator operator--(int) {
				ConstVectorIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ConstVectorIterator &other) {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ConstVectorIterator &other) {
				return (this->ptr != other.ptr);
			}

			const T& operator*(void) {
				return (*this->ptr);
			}

			pointeur operator->(void) {
				return *(&(this->ptr));
			}

			ConstVectorIterator operator+(int n) {
				ConstVectorIterator out(*this);
				out.ptr += n;
				return (out);
			}

			ConstVectorIterator operator+=(int n) {
				this->ptr += n;
				return (*this);
			}

			ConstVectorIterator operator-(int n) {
				ConstVectorIterator out(*this);
				out.ptr -= n;
				return (out);
			}

			ConstVectorIterator operator-(ConstVectorIterator other) {
				return (this->ptr - other.ptr);
			}

			ConstVectorIterator operator-=(int n) {
				this->ptr -= n;
				return (*this);
			}
			bool operator<(const ConstVectorIterator other) {
				return (this->ptr < other.ptr);
			}
			
			bool operator<=(const ConstVectorIterator other) {
				return (this->ptr <= other.ptr);
			}
						
			bool operator>(const ConstVectorIterator other) {
				return (this->ptr > other.ptr);
			}
						
			bool operator>=(const ConstVectorIterator other) {
				return (this->ptr >= other.ptr);
			}

			reference operator[](int n) {
				return (*(this->ptr + n));
			}
	};

	template <class T>
	class ConstReverseVectorIterator {
		public:
			typedef T					value_type;
			typedef T					*pointeur;
			typedef T					&reference;
			typedef std::ptrdiff_t		difference_type;

		protected:
			pointeur					ptr;
		
		public:
			ConstReverseVectorIterator(void) {}
			ConstReverseVectorIterator(const ConstReverseVectorIterator &other) : ptr(other.ptr) {}
			ConstReverseVectorIterator(const pointeur other) : ptr(other) {}
			~ConstReverseVectorIterator(void) {}

			ConstReverseVectorIterator& operator=(const ConstReverseVectorIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ConstReverseVectorIterator &operator++(void) {
				this->ptr--;
				return (*this);
			}

			ConstReverseVectorIterator operator++(int) {
				ConstReverseVectorIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ConstReverseVectorIterator &operator--(void) {
				this->ptr++;
				return (*this);
			}

			ConstReverseVectorIterator operator--(int) {
				ConstReverseVectorIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ConstReverseVectorIterator &other) {
				return (this->ptr == other.ptr);
			}

			bool operator!=(const ConstReverseVectorIterator &other) {
				return (this->ptr != other.ptr);
			}

			const T& operator*(void) {
				return (*this->ptr);
			}

			pointeur operator->(void) {
				return *(&(this->ptr));
			}

			ConstReverseVectorIterator operator+(int n) {
				ConstReverseVectorIterator out(*this);
				out.ptr -= n;
				return (out);
			}

			ConstReverseVectorIterator operator+=(int n) {
				this->ptr -= n;
				return (*this);
			}

			ConstReverseVectorIterator operator-(int n) {
				ConstReverseVectorIterator out(*this);
				out.ptr += n;
				return (out);
			}

			ConstReverseVectorIterator operator-=(int n) {
				this->ptr += n;
				return (*this);
			}
			bool operator<(const ConstReverseVectorIterator other) {
				return (this->ptr < other.ptr);
			}
			
			bool operator<=(const ConstReverseVectorIterator other) {
				return (this->ptr <= other.ptr);
			}
						
			bool operator>(const ConstReverseVectorIterator other) {
				return (this->ptr > other.ptr);
			}
						
			bool operator>=(const ConstReverseVectorIterator other) {
				return (this->ptr >= other.ptr);
			}

			reference operator[](int n) {
				return (*(this->ptr + n));
			}
	};
};

#endif
