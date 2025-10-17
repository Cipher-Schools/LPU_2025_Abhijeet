
	#include <iostream>
	using namespace std ;



	void insert(int arr[] , int * size , int val , int index =-1 ){

		if (index == -1 ){
			index = *size ;
		}
			for(int i = *size  ;i>index ;i--){
			arr[i] = arr[i-1] ;
		}

		arr[index] = val ;
		(*size)++ ;
	}

	void delete_ele(int arr[] , int*size , int index = -1){
		if(index == -1) {
			(*size)-- ;
			return ;
		}
		// left shift the array
		for(int i = index ;i<*size -1 ;i++){
			arr[i] = arr[i+1] ;
		}

		(*size)-- ;

	}

	int search(int arr [] , int size , int target){
		for(int i =0 ;i<size ;i++){
			if(arr[i] == target){
				return i ;
			}
		}

		return -1 ;
	}

	int bubble_sort(int arr [] , int size){
		int count = 0 ;
		for(int j =0 ;j<size ;j++){
			count++ ;
			bool is_sorted = true ;
			for(int i =0 ;i<size-1 -j ;i++){
			if(arr[i] > arr[i+1]){
				int temp = arr[i] ;
				arr[i] = arr[i+1] ;
				arr[i+1] = temp ;
				is_sorted =false ;
			}}
			if(is_sorted){
				return  count;
			}

		}
		return count ;
	}

	void selection_sort(int arr [] , int size){
		for(int j =0 ;j<size ;j++){
			int min = arr[j] ;
			int min_index = j;
			for(int i =j ;i<size ;i++){
				if(arr[i] < min){
					min = arr[i] ;
					min_index = i ;
				}
			}
			int temp = arr[j] ;
			arr[j] = min ;
			arr[min_index] = temp ;
		}

	}


	void insertion_sort(int arr [] , int size){
		for(int i =1 ;i<size ;i++){
			while(i> 0 && arr[i] < arr[i-1]){
			int temp = arr[i] ;
			arr[i] = arr[i-1] ;
			arr[i-1] =temp ;
			i-- ;
			}
		}

	}


	void insertion_sort2(int arr [] , int size){
		for(int i =1 ;i<size ;i++){
			int key = arr[i] ;
			int j = i-1 ;

			while(j >=0 && arr[j] > key){
				arr[j+1 ] = arr[j];
				j-- ;
			}
			arr[j+1] = key ;
		}
	}



	int main() {

		int arr[100] ;
		int  size  =0 ;

		insert(arr , &size ,  1) ;
		insert(arr , &size ,  10) ;
		insert(arr , &size ,  6) ;
		insert(arr , &size ,  6) ;
		insert(arr , &size ,  5) ;
		insert(arr , &size ,  1) ;
		insert(arr , &size ,  3) ;

		// delete_ele(arr , &size) ;
		// delete_ele(arr , &size , 1) ;

		// cout<<search(arr , size , 30)<<endl ;

		// selection_sort(arr , size) ;
		// cout<<bubble_sort(arr , size)<<endl ;

		insertion_sort2(arr , size) ;

		for(int i =0 ;i<size ;i++){
			cout<<arr[i]<<" " ;
		}
		return  0 ;
	}