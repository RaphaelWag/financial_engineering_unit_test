#include "transaction.h"
#include <cmath>
#include <random>

using namespace std;

transaction::~transaction()
{
    delete [] Account;
    delete [] hist;
}

transaction::transaction(int N_agents, double init_money)
{
    //construct arrays
    N = N_agents;
    Account = new double[N];
    for (int i = 0; i < N; ++i) {
        Account[i] = init_money;
    }

    //set beta
    beta = 1./init_money;

    //construct transaction counter
    dm = 0.01;
    M = static_cast<int>(N * init_money / dm);
    hist = new double[M]; //check this if bugs occur
    for (int j = 0; j < M; ++j) {
        hist[j]=0;
    }
}

void transaction::timestep_equilibrim(int Agent_1, int Agent_2, double R) {
    //pre save money values
    double m;

    m = Account[Agent_1] + Account[Agent_2];

    //transact money
    Account[Agent_1] = R*m;
    Account[Agent_2] = m-Account[Agent_1]; //same formula as in project description just simplified

    //dont save data in histogram
}

void transaction::timestep_simple(int Agent_1, int Agent_2, double R)
{
    //pre save money values
    double m;

    m = Account[Agent_1] + Account[Agent_2];

    //transact money
    Account[Agent_1] = R*m;
    Account[Agent_2] = m-Account[Agent_1]; //same formula as in project description just simplified

    //save transacted money in histogram

    hist[int(Account[Agent_1]/dm)]++;
    hist[int(Account[Agent_2]/dm)]++;
}

void transaction::run_equilibrium(double timesteps) {
    //seed rng
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> random_Agent(0, N-1);
    uniform_real_distribution<double> random_transact(0,1);

    //loop over timesteps
    for (double i = 0; i < timesteps; ++i) {
        //draw random agents
        agent_1 = random_Agent(gen);
        agent_2 = random_Agent(gen);

        //draw transaction random number
        r = random_transact(gen);

        //do timestep
        timestep_equilibrim(agent_1, agent_2, r);
    }
}

void transaction::run_simple(double timesteps) {
    //seed rng
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random_Agent(0, N-1);
    uniform_real_distribution<> random_transact(0,1);

    //loop over timesteps
    for (double i = 0; i < timesteps; ++i) {
        //draw random agents
        agent_1 = random_Agent(gen);
        agent_2 = random_Agent(gen);

        //draw transaction random number
        r = random_transact(gen);

        //do timestep
        timestep_simple(agent_1, agent_2, r);
    }
}

void transaction::copy_hist(double *target) {
    for (int i = 0; i < M; ++i) {
        target[i]=hist[i];
    }
}

void transaction::copy_account(double *target) {
    for (int i = 0; i < N; ++i) {
        target[i]=Account[i];
    }
}

void transaction::add_hist(double *target) {
    for (int i = 0; i < M; ++i) {
        target[i]+=hist[i];
    }
}
