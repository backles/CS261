/* CS261- Assignment 1 - Q.4*/
/* Name: Braden Ackles
* Date: 4/9/2015
* Solution description:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

/*
function description: Sort a chunk of memory
preconditions:A chunk of memory, and the length of it
postconditions:A sorted array
*/
void sort(struct student* students, int n){
	/*Sort the n students based on their score*/
	/* Remember, each student must be matched with their original score after sorting */
	int temp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (students[i].score > students[j].score){
				//For the top to be highest
				temp = students[i].score;
				students[i].score = students[j].score;
				students[j].score = temp;
				temp = students[i].id;
				students[i].id = students[j].id;
				students[j].id = temp;
			}
			/*
			if (students[i].id > students[j].id){
				//For IDs
				temp = students[i].id;
				students[i].id = students[j].id;
				students[j].id = temp;
				temp = students[i].score;
				students[i].score = students[j].score;
				students[j].score = temp;
			}
			*/
			/*
			if (students[i].score < students[j].score){
				//for the bottom to be highest
				temp = students[i].score;
				students[i].score = students[j].score;
				students[j].score = temp;
				temp = students[i].id;
				students[i].id = students[j].id;
				students[j].id = temp;
			}
			*/
		}
	};
}

/*
function description Generate a chunk of memory and fill it will values and print them
preconditions: None
postconditions: Unsorted and sorted array are printed out
*/
int main(){
	/*Declare an integer n and assign it a value.*/
	int n, temp = 1, rando = 0, maxScore = 100;
	/*Allocate memory for n students using malloc.*/
	struct student * students = (struct student *)malloc(n*sizeof(struct student));
	/*Generate random IDs and scores for the n students, using rand().*/
	srand(time(NULL));
	printf("Enter the number of students: \n");
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		do{
			rando = (rand() % n + 1);
			for (int j = 0; j < i; j++){
				if (students[j].id == rando){
					temp = 1;
				};
			};
		} while (temp == 0);
		students[i].id = rando;
		students[i].score = (rand() % maxScore + 1);
	}
	/*Print the contents of the array of n students.*/
	printf("The unsorted list is: \n");
	for (int i = 0; i < n; i++){
		printf("The students ID is: %d, Their score was: %d\n", students[i].id, students[i].score);
	};
	/*Pass this array along with n to the sort() function*/
	sort(students, n);
	/*Print the contents of the array of n students.*/
	printf("The sorted list is: \n");
	for (int i = 0; i < n; i++){
		printf("The students ID is: %d, Their score was: %d\n", students[i].id, students[i].score);
	};
	return 0;
}
