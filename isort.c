#include<stdio.h>

void isort(int * array, int size){
	int i,j,temp;	
	for(i=0;i<size;i++){
		j=i;
		while(j>0 && array[j]<array[j-1]){
			temp = array[j];
			array[j]=array[j-1];
			array[j-1]=temp;
			j--;
		}

	}

}
