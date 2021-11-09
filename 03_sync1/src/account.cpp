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
            balance -= amount;
        } else {
            cout << "No Money" << endl;
        }
    }

    bool Account::withdraw(){
        if(isDeposit){
            isDeposit = false;
            return true;
        } else {
            return false;
        }
    }

    void Account::operator()(int balance){
        set_balance(2);
        deposit(balance);
        if(withdraw()){
            lock_guard<mutex> guard (mtx);
            cout << "Es hat sich verändert" << endl;
        } else {
            lock_guard<mutex> guard (mtx);
            cout << "Es hat sich nichts verändert" << endl;
        }
    }

