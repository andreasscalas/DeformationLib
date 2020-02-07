#include <iostream>
#include <Eigen/Dense>
#include <meanvaluecoordinates.h>

using namespace std;

int main(int argc, char *argv[])
{

    Eigen::MatrixX3d mesh;
    Eigen::MatrixX3d cage;
    mesh.resize(6,3);
    cage.resize(8,3);
    mesh << 0, 0, -1,
            0, 0, 1,
            0, -1, 0,
            0, 1, 0,
            -1, 0, 0,
            1, 0, 0;
    cage << 2, 2, 2,
            2, 2, -2,
            2, -2, 2,
            2, -2, -2,
            -2, 2, 2,
            -2, 2, -2,
            -2, -2, 2,
            -2, -2, -2;
    MeanValueCoordinates coords(&mesh, &cage);
    coords.loadCoordinates("prism_cube.coord");
    Eigen::Vector3d newPos = {2, 4, 12};
    cage.row(0) = newPos;
    coords.deform();

    cout << mesh  << endl << flush;

}
