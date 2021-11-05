#ifndef ACCOUNT_H
#define ACCOUNT_H

void hello();

class Account{
    public:
        int balance;
        bool isDeposit = false;

        int get_balance();
        void set_balance(int b);
        void deposit(int amount);
        bool withdraw();
        void operator()(int balance);
};



#endif