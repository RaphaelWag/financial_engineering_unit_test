#include <iostream>
#include <cmath>
#include "transaction.h"

using namespace std;

int main() {
    double equilibrium_steps=50000;
    double timesteps = 1*pow(10,4);
    int N_Agents=500;
    double m_0=1;
    int N_runs=100;

    //construct model
    transaction model(N_Agents,m_0);

    //set up arrays
    auto **histograms = new double *[N_runs];
    for (int i = 0; i < N_runs; ++i) {
        histograms[i] = new double[model.M];
    }

    auto final_histogram = new double[model.M];
    for (int l = 0; l < model.M; ++l) {
        final_histogram[l] =0;
    }

    //run simulations
    for (int j = 0; j < N_runs; ++j) {

        model.run_equilibrium(equilibrium_steps);
        model.run_simple(timesteps);
        model.add_hist(final_histogram);
    }

    //normalize histogram
    double S =0;
    for (int m = 0; m < model.M; ++m) {
        S+=final_histogram[m];
    }
    S=S*model.dm;
    for (int n = 0; n < model.M; ++n) {
        final_histogram[n]=final_histogram[n]/S;
    }

    S=0;
    //sum up histogram and check if it is normalized
    for (int k = 0; k < model.M; ++k) {
        S+=final_histogram[k]*model.dm;
    }

    cout << S << endl;

    return 0;
}
