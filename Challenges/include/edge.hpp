#ifndef __EDGE_HPP_defguard
#define __EDGE_HPP_defguard

#include <array>
#include <algorithm>
#include <iostream>
#include <sstream>

#include "point.hpp"

template <std::size_t D> class Edge;
template <std::size_t D> std::ostream& operator<<(std::ostream &os, const Edge<D>& e);

template <std::size_t D>
class Edge
{
	friend std::ostream& operator<< <>(std::ostream &os, const Edge<D>& e);

	private:
		std::array<Point<D>,2> AB;

	public:
		Edge() = delete;		// NO default constructor
		Edge(const Point<D>& a, const Point<D>& b) : AB{a,b}
		{
			std::sort(AB.begin(),AB.end());
		}

		Point<D> A() const	{ return AB[0]; }
		Point<D> B() const	{ return AB[1]; }

		~Edge() = default;
};

template <std::size_t D>
inline std::ostream& operator<<(std::ostream &os, const Edge<D>& e)
{
	std::ostringstream oss;

	for(Point<D> i : e.AB)
		oss << i << " ";

	oss << "\b";
	os << oss.str() << std::flush;

	return os;
}

#endif
