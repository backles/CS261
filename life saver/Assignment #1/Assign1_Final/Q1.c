/* CS261- Assignment 1 - Q.1*/
/* Name: Pranav T. Ramesh
 * Date: 1/10/2015
 * Solution description: Generates random ID's and scores and stores them in the given struct by type and outputs them to the screen
 with the min, max, average scores.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student* allocate();
void generate(struct student* students);
void output(struct student* students);
void summary(struct student* students);
void deallocate(struct student* stud);

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	 int numberOfStudents = 10;
	 struct student* s = malloc(numberOfStudents * sizeof(struct student));
	 if (s == 0){ /*checks to make sure s is not empty*/
		 printf("There has been an error.");
		 exit(0);
	 }
	 else
		 printf("Memory has been allocated. \n");
     /*return the pointer*/
	 return s;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
	int i, j, x;
	int maxIDValue = 10;
	int maxScoreValue = 100;
	int random = 0;

	srand(time(NULL)); //this allows the values to change every time the program is run based on time
	for (i = 0; i < maxIDValue; i++) {
		do {
			x = 1;
			random = (rand() % maxIDValue + 1);  //generates random ID for each student

			for (j = 0; j < i && x == 1; j++) {  //check array if there are any matching ID numbers
				if (students[j].id == random) {
					x = 0;
				}
			}
		} 
		
		while (x == 0);  
		students[i].id = random;
		students[i].score = (rand() % maxScoreValue + 1);  //generate random score for each student
	}
}
	


void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int i;
	int maxValue = 10;
	printf("Scores: \n\n");
	for (i = 0; i < maxValue; i++){
		printf("ID: %d  Score: %d\n", students[i].id, students[i].score);
	}
	printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int i;
	//int score;
	int numberOfStudents = 10;
	int minScore = students[0].score; /*initializes the min and max for the scores*/
									 /*and they will be used at the end to display the values.*/
	int maxScore = students[0].score;
	int avgScore = 0;

	for (i = 0; i < numberOfStudents; i++) {  /*compares each score to see if it is the minimum or maximum*/
		if (students[i].score < minScore) {
			minScore = students[i].score;
		}
		if (students[i].score > maxScore) {
			maxScore = students[i].score;
		}
		avgScore = avgScore + students[i].score;
	}

	avgScore = avgScore / numberOfStudents;

	printf("Summary: \n");
	printf("\n");
	printf("Average Score: %d\n", avgScore);
	printf("Minimum (Lowest) Score: %d\n", minScore);
	printf("Maximum (Highest) Score: %d\n", maxScore);
	
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;
	
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
