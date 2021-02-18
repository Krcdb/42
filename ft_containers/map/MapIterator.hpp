/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:23:50 by memartin          #+#    #+#             */
/*   Updated: 2021/02/11 16:46:09 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <utility>
# include <limits>

namespace ft {
	template <class Key, class T>
	struct MapNode {
		MapNode				*parent;
		MapNode				*left;
		MapNode				*right;
		std::pair<Key, T>	pair;
	};

	template <class Key, class T>
	class MapIterator {
		public:
			typedef T         					value_type;
    		typedef T							*pointer;
    		typedef T							&reference;
    		typedef std::ptrdiff_t  			difference_type;
			typedef MapNode<Key, T>				*node_ptr;

		protected:
			node_ptr							ptr;

		public:
			MapIterator(void) {}
			MapIterator(const MapIterator &other) : ptr(other.ptr) {}
			MapIterator(const node_ptr map) : ptr(map) {}
			~MapIterator(void) {}

			MapIterator& operator=(const MapIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			MapIterator& operator++(void) {
				node_ptr		next;
				
				if (!this->ptr)
					return (*this);
				if (!this->ptr->right) {
					next = this->ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else {
					next = this->ptr->right;
					while (next->left)
						next = next->left;
				}
				this->ptr = next;
				return (*this);
			}

			MapIterator operator++(int) {
				MapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			MapIterator& operator--(void) {
				node_ptr 		prev;

				if (!this->ptr->left) {
					prev = this->ptr;
					while (prev->parent && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else {
					prev = this->ptr->left;
					while (prev->right)
						prev = prev->right;
				}
				this->ptr = prev;
				return (*this);
			}

			MapIterator operator--(int) {
				MapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const MapIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator !=(const MapIterator &other) const {
				return (this->ptr != other.ptr);
			}

			std::pair<Key, T> &operator*(void) {
				return (this->ptr->pair);
			}

			std::pair<Key, T> *operator->(void) {
				return (&this->ptr->pair);
			}

			node_ptr getPtr(void) {
				return (this->ptr);
			}
	};

	template <class Key, class T>
	class ConstMapIterator {
		public:
			typedef T         					value_type;
    		typedef T							*pointer;
    		typedef T							&reference;
    		typedef std::ptrdiff_t  			difference_type;
			typedef MapNode<Key, T>				*node_ptr;

		protected:
			node_ptr							ptr;

		public:
			ConstMapIterator(void) {}
			ConstMapIterator(const ConstMapIterator &other) : ptr(other.ptr) {}
			ConstMapIterator(const node_ptr map) : ptr(map) {}
			~ConstMapIterator(void) {}

			ConstMapIterator& operator=(const ConstMapIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ConstMapIterator& operator++(void) {
				node_ptr		next;
				
				if (!this->ptr)
					return (*this);
				if (!this->ptr->right) {
					next = this->ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else {
					next = this->ptr->right;
					while (next->left)
						next = next->left;
				}
				this->ptr = next;
				return (*this);
			}

			ConstMapIterator operator++(int) {
				ConstMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ConstMapIterator& operator--(void) {
				node_ptr 		prev;

				if (!this->ptr->left) {
					prev = this->ptr;
					while (prev->parent && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else {
					prev = this->ptr->left;
					while (prev->right)
						prev = prev->right;
				}
				this->ptr = prev;
				return (*this);
			}

			ConstMapIterator operator--(int) {
				ConstMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			bool operator==(const ConstMapIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator !=(const ConstMapIterator &other) const {
				return (this->ptr != other.ptr);
			}

			const std::pair<Key, T> &operator*(void) {
				return (this->ptr->pair);
			}

			std::pair<Key, T> *operator->(void) {
				return (&(this->ptr->pair));
			}
	};

	template <class Key, class T>
	class ReverseMapIterator {
		public:
			typedef T         					value_type;
    		typedef T							*pointer;
    		typedef T							&reference;
    		typedef std::ptrdiff_t  			difference_type;
			typedef MapNode<Key, T>				*node_ptr;

		protected:
			node_ptr							ptr;

		public:
			ReverseMapIterator(void) {}
			ReverseMapIterator(const ReverseMapIterator &other) : ptr(other.ptr) {}
			ReverseMapIterator(const node_ptr map) : ptr(map) {}
			~ReverseMapIterator(void) {}

			ReverseMapIterator& operator=(const ReverseMapIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ReverseMapIterator& operator--(void) {
				node_ptr		next;
				
				if (!this->ptr)
					return (*this);
				if (!this->ptr->right) {
					next = this->ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else {
					next = this->ptr->right;
					while (next->left)
						next = next->left;
				}
				this->ptr = next;
				return (*this);
			}

			ReverseMapIterator operator--(int) {
				ReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			ReverseMapIterator& operator++(void) {
				node_ptr 		prev;

				if (!this->ptr->left) {
					prev = this->ptr;
					while (prev->parent && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else {
					prev = this->ptr->left;
					while (prev->right)
						prev = prev->right;
				}
				this->ptr = prev;
				return (*this);
			}

			ReverseMapIterator operator++(int) {
				ReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			bool operator==(const ReverseMapIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator !=(const ReverseMapIterator &other) const {
				return (this->ptr != other.ptr);
			}

			std::pair<Key, T> &operator*(void) {
				return (this->ptr->pair);
			}

			std::pair<Key, T> *operator->(void) {
				return (&this->ptr->pair);
			}
	};

	template <class Key, class T>
	class ConstReverseMapIterator {
		public:
			typedef T         					value_type;
    		typedef T							*pointer;
    		typedef T							&reference;
    		typedef std::ptrdiff_t  			difference_type;
			typedef MapNode<Key, T>				*node_ptr;

		protected:
			node_ptr							ptr;

		public:
			ConstReverseMapIterator(void) {}
			ConstReverseMapIterator(const ConstReverseMapIterator &other) : ptr(other.ptr) {}
			ConstReverseMapIterator(const node_ptr map) : ptr(map) {}
			~ConstReverseMapIterator(void) {}

			ConstReverseMapIterator& operator=(const ConstReverseMapIterator &other) {
				if (this != &other)
					this->ptr = other.ptr;
				return (*this);
			}

			ConstReverseMapIterator& operator--(void) {
				node_ptr		next;
				
				if (!this->ptr)
					return (*this);
				if (!this->ptr->right) {
					next = this->ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else {
					next = this->ptr->right;
					while (next->left)
						next = next->left;
				}
				this->ptr = next;
				return (*this);
			}

			ConstReverseMapIterator operator--(int) {
				ConstReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			ConstReverseMapIterator& operator++(void) {
				node_ptr 		prev;

				if (!this->ptr->left) {
					prev = this->ptr;
					while (prev->parent && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else {
					prev = this->ptr->left;
					while (prev->right)
						prev = prev->right;
				}
				this->ptr = prev;
				return (*this);
			}

			ConstReverseMapIterator operator++(int) {
				ConstReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			bool operator==(const ConstReverseMapIterator &other) const {
				return (this->ptr == other.ptr);
			}

			bool operator !=(const ConstReverseMapIterator &other) const {
				return (this->ptr != other.ptr);
			}

			std::pair<Key, T> &operator*(void) {
				return (this->ptr->pair);
			}

			std::pair<Key, T> *operator->(void) {
				return (&this->ptr->pair);
			}
	};
};

#endif