#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<assert.h>
#include<unistd.h>
#include"mkarr.h"
#include"bsort.h"
#include"printres.h"

int static difftod(struct timeval * tv0, struct timeval * tv1){
	return (tv1->tv_sec - tv0->tv_sec)*1000 + (tv1->tv_usec- tv0->tv_usec)/1000;
}

void bsort_random(){
	int i,j,N=512,*array;

	int rtn;
	struct timeval tv0, tv1;
	struct timezone tzp;

	double time=0;
	pinfo("Bubblesort: Random");
	for(i=0;i<5;i++){
		N*=2;
		time = 0;
		array = rand_array(N);
		for(j=0;j<10;j++){
			
			rtn = gettimeofday(&tv0, &tzp);
			bsort(array,N);
			rtn = gettimeofday(&tv1, &tzp); 
			time += (double)difftod(&tv0,&tv1);

		}
		
		pres(N,time/10.0);

	}

}

void bsort_best(){
int i,N=512,*array;

	int rtn;
	struct timeval tv0, tv1;
	struct timezone tzp;

	pinfo("Bubblesort: Best");
	for(i=0;i<5;i++){
		N*=2;
		array = order_array(N); 
		
		rtn = gettimeofday(&tv0, &tzp);
		bsort(array,N);
		rtn = gettimeofday(&tv1, &tzp); 
		
		pres(N,(double)difftod(&tv0,&tv1));
	}
}

void bsort_worst(){
int i,N=512,*array;

	int rtn;
	struct timeval tv0, tv1;
	struct timezone tzp;

	pinfo("Bubblesort: Worst");
	for(i=0;i<5;i++){
		N*=2;
		array = reverse_array(N);
		
		rtn = gettimeofday(&tv0, &tzp);
		bsort(array,N);
		rtn = gettimeofday(&tv1, &tzp); 
		
		pres(N,(double)difftod(&tv0,&tv1));
	}
}
