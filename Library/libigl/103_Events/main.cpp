#include <igl/readOFF.h>
#include <igl/readOBJ.h>
#include <igl/opengl/glfw/Viewer.h>
#include <iostream>

Eigen::MatrixXd V0, V1, V2;
Eigen::MatrixXi F0, F1, F2;

// This function is called every time a keyboard button is pressed
bool key_down(igl::opengl::glfw::Viewer& viewer, unsigned char key, int modifier)
{
    std::cout << "Key: " << key << " " << (unsigned int)key << std::endl;
    if (key == '1')
    {
        // Clear should be called before drawing the mesh, same logic applied later
        viewer.data().clear();

        // Draw_mesh creates or !updates! the vertices and faces of the displayed mesh.
        // If you wanna update the vertices and faces, the shape of before and after must be aligned.
        viewer.data().set_mesh(V1, F1);
        viewer.core().align_camera_center(V1, F1);
    }
    else if (key == '2')
    {
        viewer.data().clear();
        viewer.data().set_mesh(V2, F2);
        viewer.core().align_camera_center(V2, F2);
    }

    return false;
}


int main(int argc, char* argv[])
{
    // Load two meshes
    igl::readOBJ("../data/sphere.obj", V0, F0);
    igl::readOFF("../data/bunny.off", V1, F1);
    igl::readOFF("../data/lion.off", V2, F2);
    std::cout << R"(
Which animal you like the best?
Press 1 for select bunny
Press 2 for select lion
    )";

    igl::opengl::glfw::Viewer viewer;

    // Register a keyboard callback that allows to switch between
    // the two loaded meshes
    viewer.callback_key_down = &key_down;

    //Init mesh is a sphere.
    viewer.data().set_mesh(V0, F0);
    viewer.launch();
}