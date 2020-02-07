#include <meanvaluecoordinates.h>
#include <fstream>

using namespace std;

MeanValueCoordinates::MeanValueCoordinates(Eigen::MatrixX3d *meshVertices, Eigen::MatrixX3d *cageVertices)
{
    this->mesh = meshVertices;
    this->cage = cageVertices;
    this->coords = new Eigen::MatrixXd();
    this->coords->resize(mesh->rows(), cage->rows());
}

MeanValueCoordinates::~MeanValueCoordinates()
{
    mesh = nullptr;
    cage = nullptr;
    delete coords;
}

void MeanValueCoordinates::computeCoordinates(){

    //To complete. It needs connectivity

}

void MeanValueCoordinates::saveCoordinates(std::string filename){

    ofstream savefile;
    savefile.open(filename);
    savefile<<"Mean Value Coordinates"<<endl<<flush;
    savefile<<mesh->rows() <<" "<<cage->rows()<<endl<<flush;
    for(long i = 0; i < coords->rows(); i++){

        for(long j = 0; j < coords->cols(); j++)
            savefile<<(*coords)(i,j)<<" ";

        savefile<<std::endl<<flush;
    }
    savefile.close();

}

void MeanValueCoordinates::loadCoordinates(std::string filename){

    ifstream loadfile;
    loadfile.open(filename);
    std::string line;
    std::getline(loadfile, line);
    std::getline(loadfile, line);
    istringstream* iss = new istringstream(line);
    unsigned int meshVerticesNumber;
    (*iss) >> meshVerticesNumber;
    for(unsigned int i = 0; i < meshVerticesNumber; i++){
        int j = 0;
        std::getline(loadfile, line);
        iss = new istringstream(line);
        double coord;
        while((*iss) >> coord)
            (*coords)(i, j++)=coord;
    }
    loadfile.close();

}


void MeanValueCoordinates::deform(){

    (*mesh) = (*coords) * (*cage);

}

Eigen::MatrixXd* MeanValueCoordinates::getCoordinates(){
    return this->coords;
}
