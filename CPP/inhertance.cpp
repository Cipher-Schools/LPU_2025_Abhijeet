#include <iostream>
using namespace std;


class BankAccount {
private:
    string name;
    float amount;

public:
    BankAccount(string name, float amount) {
        this->name = name;
        this->amount = amount;
    }

    string get_name() {
        return this->name;
    }

    float get_amount() {
        return this->amount;
    }


    void set_name(string name) {
        this->name = name;
    }

    void set_amount(float amount) {
        this->amount = amount;
    }


    void deposit(float x) {
        this->amount += x;
        cout << x << " deposited successfully. New balance: " << this->amount << endl;
    }

    void withdraw(float x) {
        if (x > this->amount) {
            cout << " Insufficient balance!" << endl;
            return;
        }
        this->amount -= x;
        cout << x << " withdrawn successfully. Remaining balance: " << this->amount << endl;
    }

    // function Overloading ,  compile time polymorphisum

    void withdraw(float x , float tax){
        float total = x + tax ;
        if(total > this->amount){
            cout << " Insufficient balance!" << endl;
            return;
        }

          this->amount -= total;
        cout << total << " withdrawn successfully. Remaining balance: " << this->amount << endl;
    }


      void display() {
        cout << "Account Holder: " << name << " | Balance: " << amount << endl;
    }
};


class SavingsAccount : public BankAccount {
private:
    float interestRate; // %

public:
    SavingsAccount(string name, float amount, float rate)
        : BankAccount(name, amount) {
        this->interestRate = rate;
    }

    void addInterest() {
        float interest = (get_amount() * interestRate) / 100;
        set_amount(get_amount() + interest);
        cout << " Interest of " << interest << " added. New balance: " << get_amount() << endl;
    }


};


class CurrentAccount : public BankAccount {
private:
    float transactionFee = 20.0;

public:
    CurrentAccount(string name, float amount)
        : BankAccount(name, amount) {}

    // function overriding
    // run time polymorphisum
    void withdraw(float x) {
        cout<<"withdraw of the child class current Account";
        float total = x + transactionFee;
        if (total > get_amount()) {
            cout << "Insufficient balance (including fee)!" << endl;
            return;
        }
        set_amount(get_amount() - total);
        cout << "Withdrawn: " << x << " + Fee: " << transactionFee
             << " | Remaining: " << get_amount() << endl;
    }


};


int main() {


    BankAccount base("A", 5000);
    base.deposit(1000);
    base.withdraw(2000);
    base.withdraw(500 , 20);
    base.display() ;

    SavingsAccount a1("B" , 5000 , 8) ;
    CurrentAccount b1("C" , 5000) ;

    // common behvoir using function from base class
    a1.deposit(1000) ;
    b1.deposit(2000) ;


    a1.display();
    b1.display();

    b1.withdraw(500) ;






    return 0;
}
