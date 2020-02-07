#ifndef MEANVALUECOORDINATES_H
#define MEANVALUECOORDINATES_H

#include <map>
#include <barycentriccoordinates.h>


class MeanValueCoordinates : public BarycentricCoordinates
{
public:

    /**
     * @brief MeanValueCoordinates Main constructor of the class. It requires the
     * model which will be deformed and the cage used for that purpose.
     * @param meshVertices nx3 matrix of mesh vertices' positions.
     * @param cageVertices mx3 matrix of cage vertices' positions.
     */
    MeanValueCoordinates(Eigen::MatrixX3d* meshVertices, Eigen::MatrixX3d* cageVertices);

    ~MeanValueCoordinates();

    /**
     * @brief MeanValueCoordinates::computeCoordinates Method that manages the computation of the coordinates
     */
    void computeCoordinates();

    /**
     * @brief MeanValueCoordinates::saveCoordinates Method that manages the storage of the computed coordinates
     * @param filename the name of the file in which the coordinates will be saved
     */
    void saveCoordinates(std::string filename);

    /**
     * @brief MeanValueCoordinates::loadCoordinates Method that manages the loading of the coordinates
     * @param filename the name of the file from which the coordinates are loaded
     */
    void loadCoordinates(std::string filename);

    /**
     * @brief MeanValueCoordinates::deform Method that manages the deformation of the model.
     */
    void deform();

    /**
     * @brief MeanValueCoordinates::getCoordinates Method that allow the gathering of the coordinates
     * @return the coordinates set
     */
    Eigen::MatrixXd* getCoordinates();
};

#endif // MEANVALUECOORDINATES_H
