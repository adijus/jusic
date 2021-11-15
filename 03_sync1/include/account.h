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
        bool withdraw(int data);
        Account(int balance);
};


class Depositer{
        int credit;
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