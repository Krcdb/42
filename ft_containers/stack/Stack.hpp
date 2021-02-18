/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <memartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:46:26 by memartin          #+#    #+#             */
/*   Updated: 2021/02/03 16:43:33 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../list/List.hpp"

namespace ft {
	template <class T, class Container = ft::List<T> >
	class Stack {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
		
		private:
			container_type		_container;

		public:
			/* Constructor */
			explicit Stack(const container_type& ctnr = container_type()) : _container(ctnr) {}

			/* Member functions */
			bool empty(void) const {
				return (this->_container.empty());
			}

			size_type size(void) const {
				return (this->_container.size());
			}

			value_type& top(void) {
				return (this->_container.front());
			}

			const value_type& top(void) const {
				return (this->_container.front());
			}

			void push(const value_type& val) {
				this->_container.push_front(val);
			}

			void pop(void) {
				this->_container.pop_front();
			}

			/* Relational operators */
			friend bool operator==(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
				return (lhs._container == rhs._container);
			}

			friend bool operator!=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
				return (lhs._container != rhs._container);
			}

			friend bool operator<(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
				return (lhs._container < rhs._container);
			}

			friend bool operator<=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
				return (lhs._container <= rhs._container);
			}

			friend bool operator>(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
				return (lhs._container > rhs._container);
			}

			friend bool operator>=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
				return (lhs._container >= rhs._container);
			}
	};
};

#endif