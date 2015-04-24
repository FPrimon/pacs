#ifndef __MESH_HPP_defguard
#define __MESH_HPP_defguard

#include <vector>
#include <initializer_list>
#include <iostream>

template <typename T> class Mesh;
template <typename T> std::ostream& operator<<(std::ostream &os, const Mesh<T>& m);

template <typename T>
class Mesh
{
	friend std::ostream& operator<< <>(std::ostream &os, const Mesh<T>& m);

	private:
		std::vector<T> msh;

	public:
		Mesh() = default;
		Mesh(std::initializer_list<T> il) : msh(il)	{}

		~Mesh() = default;
};

template <typename T>
inline std::ostream& operator<<(std::ostream &os, const Mesh<T>& m)
{
	for(T i : m.msh)
		os << i << std::endl;
	return os;
}

#endif
