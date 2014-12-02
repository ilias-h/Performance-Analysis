#include<stdio.h>

static int binary_search(int * array, int lower, int upper,int val){
	if(upper<lower)
		return -1;
	else{
		int pivot = (lower+upper)/2;
		if(array[pivot]==val)
			return pivot;
		else if(array[pivot]>val){
			return binary_search(array,lower,pivot-1,val);
		}else{//if(array[pivot]<val){
			return binary_search(array,pivot+1,upper,val);
		}
	}

}


int bsearch(int * array, int size, int val){
	return binary_search(array,0,size-1,val);	
}

