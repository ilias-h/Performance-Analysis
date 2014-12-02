#include<stdio.h>

int lsearch(int * array, int size, int value){
	int i=0;
	while(i<size && array[i]!=value)
		i++;

	return value==size ? -1 : i;

}
