#include<stdio.h>


static int partion(int * array, int lower, int upper){
	int temp, pivot;
	pivot = (upper+lower)/2;	
	do{
		while(array[lower] < array[pivot] && lower<pivot)
			lower++;
		while(array[upper] > array[pivot] && upper>pivot)
			upper--;
		if(lower<upper){
			if(pivot==lower)
				pivot=upper;
			else if(pivot==upper)
				pivot=lower;
			temp = array[lower];
			array[lower] = array[upper];
			array[upper] = temp;
		}
	}while(lower<upper);
	return pivot;
}


static void quicksort(int * array, int lower, int upper){
	if(lower<upper){
		int pivot = partion(array,lower,upper);
		quicksort(array,lower,pivot-1);
		quicksort(array,pivot+1,upper);
	}

}

void qsorting(int * array, int size){
	quicksort(array,0,size-1);
}
