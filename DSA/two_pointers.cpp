
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

	int main() {


		return  0 ;
	}