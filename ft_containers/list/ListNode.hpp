/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:10:38 by memartin          #+#    #+#             */
/*   Updated: 2020/12/29 13:54:07 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
# define LISTNODE_HPP

# include <cstring>
# include <cstddef>
# include <limits>
# include "../utils/utils.hpp"

namespace ft {
	template <typename T>
	class Node {
		public:
			T			data;
			Node<T>		*next;
			Node<T>		*prev;

			//Node(void) : data(), next(NULL), prev(NULL) {}
			Node(const T &val = T()) : data(val), next(NULL), prev(NULL) {}
			Node(const Node &other) : data(other.data), next(other.next), prev(other.prev) {}
			~Node() {}

			Node& operator=(const Node &other) {
				if (this != other)
				{
					this->data = other.data;
					this->next = other.next;
					this->prev = other.prev;
				}
				return (*this);
			}

			bool operator==(const Node &other) {
				return (this->data == other.data && this->next == other.next && this->prev == other.prev); 
			}
	
			bool operator!=(const Node &other) {
				return (*this != other); 
			}
	};
};

#endif