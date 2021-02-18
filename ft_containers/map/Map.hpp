/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:28:25 by memartin          #+#    #+#             */
/*   Updated: 2021/02/15 11:55:49 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <iostream>
# include "MapIterator.hpp"
# include "../utils/utils.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key> >
	class Map {
		public:
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef std::pair<const key_type, mapped_type>					value_type;
			typedef std::less<key_type>										key_compare;
			typedef T														&reference;
			typedef const T													&const_reference;
			typedef	T														*pointer;
			typedef	const T													*const_pointer;
			typedef ptrdiff_t												difference_type;
			typedef size_t													size_type;
			typedef MapNode<Key, T>											*node_ptr;
			typedef ft::MapIterator<Key, T>									iterator;
			typedef ft::ConstMapIterator<Key, T>							const_iterator;
			typedef ft::ReverseMapIterator<Key, T>							reverse_iterator;
			typedef ft::ConstReverseMapIterator<Key, T>						const_reverse_iterator;


			class value_compare {
  				friend class map;

				protected:
  					Compare comp;

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

  					value_compare (Compare c) : comp(c) {}
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		protected:
			node_ptr		_root;
			node_ptr		_start;
			node_ptr		_end;
			key_compare		_comp;
			size_type		_size;

			void init_map(void) {
				this->_start = new MapNode<Key, T>;
				this->_end = new MapNode<Key, T>;
				this->make_bounds();
			}

			void make_bounds(void) {
				this->_start->left = NULL;
				this->_start->right = NULL;
				this->_end->right = NULL;
				this->_end->left = NULL;
				this->_end->parent = this->_start;
				this->_start->parent = this->_end;
				this->_root = NULL;
			}

			size_t height_successor(node_ptr node) {
				if (!node->right)
					return (0);
				size_t height = 1;
				node_ptr successor = node->right;
				while (successor->left) {
					successor = successor->left;
					++height;
				}
				return (height);
			}

			size_t height_predecessor(node_ptr node) {
				if (!node->left)
					return (0);
				size_t height = 1;
				node_ptr predecessor = node->left;
				while (predecessor->right) {
					predecessor = predecessor->right;
					++height;
				}
				return (height);
			}

			size_t delete_node(node_ptr node) {
				node_ptr del_node = node;
				
				//std::cout << "\ndelete node" << std::endl;
				//std::cout << "node to del " << node->pair.first << std::endl;
				if (!node || node == this->_start || node == this->_end)
					return (0);
				else if ((!node->left || node->left == this->_start) && (!node->right || node->right == this->_end)) {
					//std::cout << "0 child\n";
					if (node->parent && node->parent->left == node) {
						//std::cout << "node is left\n";
						if (node->left) {
							node->parent->left = this->_start;
							this->_start->parent = node->parent;
							//std::cout << "assign start\n";
						}
						else
							node->parent->left = NULL;
					}
					else if (node->parent && node->parent->right == node) {
						if (node->right) {
							node->parent->right = this->_end;
							this->_end->parent = node->parent;
						}
						else
							node->parent->right = NULL;
					}
					else
						make_bounds();
					delete node;
					return (1);
				}
				else if (height_predecessor(node) <= height_successor(node)) {
					//std::cout << "successor\n";
					del_node = node->right;
					while (del_node->left)
						del_node = del_node->left;
					//std::cout << "del_node before swap" << del_node->pair.first << std::endl;
					ft::swap_item(del_node->pair, node->pair);
					//std::cout << "del_node after swap" << del_node->pair.first << std::endl;
					if (del_node->parent && del_node->parent->left == del_node) {
						if (del_node->right) {
							del_node->parent->left = del_node->right;
							del_node->left->parent = del_node->parent;
						}
						else
							del_node->parent->left = NULL;
					}
					else if (del_node->parent && del_node->parent->right == del_node) {
						if (del_node->right) {
							del_node->parent->right = del_node->right;
							del_node->right->parent = del_node->parent;
						}
						else
							del_node->parent->right = NULL;
					}
					delete del_node;
					return (0);
				}
				else {
					del_node = node->left;
					while (del_node->right)
						del_node = del_node->right;
					ft::swap_item(del_node->pair, node->pair);
					if (del_node->parent && del_node->parent->left == del_node) {
						if (del_node->left) {
							del_node->parent->left = del_node->left;
							del_node->left->parent = del_node->parent;
						}
						else
							del_node->parent->left = NULL;
					}
					else if (del_node->parent && del_node->parent->right == del_node) {
						if (del_node->left) {
							del_node->parent->right = del_node->left;
							del_node->right->parent = del_node->parent;
						}
						else
							del_node->parent->right = NULL;
					}
					delete del_node;
				}
				return (0);
			}

		public:
			/* Constructor */
			explicit Map(const key_compare &comp = key_compare()) : _comp(comp), _size(0) {
				this->init_map();
			}

			template <class InputIterator>
			explicit Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare()) : _comp(comp), _size(0) {
				this->init_map();
				this->insert(first, last);
			}

			Map(const Map &other) : _comp(other._comp), _size(0) {
				this->init_map();
				this->insert(other.begin(), other.end());
			}

			/* Destructor */
			virtual ~Map(void) {
				this->clear();
				delete this->_start;
				delete this->_end;
			}

			/* Assign */
			Map& operator=(const Map &other) {
				if (this != &other) {
					this->clear();
					this->_comp = other._comp;
					this->insert(other.begin(), other.end());
				}
				return (*this);
			}

			/* Iterators member functions */
			iterator begin(void) {
				return (iterator(this->_start->parent));
			}

			const_iterator begin(void) const {
				return (const_iterator(this->_start->parent));
			}

			iterator end(void) {
				return (iterator(this->_end));
			}

			const_iterator end(void) const {
				return (const_iterator(this->_end));
			}

			reverse_iterator rbegin(void) {
				return (reverse_iterator(this->_end->parent));
			}

			const_reverse_iterator rbegin(void) const {
				return (const_reverse_iterator(this->_end->parent));
			}

			reverse_iterator rend(void) {
				return (reverse_iterator(this->_start));
			}

			const_reverse_iterator rend(void) const {
				return (const_reverse_iterator(this->_start));
			}

			/* Capacity member functions */
			bool empty(void) const {
				return (!this->_size);
			}

			size_type size(void) const {
				return (this->_size);
			}

			size_type max_size(void) const {
				return (std::numeric_limits<size_type>::max() / sizeof(this->_root));
			}

			/* Element acces member function */
			mapped_type &operator[](const key_type& k) {
				return (insert(std::make_pair(k, mapped_type())).first->second);
			}

			/* Modifiers member functions */
			std::pair<iterator, bool> insert(const value_type& val) {
				node_ptr node = this->_root;
				node_ptr new_node = new MapNode<Key, T>;

				new_node->parent = NULL;
				new_node->right = NULL;
				new_node->left = NULL;
				new_node->pair = val;
				if (this->_root) {
					while (!new_node->parent) {
						if (new_node->pair.first == node->pair.first) {
							delete new_node;
							return (std::pair<iterator, bool>(iterator(node), false));
						}
						if (this->_comp(new_node->pair.first, node->pair.first)) {
							if (node->left && node->left != this->_start)
								node = node->left;
							else {
								if (node->left == this->_start)
									this->_start->parent = new_node;
								new_node->parent = node;
								node->left = new_node;
								if (this->_start->parent == new_node)
									new_node->left = this->_start;
							}
						}
						else {
							if (node->right && node->right != this->_end)
								node = node->right;	
							else {
								if (node->right == this->_end)
									this->_end->parent = new_node;
								new_node->parent = node;
								node->right = new_node;
								if (this->_end->parent == new_node)
									new_node->right = this->_end;
							}
						}
					}
				}
				else {
					this->_root = new_node;
					this->_root->right = this->_end;
					this->_root->left = this->_start;
					this->_start->parent = new_node;
					this->_end->parent = new_node;
				}
				++this->_size;
				return (std::pair<iterator, bool>(iterator(new_node), true));
			}

			iterator insert(iterator position, const value_type& val) {
				node_ptr node = position.getPtr();
				node_ptr new_node = new MapNode<Key, T>;

				new_node->parent = NULL;
				new_node->right = NULL;
				new_node->left = NULL;
				new_node->pair = val;
				if (this->_root) {
					while (!new_node->parent) {
						if (node == this->_start || node == this->_end)
							node = this->_root;
						if (new_node->pair.first == node->pair.first) {
							delete new_node;
							return (iterator(node));
						}
						if (this->_comp(new_node->pair.first, node->pair.first)) {
							if (node->left && node->left != this->_start)
								node = node->left;
							else {
								if (node->left == this->_start)
									this->_start->parent = new_node;
								new_node->parent = node;
								node->left = new_node;
								if (this->_start->parent == new_node)
									new_node->left = this->_start;
							}
						}
						else {
							if (node->right && node->right != this->_end)
								node = node->right;	
							else {
								if (node->right == this->_end)
									this->_end->parent = new_node;
								new_node->parent = node;
								node->right = new_node;
								if (this->_end->parent == new_node)
									new_node->right = this->_end;
							}
						}
					}
				}
				else {
					this->_root = new_node;
					new_node->right = this->_end;
					new_node->left = this->_start;
					this->_start->parent = new_node;
					this->_end->parent = new_node;
				}
				++this->_size;
				return (iterator(new_node));
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				while (first != last) {
					this->insert(*first);
					++first;
				}
			}

			void erase(iterator position) {
				this->delete_node(position.getPtr());
				--this->_size;
			}

			size_type erase(const key_type& k) {
				node_ptr node = this->_root;

				while (node && node != this->_start && node != this->_end) {
					if (k == node->pair.first) {
						this->erase(iterator(node));
						return (1);
					}
					if (this->_comp(k, node->pair.first))
						node = node->left;
					else
						node = node->right;	
				}
				return (0);
			}

			void erase(iterator first, iterator last) {
				iterator tmp;
				size_t ret = 0;
				difference_type	nb = ft::distance(first, last);

				while (first != last && nb) {
					tmp = first;
					++tmp;
					ret = this->delete_node(first.getPtr());
					--nb;
					--this->_size;
					if (ret)
						first = tmp;
				}
			}

			void swap(Map& other) {
				ft::swap_item(this->_root, other._root);
				ft::swap_item(this->_start, other._start);
				ft::swap_item(this->_end, other._end);
				ft::swap_item(this->_size, other._size);
			}

			void clear(void) {
				this->erase(this->begin(), this->end());
			}

			/* Observers member funtions */
			key_compare key_comp(void) const {
				return (this->_comp);
			}

			value_compare value_comp(void) const {
				return (value_compare(this->_comp));
			}

			/* Operations member functions */
			iterator find(const key_type& k) {
				node_ptr node = this->_root;

				while (node && node != this->_start && node != this->_end) {
					if (k == node->pair.first)
						return (iterator(node));
					else if (this->_comp(k, node->pair.first))
						node = node->left;
					else
						node = node->right;
				}
				return (this->end());
			}

			const_iterator find(const key_type& k) const {
				node_ptr node = this->_root;

				while (node && node != this->_start && node != this->_end) {
					if (k == node->pair.first)
						return (const_iterator(node));
					else if (this->_comp(k, node->pair.first))
						node = node->left;
					else
						node = node->right;
				}
				return (this->end());
			}

			size_type count(const key_type& k) {
				return (this->find(k) != this->end());
			}

			iterator lower_bound(const key_type& k) {
				iterator it = this->begin();
				iterator it2 = this->end();
				
				while (it != it2) {
					if (this->_comp(it->first, k) == false)
						return (it);
					++it;
				}
				return (it2);
			}

			const_iterator lower_bound(const key_type& k) const {
				const_iterator it = this->begin();
				const_iterator it2 = this->end();
				
				while (it != it2) {
					if (this->_comp(it->first, k) == false)
						return (it);
					++it;
				}
				return (it2);
			}

			iterator upper_bound(const key_type& k) {
				iterator it = this->begin();
				iterator it2 = this->end();
				
				while (it != it2) {
					if (this->_comp(k, it->first))
						return (it);
					++it;
				}
				return (it2);
			}

			const_iterator upper_bound(const key_type& k) const {
				const_iterator it = this->begin();
				const_iterator it2 = this->end();
				
				while (it != it2) {
					if (this->_comp(k, it->first))
						return (it);
					++it;
				}
				return (it2);
			}
			
			std::pair<iterator,iterator>					equal_range(const key_type &k) {
				return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			std::pair<const_iterator,const_iterator>		equal_range(const key_type &k) const {
				return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

	};
};

#endif