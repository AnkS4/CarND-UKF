#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

	VectorXd rmse(4);
    rmse << 0,0,0,0;

    // Check for the following:
    //  The estimation vector size should equal ground truth vector size.
    //  The estimation vector size should not be zero.
    //  The ground truth vector size should not be equal to zero.
    // If one of the above statement is True return default rmse(set with 0, 0, 0, 0).
    if(estimations.size() != ground_truth.size() || estimations.size() == 0 || ground_truth.size() == 0){
        std::cout << "Invalid Estimation/Estimation Vector Size/Ground Truth Vector Size" << std::endl;
        return rmse;
    }

    for(unsigned int i=0; i < estimations.size(); ++i){
        VectorXd residual = estimations[i] - ground_truth[i];
        residual = residual.array()*residual.array();
        rmse += residual;
    }

    //calculate the mean
    rmse = rmse/estimations.size();

    //calculate the squared root
    rmse = rmse.array().sqrt();

    //return the result
    return rmse;
}