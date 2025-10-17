
// Online Free C++ compiler to run C++ program online
#include <iostream>
using namespace std ;
class Car {
    // data members
private  :
string name ;
    int speed ;
    int dis ;
    const int id =0   ;



    // parametrized constructor ;
public :
static  int count ;
    Car(string name , int speed){
        this->name = name ;
        this->speed = speed ;
        count++ ;
    }

    // default constructor
    Car() {

    }

    // copy constructor

    Car(Car &c){
        this->name = c.name ;
        this->speed = c.speed ;
        this->dis =0 ;
    }
    // member functions
    void move(int time){
        dis = this->speed*time ;
    }

    static int get_count() {
        // you cant access member variable only satic variables
        return count ;
    }

    // firend function
    //its a function that can access the private members of the class

    friend int get_dis(Car &c) ;

    friend class Bus ;


};

int Car::count = 0 ;
int get_dis(Car &c){
    return c.dis ;
}
int main() {
    // dynamic memory allocation to heap return the pointer to the memory in heap so we need to use pointers


    Car *c = new Car("volvo" , 120) ;
    c->move(2) ;
    Car *c1 = new Car("volvo" , 120) ;

    cout<<Car::get_count() ;


    //Static variables is a variable which shared among all object of the class
    // static function is a fucntion that belong to the entire class
    // const variable values cant be changed after assigment

    const int id = 1 ;
    id = 2 ;



    // Car *c1 = c ; shallow copy
    // deep copy with help of copy constructor
    // ->. when we have pointer to the object
    // . when we have the object

    // Car c1 = *c;
    // c1.name="BMW" ;
    // cout<<c->name ;
    // cout<<endl;

    // cout<<&c1.name<<" "<<&c->name ;


    return 0;
}