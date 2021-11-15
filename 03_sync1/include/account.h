#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <thread>

void hello();



class Account{
    public:
        int balance;
        bool isDeposit;
        int get_balance();
        void set_balance(int b);
        void deposit(int amount);
        void withdraw(int data);
        Account(){this->balance = 10; this->isDeposit = false;};
};


class Depositer{
        int balance;
        bool isDeposit;
    public:
        int getCredit();
        void setCredit(int c);
        void deposit(int amount);
        void operator()(int c){
            deposit(c);
            for(int i = 0; i < 5; i++){
            
            }
        }
};


#endif