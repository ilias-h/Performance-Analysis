#include<stdio.h>
#include"bsort_out.h"
#include"qsort_out.h"
#include"isort_out.h"

#include"lsearch.h"
#include"bsearch.h"
#include"mkarr.h"
#include"qsort.h"

void disp_menu(){
	printf("\n\n*****************************\n");
	printf("*           MENU            *\n");
	printf("*****************************\n");
	printf("*   a: Show menu            *\n");
	printf("*   b:                      *\n");
	printf("*                           *\n");
	printf("*   c: Bubblesort best      *\n");
	printf("*   d: Bubblesort random    *\n");
	printf("*   e: Bubblesort worst     *\n");
	printf("*                           *\n");
	printf("*   f: Insertionsort best   *\n");
	printf("*   g: Insertionsort random *\n");
	printf("*   h: Insertioinsort worst *\n");
	printf("*                           *\n");
	printf("*   i: Quicksort best       *\n");
	printf("*   j: Quicksort random     *\n");
	printf("*   k: Quicksort worst      *\n");
	printf("*                           *\n");
	printf("*   l: Linear search best   *\n");
	printf("*   m: Linear search random *\n");
	printf("*   n: Linear search worst  *\n");
	printf("*                           *\n");
	printf("*   o: Binary search best   *\n");
	printf("*   p: Binary search random *\n");
	printf("*   q: Binary search worst  *\n");
	printf("*                           *\n");
	printf("*   r: End program          *\n");
	printf("*****************************\n");
}

void get_input(char *val){
	printf("Välj från menyn: ");
	scanf(" %c", val);
}

void sort(char *text, int * array,int size,void (*sort_funk)(int*,int)){
	int i;
	printf("Sorteringsalgoritm: %s\n", text);
	printf("Osorterad:\n");
	for(i=0;i<size;i++)
		printf(" %d ",array[i]);
	printf("\n");
	sort_funk(array,size);
	printf("Sorterad:\n");
	for(i=0;i<size;i++)
		printf(" %d ",array[i]);
	printf("\n");
}

void search(char *text,int (*search_funk)(int *,int,int), int * array,int size){
	int val;
	printf("Var god skriv in vilket värde du söker:\n");
	scanf(" %d",&val);
	printf("Söker med %s:\n",text);
	val = search_funk(array,size,val);
	if(val>=0)
		printf("Värdet %d fanns på plats %d\n",array[val], val);
	else
		printf("Det sökta värdet fanns inte i arrayen.\n");
}


void test(){
	int *array,i;
	array = reverse_array(30);
	printf("\nOmvänd array:");
	printf("\n");
	for(i=0;i<30;i++){
		printf("%d   ",array[i]);
	}
	printf("\n");
	qsorting(array,30);
	printf("Sorterad med quickie:\n");
	for(i=0;i<30;i++){
		printf("%d   ",array[i]);
	}
	printf("\n\n");
	printf("Slumpartad array:\n");
	array = rand_array(30);
	for(i=0;i<30;i++){
		printf("%d   ",array[i]);
	}
	printf("\n");
	qsorting(array,30);
	printf("Sorterad med quickie:\n");
	for(i=0;i<30;i++){
		printf("%d   ",array[i]);
	}
	printf("\n");
	array = order_array(30);
	for(i=0;i<30;i++){
		printf("%d   ",array[i]);
	}
	printf("\n\n");
}

int main(){
	
	char val;

	printf("\n\n");
	printf("*************************\n");
	printf("*     Laboration 2      *\n");
	printf("*************************\n");

	disp_menu();

	do{
		get_input(&val);

		switch(val){
			case 'a': case 'A':	disp_menu();				break;

			case 'b': case 'B':	test();			break;

			case 'c': case 'C':	bsort_best();				break;
			case 'd': case 'D':	bsort_random();				break;
			case 'e': case 'E':	bsort_worst();				break;

			case 'f': case 'F':	isort_best();				break;
			case 'g': case 'G':	isort_random();				break;
			case 'h': case 'H':	isort_worst();				break;

			case 'i': case 'I':	qsort_best();				break;
			case 'j': case 'J':	qsort_random();				break;
			case 'k': case 'K':	printf("Inte klar!\n");			break;

			case 'l': case 'L':	printf("Inte klar!\n");			break;
		//	case 'm': case 'M':	search("Linear search",lsearch,array,20);				break;
			case 'n': case 'N':	printf("Inte klar!\n");			break;
			case 'o': case 'O':	printf("Inte klar!\n");			break;
		//	case 'p': case 'P':	search("Binary search",bsearch,array,20);			break;
			case 'q': case 'Q':	printf("Inte klar!\n");			break;
			case 'r': case 'R':	printf("Ending program...\n");		break;
			default : printf("Ogiltigt val!\n");
		}
	
	}while(val != 'r' && val != 'R');
	printf("\nBye Bye!\n\n");
	return 0;

}
