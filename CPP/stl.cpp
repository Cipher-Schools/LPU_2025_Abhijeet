// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std ;


    void rotate(vector<int>& nums, int k) {

        k = k%nums.size() ;
        reverse(nums.begin() , nums.end()) ;
        reverse(nums.begin() , nums.begin() +k);
        reverse(nums.begin() +k , nums.end());


    }


void print(vector<int> & arr){
    for(int i =0 ;i<arr.size() ;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl ;
}

int main() {
    // Write C++ code here

    vector<int> arr ;

    //

    arr.push_back(10);
    // insert at last
    arr.push_back(4) ;
    arr.push_back(30) ;
    arr.push_back(1) ;
    arr.push_back(40) ;

    // removing from the last

    // arr.pop_back() ;

    //. insert

    cout<<arr[1]<<" "<<arr.size()<<" "<<arr.capacity()<<endl ;




    // iterate the vector

    arr.insert(arr.begin() +2 , 90);

    // arr.beign() ---> address of first block of arr , arr[0]

    arr.erase(arr.begin()+2) ;


    // sorting nusing stl
    sort(arr.begin() , arr.end());



    cout<<endl;

    print(arr) ;


    return 0;
}