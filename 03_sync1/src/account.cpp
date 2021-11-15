#include <iostream>
#include <thread>
#include <mutex>
#include "account.h"

using namespace std;

    mutex mtx;

    int Account::get_balance(){
        return this->balance;
    }

    void Account::set_balance(int b){
        this->balance = b;
    }

    void Account::deposit(int amount){
        if(balance >= amount){
            this_thread::yield();
            isDeposit = true;
            this->balance += amount;
        } else {
            cout << "No Money" << endl;
        }
    }

    void Account::withdraw(int data){
        deposit(data);
        if(isDeposit){
            isDeposit = false;
            cout << get_balance() << endl;
        } else {
            cout << "hat sich nichts verändert" << endl;
        }
    }


    int Depositer::getCredit(){
        return balance;
    }


    void Depositer::setCredit(int c){
        this->balance = c;
    }


    void Depositer::deposit(int amount){
        if(balance >= amount){
            this_thread::yield();
            isDeposit = true;
            int tmp{balance};
            std::this_thread::sleep_for(10ms);
            balance = tmp + amount;
        } else {
            cout << "No Money" << endl;
        }
    }


