/* carefree-objects
 *
 * a thread-safe object manager extension for c++
 *
 * Copyright (C) 2011-2016 Stefan Zimmermann <zimmermann.code@gmail.com>
 *
 * carefree-objects is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * carefree-objects is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with carefree-objects.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CAREFREE_TYPES_BITS_HPP
#define __CAREFREE_TYPES_BITS_HPP

#include "./common.hpp"

namespace cfo
{
  namespace _bits
  {
    typedef std::vector<bool> super_vector;
  }
  /**
   * A bit field of dynamic size.
   */
  class bits : public _bits::super_vector
  {
  private:
    // inline void _bits()
    // {}

    // template<typename... N>
    // inline void _bits(const std::size_t num, const N &...numbers)
    // {
    //   if (num >= this->size())
    //     this->resize(num + 1, false);

    //   (*this)[num] = true;

    //   this->_bits(numbers...);
    // }

  public: //---------------------------------------------------------------
    //--> bits.cpp                                             Constructors

    inline
    bits()
    {}

    bits
    (const std::string &bitstring, const std::size_t nbits = 0u,
     const bool fill = false);

    // template<typename... N>
    // inline bits(const N &...numbers)
    // {
    //   this->_bits(numbers...);
    // }

{% for INT in [INT_TYPES, UINT_TYPES]|chain %}
    bits
    (const {{ INT }} bits, std::size_t nbits = 0u,
     const bool fill = false);
{% endfor %}

  public: //---------------------------------------------------------------
    //--> ./bits.inl                                             Bit access

    inline
    bool operator[](const std::size_t bit)
      const;

    inline
    _bits::super_vector::reference operator[](const std::size_t bit);
  };
}

#include "./bits.inl"

#endif
