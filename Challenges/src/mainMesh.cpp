#include <iostream>
#include "point.hpp"
#include "triangle.hpp"
#include "mesh.hpp"

int main()
{
	Point<2> A={0,1};
	Point<2> B={1,0};
	Point<2> C={0,0};
	Point<2> D={1,1};
	Triangle<2> T1(A,B,C);
	Triangle<2> T2(A,B,D);

	Mesh<Triangle<2>> M={T1,T2};

//	Point<3> A={0,1,15};
//	Point<3> B={1,0,16};
//	Point<3> C={0,0,14};
//	Triangle<3> T(A,B,C);

	std::cout << T1 << std::endl;
	std::cout << T2 << std::endl;
	std::cout << M << std::endl;

	return 0;
}
