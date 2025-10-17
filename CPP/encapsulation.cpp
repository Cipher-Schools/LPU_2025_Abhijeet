
// Online Free C++ compiler to run C++ program online
#include <iostream>
using namespace std ;
// Implementing encapsulation
// make all data members as private and make getter setter funtions to access it .
class BankAccount {
private :
string name ;
    float amount  ;


public :
BankAccount(string name,  int amount){
    this->name = name ;
    this->amount = amount ;
}
    string get_name(){
    return this->name ;
}
    float  get_amount(){
    return this->amount ;
}
    void set_name(string name) {
    this->name = name ;
}
    void set_amount(int amount){
    this->amount = amount ;
}


    // depostite function 		// withdraw

    void deposit(float x){
    this->amount+=x ;
}

    void withdraw(int x) {
    if(x > this->amount) {
        return ;
    }

    this->amount -= x;
}



} ;
int main() {
    // OOPS pillars

    // 1) encapsulation

    // bundling data and methods together  is encapsulation

    // controlling who is able to access what in the class

    BankAccount b("A" , 1000) ;

    cout<<b.get_name() ;






    return 0;
}