/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:13:45 by memartin          #+#    #+#             */
/*   Updated: 2021/02/10 16:33:58 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include "ListIterator.hpp"
# include <cstddef>

namespace ft {
	template <class T>
	class List {
		public:
			typedef T												value_type;
			typedef value_type										&reference;
			typedef const value_type								&const_reference;
			typedef value_type										*pointer;
			typedef const value_type								*const_pointer;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;
			typedef Node<T>											*node_ptr;
			typedef ft::ListIterator<value_type>					iterator;
			typedef ft::ConstListIterator<value_type>				const_iterator;
			typedef ft::ReverseListIterator<value_type>				reverse_iterator;
			typedef ft::ConstReverseListIterator<value_type>		const_reverse_iterator;

		private:
			node_ptr			_anchor;
			size_type			_size;

			void	initList(void) {
				this->_anchor = new Node<value_type>();
				this->_anchor->next = this->_anchor;
				this->_anchor->prev = this->_anchor;
				this->_size = 0;
			}

			void swapNode(node_ptr a, node_ptr b) {
				value_type tmp = a->data;
				a->data = b->data;
				b->data = tmp;
			}
			
		public:
			/* Constructor */
			explicit List(void) : _anchor(NULL), _size(0) {
				this->initList();
			}

			explicit List(size_type n, const value_type& val = value_type()) : _anchor(NULL), _size(n) {
				this->initList();
				this->assign(n, val);
			}

			template <class InputIterator>
  			List(InputIterator first, InputIterator last) {
				this->initList();
				this->assign(first, last);
			}

			List(const List &other) {
				this->initList();
				this->assign(other.begin(), other.end());
			}

			/* Destructor */
			virtual ~List(void) {
				this->clear();
				delete this->_anchor;
			}

			/* Assign */
			List& operator=(const List &other) {
				this->assign(other.begin(), other.end());
				return (*this);
			}

			/* Iterators member functions */
			iterator begin(void) {
				return (iterator(this->_anchor->next));
			}

			const_iterator begin(void) const {
				return (const_iterator(this->_anchor->next));
			}

			iterator end(void) {
				return (iterator(this->_anchor));
			}

			const_iterator end(void) const {
				return (const_iterator(this->_anchor));
			}

			reverse_iterator rbegin(void) {
				return (reverse_iterator(this->_anchor->prev));
			}

			const_reverse_iterator rbegin(void) const {
				return (const_reverse_iterator(this->_anchor->prev));
			}

			reverse_iterator rend(void) {
				return (reverse_iterator(this->_anchor));
			}

			const_reverse_iterator rend(void) const {
				return (const_reverse_iterator(this->_anchor));
			}

			/* Capacity member functions */
			bool empty(void) const {
				return (!this->_size);
			}

			size_type size(void) const {
				return (this->_size);
			}

			size_type max_size(void) const {
				return (std::numeric_limits<size_type>::max() / sizeof(this->_anchor));
			}

			/* Element access member functions */
			reference front(void) {
				return (this->_anchor->next->data);
			}
			
			const_reference front(void) const {
				return (this->_anchor->next->data);
			}

			reference back(void) {
				return (this->_anchor->prev->data);
			}
			
			const_reference back(void) const {
				return (this->_anchor->prev->data);
			}

			/* Modifiers member functions */
			template <class InputIterator>
  			void assign(InputIterator first, InputIterator last) {
				this->clear();
				while (first != last) {
					this->push_back(*first);
					++first;
				}
			}

			void assign(size_type n, const value_type &val) {
				this->clear();
				while (n > 0) {
					this->push_back(val);
					--n;
				}
			}

			void push_front(const value_type &val) {
				Node<T> *ptr = new Node<T>(val);
				ptr->prev = this->_anchor;
				ptr->next = this->_anchor->next;
				this->_anchor->next->prev = ptr;
				this->_anchor->next = ptr;
				++this->_size;
			}

			void pop_front(void) {
				if (this->_size) {
					Node<T> *tmp;
					tmp = this->_anchor->next->next;
					delete this->_anchor->next;
					this->_anchor->next = tmp;
					tmp->prev = this->_anchor;
					--this->_size;
				}
			}

			void push_back(const value_type &val) {
				Node<T> *ptr = new Node<T>(val);
				ptr->next = this->_anchor;
				ptr->prev = this->_anchor->prev;
				this->_anchor->prev->next = ptr;
				this->_anchor->prev = ptr;
				++this->_size;
			}

			void pop_back(void) {
				if (this->_size) {
					Node<T> *tmp;
					tmp = this->_anchor->prev->prev;
					delete this->_anchor->prev;
					tmp->next = this->_anchor;
					this->_anchor->prev = tmp;
					--this->_size;
				}
			}

			iterator insert(iterator position, const value_type &val) {
				Node<T> *ptr = new Node<T>(val);
				ptr->prev = position.getptr()->prev;
				ptr->next = position.getptr();
				ptr->next->prev = ptr;
				ptr->prev->next = ptr;
				++this->_size;
				return (iterator(ptr));
			}

			void insert(iterator position, size_type n, const value_type &val) {
				while (n > 0) {
					this->insert(position, val);
					--n;
				}
			}

			template <class InputIterator>
    		void insert(iterator position, InputIterator first, InputIterator last) {
				while (first != last) {
					this->insert(position, *first);
					++first;
				}
			}
			
			iterator erase(iterator position) {
				Node<T> *tmp = position.getptr();
				if (tmp != this->_anchor) {
					tmp->next->prev = tmp->prev;
					tmp->prev->next = tmp->next;
					++position;
					delete tmp;
					--this->_size;
					return (position);
				}
				++position;
				return (position);
			}

			iterator erase(iterator first, iterator last) {
				while (first != last) {
					erase(first++);
				}
				return (first);
			}

			void swap(List &other) {
				size_type	size_tmp;
				node_ptr	ptr_tmp;

				size_tmp = this->_size;
				this->_size = other._size;
				other._size = size_tmp;
				ptr_tmp = this->_anchor;
				this->_anchor = other._anchor;
				other._anchor = ptr_tmp;
			}

			void resize(size_type n, value_type val = value_type()) {
				while (n > this->_size) {
					this->push_back(val);
				}
				while (n < this->_size) {
					this->pop_back();
				}
			}
			
			void clear(void) {
				while (this->_size)
					this->pop_back();
			}

			/* Operation member functions */
			void splice(iterator position, List &x) {
				this->splice(position, x, x.begin(), x.end());
			}

			void splice(iterator position, List &x, iterator i) {
				iterator next(i);
				++next;
				this->splice(position, x, i, next);
			}

			void splice(iterator position, List &x, iterator first, iterator last) {
				this->_size += ft::distance(first, last);
				x._size -= ft::distance(first, last);
				node_ptr first_x = first.getptr();
				node_ptr last_x = last.getptr();
				node_ptr last_elem = last_x->prev;
				node_ptr pos = position.getptr();
				first_x->prev->next = last_x;
				last_x->prev = first_x->prev;
				pos->prev->next = first_x;
				first_x->prev = pos->prev;
				pos->prev = last_elem;
				last_elem->next = pos;
			}

			void remove(const value_type &val) {
				iterator it = this->begin();
				while (it != this->end()) {
					if (*it == val)
						it = erase(it);
					else
						++it;
				}
			}

			template <class Predicate>
			void remove_if(Predicate pred) {
				iterator it = this->begin();
				while (it != this->end()) {
					if (pred(*it))
						it = erase(it);
					else
						++it;
				}
			}

			void unique(void) {
				iterator it = this->begin();
				++it;
				while (it != this->end()) {
					if (*it == it.getptr()->prev->data)
						it = erase(it);
					else
						++it;
				}
			}

			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred) {
				iterator it = this->begin();
				++it;
				while (it != this->end()) {
					if (binary_pred(*it, it.getptr()->prev->data))
						it = erase(it);
					else
						++it;
				}
			}

			void merge(List &x) {
				if (this == &x)
					return ;
				iterator it = this->begin();
				iterator xit = x.begin();
				iterator tmp = xit;
				while (it != this->end() && xit != x.end()) {
					while (it != this->end() && (*it <= *xit))
						++it;
					tmp = xit;
					++xit;
					this->splice(it, x, tmp);
				}
				if (xit != x.end())
					this->splice(it, x, xit, x.end());
			}

			template <class Compare>
			void merge(List &x, Compare comp) {
				if (this == &x)
					return ;
				iterator it = this->begin();
				iterator xit = x.begin();
				iterator tmp = xit;
				while (it != this->end() && xit != x.end()) {
					while (it != this->end() && comp(*it, *xit))
						++it;
					tmp = xit;
					++xit;
					this->splice(it, x, tmp);
				}
				if (xit != x.end())
					this->splice(it, x, xit, x.end());
			}

			void sort(void) {
				iterator it = this->begin();
				++it;
				size_type n = this->_size;
				--n;
				while (n) {
					while (it != this->end()) {
						if (*it < it.getptr()->prev->data)
							this->swapNode(it.getptr(), it.getptr()->prev);
						++it;
					}
					it = this->begin();
					++it;
					--n;
				}
			}

			template <class Compare>
			void sort(Compare comp) {
				iterator it = this->begin();
				++it;
				size_type n = this->_size;
				--n;
				while (n) {
					while (it != this->end()) {
						if (comp(*it, it.getptr()->prev->data))
							this->swapNode(it.getptr(), it.getptr()->prev);
						++it;
					}
					it = this->begin();
					++it;
					--n;
				}
			}

			void reverse(void) {
				iterator begin = this->begin();
				iterator end = this->end();
				size_type n = this->_size / 2;
				--end;
				while (n) {
					this->swapNode(begin.getptr(), end.getptr());
					++begin;
					--end;
					--n;
				}
			}
	};

	/* Relational operators (list) */
	template <class T>
	bool operator==(const ft::List<T>& lhs, const ft::List<T>& rhs) {
		return (lhs.size() == rhs.size() && ft::is_equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template <class T>
	bool operator!=(const List<T>& lhs, const List<T>& rhs) {
		return (!(lhs == rhs));
	}
	
	template <class T>
	bool operator<(const List<T>& lhs, const List<T>& rhs) {
		return ft::compare_containers(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template <class T>
	bool operator>(const List<T>& lhs, const List<T>& rhs) {
		return (rhs < lhs);
	}
	
	template <class T>
	bool operator<=(const List<T>& lhs, const List<T>& rhs) {
		return (!(rhs < lhs));
	}
	
	template <class T>
	bool operator>=(const List<T>& lhs, const List<T>& rhs) {
		return !(lhs < rhs);
	}
	
	template <class T>
	void swap (List<T>& x, List<T>& y) {
		x.swap(y);
	}

};

#endif