#include <igl/readOFF.h>
#include <igl/writeOBJ.h>
#include <iostream>

Eigen::MatrixXd V;
Eigen::MatrixXi F;

int main(int argc, char* argv[])
{
	// Load a mesh in OFF format
	igl::readOFF("../data/cube.off", V, F);

	// Print the vertices and faces matrices
	std::cout << "Vertices: " << std::endl << V << std::endl;
	std::cout << "Faces:    " << std::endl << F << std::endl;

	// Save the mesh in OBJ format
	igl::writeOBJ("101_FileIO_cube.obj", V, F);
}