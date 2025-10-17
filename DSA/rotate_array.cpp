
#include <iostream>
using namespace std ;




void reverse(int *arr , int i , int j){
    while(i < j){

        int temp = arr[i] ;
        arr[i] = arr[j] ;
        arr[j] = temp ;
        i++ ;
        j-- ;
    }
}
void rotate(int* nums, int numsSize, int k) {

    k = k%numsSize;
    reverse(nums , 0 , numsSize -1) ;
    reverse(nums , 0 , k-1) ;
    reverse(nums , k , numsSize -1) ;



}

int main() {


    return  0 ;
}