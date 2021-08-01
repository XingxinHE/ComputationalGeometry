#include <igl/readOFF.h>
#include <igl/writeOBJ.h>
#include <iostream>
#include <string>

Eigen::MatrixXd V;
Eigen::MatrixXi F;

int main(int argc, char* argv[])
{
	std::string path = "/path/to/directory";
	std::cout << "Welcome to libigl 101!" << std::endl;
	std::cout << "Please type anything and press enter to continue...\n" << std::endl;
	std::string input = "";
	std::cin >> input;
	// Load a mesh in OFF format
	igl::readOFF("../data/cube.off", V, F);

	std::cout << "Mesh was read succeeded." << std::endl;

	// Print the vertices and faces matrices
	std::cout << "Vertices: " << std::endl << V << std::endl;
	std::cout << "Faces:    " << std::endl << F << std::endl;

	// Save the mesh in OBJ format
	igl::writeOBJ("101_FileIO_cube.obj", V, F);
	std::cout << "\nPlease type anything and press enter to continue..." << std::endl;
	std::cin >> input;
}