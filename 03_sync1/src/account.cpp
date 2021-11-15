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

    bool Account::withdraw(int data){
        deposit(data);
        if(isDeposit){
            isDeposit = false;
            cout << "hat sich was verändert" << endl;
            return true;
        } else {
            cout << "hat sich nichts verändert" << endl;
            return false;
        }
    }

    Account::Account(int balance){
        set_balance(balance);
        isDeposit = false;
    }


    int Depositer::getCredit(){
        return credit;
    }


    void Depositer::setCredit(int c){
        this->credit = c;
    }


    void Depositer::deposit(int amount){
        if(credit >= amount){
            this_thread::yield();
            isDeposit = true;
            int tmp{credit};
            std::this_thread::sleep_for(10ms);
            credit = tmp + amount;
        } else {
            cout << "No Money" << endl;
        }
    }


