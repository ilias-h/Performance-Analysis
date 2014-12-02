#include<time.h>
#include<stdlib.h>
#include<stdio.h>


int *order_array(int size){
	int *array, i;
	array = (int *) malloc(size*sizeof(int));	//initialiserar arrayen

	for(i=0;i<size;i++){				//Fyller arrayen med 1,2,3,4...
		array[i] = i+1;
	}

	return array;
}


int *rand_array(int size){

	int *array, i, temp,r;
	array = order_array(size);


	srand(time(NULL));

	for(i=0;i<size;i++){				//kastar om värdena slumpartat i arrayen
		r = rand()%size;
		temp = array[i];
		array[i] = array[r];
		array[r] = temp;
	}
	return array;
}

int *reverse_array(int size){
	int *array, i;
	array = (int *) malloc(size*sizeof(int));	//initialiserar arrayen

	for(i=0;i<size;i++){				//Fyller arrayen med n,n-1,n-2 ... ,2,1
		array[i] = size - i;
	}

	return array;


}
