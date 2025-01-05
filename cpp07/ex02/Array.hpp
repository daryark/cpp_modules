/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:20:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 06:54:29 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> class Array
{
    private:
        unsigned int    _size;
        T*              _arr;
    public:
        Array(): _size(0), _arr(NULL) {} //creates empty arr
        Array(unsigned int n): _size(n), _arr(new T[n]) {} //creates arr of n elems
        ~Array() { delete[] _arr; }

        Array(const Array& other): _size(other.size()), _arr(new T[other.size()])
        {
            for (unsigned int i = 0; i < _size; i++)
                _arr[i] = other._arr[i];
        }
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _arr;
                _size = other._size;
                _arr = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _arr[i] = other._arr[i];
            }
            return *this;
        }
        T&  operator[](unsigned int i)  const
        {
            if (i >= _size)
                throw std::exception();
            return _arr[i];
        }

        unsigned int    size() const { return _size; }
};

//*template can be either written and only used in one .cpp file
//*or declared and written fully in .hpp file so the linker would be able to use it entirely everywhere
//*one more option - to write realization separated in .tpp file

// template <typename T>
// class Array
// {
// private:
//     unsigned int _size;
//     T* _arr;

// public:
//     // Default constructor
//     Array() : _size(0), _arr(NULL) {}

//     // Parameterized constructor
//     Array(unsigned int n) : _size(n), _arr(new T[n]) {}

//     // Destructor
//     ~Array() { delete[] _arr; }

//     // Copy constructor - deep copy
//     Array(const Array& other) : _size(other._size), _arr(new T[other._size])
//     {
//         std::cout << "copy\n";
//         for (unsigned int i = 0; i < _size; i++)
//         {
//             _arr[i] = other._arr[i]; // Deep copy elements
//         }
//     }

//     // Assignment operator
//     Array& operator=(const Array& other)
//     {
//         if (this != &other) // Self-assignment check
//         {
//             std::cout << "operator=\n";
//             delete[] _arr; // Deallocate existing array
//             _size = other._size;
//             _arr = new T[_size]; // Allocate new memory for the copy
//             for (unsigned int i = 0; i < _size; i++)
//             {
//                 _arr[i] = other._arr[i]; // Copy elements from other array
//             }
//         }
//         return *this;
//     }

//     // Subscript operator
//     T& operator[](unsigned int i) const
//     {
//         if (i >= _size)
//             throw std::exception(); // Out-of-bounds check
//         return _arr[i];
//     }

//     // Size function
//     unsigned int size() const { return _size; }
// };
