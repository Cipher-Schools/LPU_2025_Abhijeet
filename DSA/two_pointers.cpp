
	#include <iostream>
	using namespace std ;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// LC 167 Two sum 2
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

	int *ans = (int *)malloc(2 * sizeof(int));
	*returnSize = 2;
	int i =0 ;
	int j = numbersSize -1 ;
	while (i < j){
		int sum = numbers[i] + numbers[j] ;
		if(sum == target){
			ans[0] = i+1 ;
			ans[1] = j+1 ;
			return ans ;
		}
		else if(sum > target){
			j-- ;
		}
		else {
			i++ ;
		}
	}

	return ans ;
}


// two sum in same direction

//lC 282
void moveZeroes(int* nums, int numsSize) {
	int j =0 ;
	for(int i =0 ;i<numsSize ;i++){
		if(nums[i] != 0){
			int temp = nums[j] ;
			nums[j] =nums[i] ;
			nums[i] = temp ;

			j++ ;
		}
	}


}
// lc 26
int removeDuplicates(int* arr, int numsSize) {

	int j =1;
	for(int i =1 ;i<numsSize ;i++){
		if(arr[i] != arr[i-1]){
			arr[j] = arr[i] ;
			j++ ;
		}
	}

	return j ;
}


	int main() {


		return  0 ;
	}