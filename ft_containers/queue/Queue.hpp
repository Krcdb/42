/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:07:20 by memartin          #+#    #+#             */
/*   Updated: 2021/02/03 17:11:07 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../list/List.hpp"

namespace ft {
	template <class T, class Container = ft::List<T> >
	class Queue {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
		
		private:
			container_type		_container;

		public:
			/* Constructor */
			explicit Queue(const container_type& ctnr = container_type()) : _container(ctnr) {}

			/* Member functions */
			bool empty(void) const {
				return (this->_container.empty());
			}

			size_type size(void) const {
				return (this->_container.size());
			}

			value_type& front(void) {
				return (this->_container.front());
			}

			const value_type& front(void) const {
				return (this->_container.front());
			}

			value_type& back(void) {
				return (this->_container.back());
			}

			const value_type& back(void) const {
				return (this->_container.back());
			}

			void push(const value_type& val) {
				this->_container.push_back(val);
			}

			void pop(void) {
				this->_container.pop_front();
			}

			/* Relational operators */
			friend bool operator==(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
				return (lhs._container == rhs._container);
			}

			friend bool operator!=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
				return (lhs._container != rhs._container);
			}

			friend bool operator<(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
				return (lhs._container < rhs._container);
			}

			friend bool operator<=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
				return (lhs._container <= rhs._container);
			}

			friend bool operator>(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
				return (lhs._container > rhs._container);
			}

			friend bool operator>=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
				return (lhs._container >= rhs._container);
			}
	};
};

#endif