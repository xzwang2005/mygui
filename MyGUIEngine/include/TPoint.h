/*!
	@file
	@author		Albert Semenov
	@date		11/2007
	@module
*/
#ifndef __TPONT_H__
#define __TPONT_H__

#include <string>
#include <sstream>

namespace types
{
	template< typename T > struct TPoint
	{
		T left, top;

		TPoint() : left( 0 ), top( 0 ) { }
		TPoint( T const & l, T const & t) : left( l ), top( t ) { }
		TPoint( TPoint const & o ) : left( o.left ), top( o.top ) { }
		explicit TPoint(const std::string& _value) {*this = parse(_value);}

		TPoint & operator-=( TPoint const & o )
		{
			left -= o.left;
			top -= o.top;
			return *this;
		}

		TPoint & operator+=( TPoint const & o )
		{
			left += o.left;
			top += o.top;
			return *this;
		}

		TPoint operator-( TPoint const & o ) const
		{
			return TPoint(left - o.left, top - o.top);
		}

		TPoint operator+( TPoint const & o ) const
		{
			return TPoint(left + o.left, top + o.top);
		}

		TPoint & operator=( TPoint const & o )
		{
			left = o.left;
			top = o.top;
			return *this;
		}

		template< typename U >
		TPoint & operator=( TPoint<U> const & o )
		{
			left = o.left;
			top = o.top;
			return *this;
		}

		bool operator==( TPoint const & o ) const
		{
			return ((left == o.left) && (top == o.top));
		}

		bool operator!=( TPoint const & o ) const
		{
			return ! ((left == o.left) && (top == o.top));
		}

		void clear()
		{
			left = top = 0;
		}

		void set( T const & l, T const & t)
		{
			left = l;
			top = t;
		}

		void swap(TPoint& _value)
		{
			TPoint tmp = _value;
			_value = *this;
			*this = tmp;
		}

		bool empty() const
		{
			return ((left == 0) && (top == 0));
		}

		std::string print() const
		{
	        std::ostringstream stream;
	        stream << *this;
		    return stream.str();
		}

		static TPoint<T> parse(const std::string& _value)
		{
			TPoint<T> ret;
	        std::istringstream stream(_value);
	        stream >> ret;
		    return ret;
		}

        friend std::ostream& operator << ( std::ostream& _stream, const TPoint<T>&  _value )
        {
            _stream << _value.left << " " << _value.top;
            return _stream;
        }

        friend std::istream& operator >> ( std::istream& _stream, TPoint<T>&  _value )
        {
            _stream >> _value.left >> _value.top;
			if (_stream.fail()) _value.clear();
            return _stream;
        }

	};

} // namespace types

#endif // __TPONT_H__
