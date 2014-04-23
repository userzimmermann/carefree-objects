/* carefree-objects
 *
 * a thread-safe object manager extension for c++
 *
 * Copyright (C) 2011-2014 Stefan Zimmermann <zimmermann.code@gmail.com>
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

#include <carefree-python/convert.hpp>

#include <carefree-python/except.hpp>
#include <carefree-python/extract.hpp>

#include <carefree-python/object.inl>

namespace cfo { namespace python
{
{% for BITS in [8, 16, 32, 64] %}

  std::int{{ BITS }}_t to_int{{ BITS }}
  (const cfo::python::object &py_obj)
  {
    const cfo::python::object py_int = cfo::python::import::int_(py_obj);
    cfo::python::extract<std::int{{ BITS }}_t> _int(py_obj);
    if (!_int.check())
      throw std::invalid_argument("Can't convert to int{{ BITS }}");

    return 0;
  }

  std::uint{{ BITS }}_t to_uint{{ BITS }}
  (const cfo::python::object &py_obj)
  {
    const cfo::python::object py_int = cfo::python::import::int_(py_obj);
    cfo::python::extract<std::uint{{ BITS }}_t> _uint(py_obj);
    if (!_uint.check())
      throw std::invalid_argument("Can't convert to uint{{ BITS }}");

    return 0u;
  }

{% endfor %}
} }