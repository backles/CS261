/* CS261- Assignment 1 - Q.3*/
/* Name: Braden Ackles
* Date:4/5/2015
* Solution description:
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*
function description:Sorter
preconditions:an array and its length
postconditions:A sorted array
*/
void sort(int* number, int n){
	/*Sort the given array number , of length n*/
	int temp = 0, j, i;
	for (i = 1; i<n; i++){
		for (j = 0; j<n - i; j++){
			if (number[j] >number[j + 1]){
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
			}
		}
	}
}


/*
function description: Main
preconditions:None
postconditions:Sorted Array
*/
int main(){
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	/*Allocate memory for an array of n integers using malloc.*/
	int* array1;
	array1 = malloc(n*sizeof(int));
	/*Fill this array with random numbers between 0 and n, using rand().*/
	for (int i = 0; i < n; i++){
		array1[i] = rand()%n+1;
	};
	/*Print the contents of the array.*/
	printf("The array before it is sorted is: ");
	for (int i = 0; i < n; i++){
		printf("%d, ", array1[i]);
	};
	/*Pass this array along with n to the sort() function.*/
	sort(array1, n);
	/*Print the contents of the array.*/
	printf("\nThe array after it is sorted is: ");
	for (int i = 0; i < n; i++){
		printf("%d, ", array1[i]);
	};
	printf("\n");
	return 0;
}
