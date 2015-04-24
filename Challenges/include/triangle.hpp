#ifndef __TRIANGLE_HPP_defguard
#define __TRIANGLE_HPP_defguard

#include <array>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>

#include "point.hpp"
#include "edge.hpp"

template <std::size_t D> class Triangle;
template <std::size_t D> std::ostream& operator<<(std::ostream &os, const Triangle<D>& t);

template <std::size_t D>
class Triangle
{
	friend std::ostream& operator<< <>(std::ostream &os, const Triangle<D>& t);

	private:
		std::array<Point<D>,3> ABC;
		std::array<Edge<D>,3> abc;

	public:
		Triangle() = delete;		// NO default constructor
		Triangle(const Point<D>& a, const Point<D>& b, const Point<D>& c) : ABC{a,b,c}, abc{AB(),BC(),AC()}
		{
			orient();
		}

		Point<D> A() const	{ return ABC[0]; }
		Point<D> B() const	{ return ABC[1]; }
		Point<D> C() const	{ return ABC[2]; }

		Edge<D> AB() const
		{
			Edge<D> edge={A(),B()};
			return edge;
		}

		Edge<D> BC() const
		{
			Edge<D> edge={B(),C()};
			return edge;
		}

		Edge<D> AC() const
		{
			Edge<D> edge={A(),C()};
			return edge;
		}

		std::array<Edge<D>,3> edges() const	{ return abc; }

		void orient()
		{
			std::sort(ABC.begin(),ABC.end());

			Point<3> k={0,0,1};
			if( cross(B()-A(),C()-B())*k < 0 )
				std::swap(ABC[1],ABC[2]);
		}

		~Triangle() = default;
};

template <std::size_t D>
inline std::ostream& operator<<(std::ostream &os, const Triangle<D>& t)
{
	std::ostringstream oss;

	for(Point<D> i : t.ABC)
		oss << i << " ";

	oss << "\b";
	os << oss.str() << std::flush;

	return os;
}

#endif
