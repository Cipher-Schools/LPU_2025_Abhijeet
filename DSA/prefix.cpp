// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ;

int main() {
    // Write C++ code here
    int arr [] = {1 ,2 ,3 ,4 ,5};
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int prefix [n] ;
    int suffix[n] ;

    prefix[0] =arr[0] ;
    suffix[n-1] = arr[n-1] ;

    for(int i =1 ;i<n ;i++){
        prefix[i] = prefix[i-1] + arr[i] ;
    }

    for(int i = n-2 ;i>=0 ;i--){
        suffix[i] = suffix[i+1]  + arr[i] ;
    }


    for(int i =0 ;i<n ;i++){
        cout<<prefix[i]<<" ";
    }

    cout<<endl;

    for(int i =0 ;i<n ;i++){
        cout<<suffix[i]<<" ";
    }
    return 0;
}