#ifndef SHAPEOPBARYCENTRICCOORDINATES_H
#define SHAPEOPBARYCENTRICCOORDINATES_H

#include <Eigen/Dense>

class BarycentricCoordinates
{
public:
    virtual void computeCoordinates() = 0;
    virtual void deform() = 0;
    virtual void saveCoordinates(std::string filename) = 0;
    virtual void loadCoordinates(std::string filename) = 0;

    Eigen::MatrixX3d *getMesh() const { return mesh; }
    void setMesh(Eigen::MatrixX3d *value){ mesh = value; }

    Eigen::MatrixX3d *getCage() const{ return cage; }
    void setCage(Eigen::MatrixX3d *value){ cage = value; }

    Eigen::MatrixXd *getCoords() const{ return coords; }
    void setCoords(Eigen::MatrixXd *value){ coords = value; }

protected:
    Eigen::MatrixX3d* mesh;
    Eigen::MatrixX3d* cage;
    Eigen::MatrixXd* coords;
};

#endif // BARYCENTRICCOORDINATES_H
