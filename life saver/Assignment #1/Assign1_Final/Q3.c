/* CS261- Assignment 1 - Q.3*/
/* Name: Pranav T. Ramesh
 * Date: 1/14/15
 * Solution description: This program creates an array with random integers using rand(). Then the array is sorted using the sort function and then re-printed in ascending order. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int i, j, x;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (number[i] > number[j]){
				x = number[i];
				number[i] = number[j];
				number[j] = x;
			}

		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int i, n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	int * intArray = (int *)malloc(n*sizeof(int));
    /*Fill this array with random numbers between 0 and n, using rand().*/
	srand(time(NULL)); //allows it to truly be random and change with respect to time
	for (i = 0; i < n; i++) 
		intArray[i] = (rand() % n + 1);
		
	
    /*Print the contents of the array.*/
	printf("Unsorted array: \n");
	for (i = 0; i < n; i++){
		intArray[i] = (rand() % n + 1);
		printf("%d\n", intArray[i]);
	}
		
    /*Pass this array along with n to the sort() function.*/
	sort(intArray, n);
    /*Print the contents of the array.*/  
	printf("Sorted array: \n");
	for (i = 0; i < n; i++)
		printf("%d\n", intArray[i]);
    
    return 0;
}
