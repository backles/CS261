/* CS261- Assignment 1 - Q.4*/
/* Name: Pranav T. Ramesh
 * Date: 1/13/2015
 * Solution description: Generates random ID's and scores and stores them in the given struct by type 
 and outputs them to the screen unsorted and then sorted.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/     
     /* Remember, each student must be matched with their original score after sorting */
	int i, j, x;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (students[i].score > students[j].score){
				x = students[i].score;
				students[i].score = students[j].score;
				students[j].score = x;
				x = students[i].id;
				students[i].id = students[j].id;
				students[j].id = x;
			}
		}

	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10, i, j, x, maxScoreValue = 100, random = 0;
    /*Allocate memory for n students using malloc.*/
	struct student * students = (struct student *)malloc(n * sizeof(struct student));
	
    /*Generate random IDs and scores for the n students, using rand().*/
	srand(time(NULL));
	for (i = 0; i < n; i++) {

		do {
			x = 1;
			random = (rand() % (n + 1));  //generates random ID for each student

			for (j = 0; j < i; j++) {  //checks array if there are any matching ID numbers.
				if (students[j].id == random) {
					x = 0;

				}
			}
		}
		
		while (x == 0);  
		
		students[i].id = random;
		students[i].score = (rand() % maxScoreValue + 1);  //generates random score for each student
	}
	

    /*Print the contents of the array of n students.*/
	printf("Unsorted Scores w/ ID: \n");
	printf("\n");
	for (i = 0; i < n; i++)
		printf("ID: %d Score: %d\n", students[i].id, students[i].score);
	printf("\n");

    /*Pass this array along with n to the sort() function*/
	sort(students, n);
    /*Print the contents of the array of n students.*/
	printf("Sorted Scores w/ID: \n");
	printf("\n");
	for (i = 0; i < n; i++)
		printf("ID: %d Score: %d\n", students[i].id, students[i].score);
	printf("\n");
    return 0;
}
