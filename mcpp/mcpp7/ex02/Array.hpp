/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:51:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 17:11:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cctype>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_element;

	public:
		Array(): _size(0), _element(new T[0])
		{}
		Array(unsigned int n): _size(n), _element(new T[n])
		{}

		Array(const Array &other): _size(other._size), _element(NULL)
		{ this->operator=(other); }
		
		virtual ~Array()
		{ delete[] this->_element; }

		Array& operator=(const Array &other)
		{
			if (this != &other)
			{
				if (this->_element)
					delete[] this->_element;
				this->_size = other._size;
				this->_element = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_element[i] = other._element[i];
			}
			return (*this);
		}

		unsigned int size() const
		{
			return (this->_size);
		}

		T& operator[](unsigned int idx)
		{
			if (idx < 0 || idx >= this->_size)
				throw OutOfBoundsIndexException();
			else
				return (this->_element[idx]);
		}


		class OutOfBoundsIndexException: public std::exception {
		virtual const char* what() const throw() 
			{ return ("Error : index out of bounds");}
		};
};

#endif