#include<stdio.h>

void bsort(int *array, int size){
	int s,i,temp,sorted=0;
	s = size-1;

	do{
		sorted = 1;
		for(i=0;i<s;i++){
			if(array[i]>array[i+1]){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1]=temp;
				sorted = 0;
			}
		}
		s--;
	}while(!sorted);

}
