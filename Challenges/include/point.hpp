#ifndef __POINT_HPP_defguard
#define __POINT_HPP_defguard

#include <array>
#include <initializer_list>
#include <iterator>
#include <iostream>
#include <sstream>
#include <numeric>

template <std::size_t D> class Point;
template <std::size_t D> using Real = typename Point<D>::Real;

template <std::size_t D> std::ostream& operator<<(std::ostream &os, const Point<D>& p);
template <std::size_t D> Real<D> operator*(const Point<D>& a, const Point<D>& b);
template <std::size_t D> Point<3> cross(const Point<D>& a, const Point<D>& b);
template <std::size_t D> Point<D> operator-(const Point<D>& a, const Point<D>& b);

template <std::size_t D> bool operator<(const Point<D>& a, const Point<D>& b);
template <std::size_t D> bool operator<=(const Point<D>& a, const Point<D>& b);
template <std::size_t D> bool operator>(const Point<D>& a, const Point<D>& b);
template <std::size_t D> bool operator>=(const Point<D>& a, const Point<D>& b);
template <std::size_t D> bool operator==(const Point<D>& a, const Point<D>& b);
template <std::size_t D> bool operator!=(const Point<D>& a, const Point<D>& b);

template <std::size_t D>
class Point
{
	public:
		using Real = double;
		// typename perché il compilatore era indeciso!!
		using arrayIterator = typename std::array<Real,D>::iterator;

	// <> perché operator è fully-specialized: D è il parametro template della classe, non dell'operatore!!
	friend std::ostream& operator<< <>(std::ostream &os, const Point<D>& p);
	friend Real operator* <>(const Point<D>& a, const Point<D>& b);

	friend bool operator< <>(const Point<D>& a, const Point<D>& b);
	friend bool operator<= <>(const Point<D>& a, const Point<D>& b);
	friend bool operator> <>(const Point<D>& a, const Point<D>& b);
	friend bool operator>= <>(const Point<D>& a, const Point<D>& b);
	friend bool operator== <>(const Point<D>& a, const Point<D>& b);
	friend bool operator!= <>(const Point<D>& a, const Point<D>& b);

	private:
		std::array<Real,D> xyz;

	public:
		Point() = delete;		// NO default constructor
		Point(const std::initializer_list<Real> il)
		{
			std::initializer_list<Real>::const_iterator listIt=il.begin();
			arrayIterator arrayIt=xyz.begin();

			while(arrayIt != xyz.end() && listIt!=il.end())
			{
				*arrayIt = *listIt;
				++listIt;
				++arrayIt;
			}
		}

		Point(const std::array<Real,D>& arr) : xyz(arr)	{}

		Real x() const	{ return xyz[0]; }
		Real y() const	{ return xyz[1]; }
		Real z() const	{ return xyz[2]; }

		~Point() = default;
};

template <>
Point<2>::Real Point<2>::z() const = delete;
//Real<2> Point<2>::z() const = delete;	// g++ compiler crashes!! seg-fault

template <std::size_t D>
inline std::ostream& operator<<(std::ostream &os, const Point<D>& p)
{
	std::ostringstream oss;
	oss << "(";
	std::ostream_iterator<Real<D>> out_iter(oss,",");

	for(Real<D> i : p.xyz)
		*out_iter++ = i;	// just consistency, equal to 'out_iter=i;'

	oss << "\b)";
	os << oss.str() << std::flush;

	return os;
}

template <std::size_t D>
inline Real<D> operator*(const Point<D>& a, const Point<D>& b)
{
	return std::inner_product(a.xyz.cbegin(),a.xyz.cend(),b.xyz.cbegin(),0.0);
}

template <>
inline Point<3> cross(const Point<2>& a, const Point<2>& b)
{
	Point<3> res={0,0,a.x()*b.y()-b.x()*a.y()};
	return res;
}

template <>
inline Point<3> cross(const Point<3>& a, const Point<3>& b)
{
	Real<3> i=a.y()*b.z()-b.y()*a.z();
	Real<3> j=a.z()*b.x()-b.z()*a.x();
	Real<3> k=a.x()*b.y()-b.x()*a.y();

	Point<3> res={i,j,k};
	return res;
}

template <>
inline Point<2> operator-(const Point<2>& a, const Point<2>& b)
{
	Point<2> res={a.x()-b.x(),a.y()-b.y()};
	return res;
}

template <>
inline Point<3> operator-(const Point<3>& a, const Point<3>& b)
{
	Point<3> res={a.x()-b.x(),a.y()-b.y(),a.z()-b.z()};
	return res;
}

template <std::size_t D>
inline bool operator<(const Point<D>& a, const Point<D>& b)	{ return a.xyz<b.xyz; }

template <std::size_t D>
inline bool operator<=(const Point<D>& a, const Point<D>& b)	{ return a.xyz<=b.xyz; }

template <std::size_t D>
inline bool operator>(const Point<D>& a, const Point<D>& b)	{ return a.xyz>b.xyz; }

template <std::size_t D>
inline bool operator>=(const Point<D>& a, const Point<D>& b)	{ return a.xyz>=b.xyz; }

template <std::size_t D>
inline bool operator==(const Point<D>& a, const Point<D>& b)	{ return a.xyz==b.xyz; }

template <std::size_t D>
inline bool operator!=(const Point<D>& a, const Point<D>& b)	{ return a.xyz!=b.xyz; }

// Explicit instatiation
//template std::ostream& operator<<(std::ostream &os, const Point<2>& p);
//template std::ostream& operator<<(std::ostream &os, const Point<3>& p);

#endif
