#ifndef SIMPLE_MODEL_TRANSACTION_H
#define SIMPLE_MODEL_TRANSACTION_H

class transaction {
private:
    //variable
    double *Account;    //money of agents
    double *hist;       // value counter for transacted money
    double r;           //transaction random number
    double beta;        //beta value of distribution
    int agent_1;        //Agent for timestep_simple
    int agent_2;        //Agent for timestep_simple

    //functions
    void timestep_simple(int Agent_1, int Agent_2, double R);        //single transaction
    void timestep_equilibrim(int Agent_1, int Agent_2, double R);    //single transaction

public:
    //variables
    int N;              //number of agents
    int M;              //length of hist array
    double dm;          //step length of transaction money histogram

    //functions
    transaction(int N_agents, double init_money);
    void run_simple(double timesteps);
    void run_equilibrium(double timesteps);
    void copy_hist(double *target);
    void add_hist(double *target);
    void copy_account(double *target);
    ~transaction();
};

#endif //SIMPLE_MODEL_TRANSACTION_H
