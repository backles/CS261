/* CS261- Assignment 1 - Q.1*/
/* Name: Braden Ackles
* Date: 4/3/2015
* Solution description: Generate random Ids and scores for students and caluclate the averages and store their info in a struct
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student* allocate();
void generate(struct student* students);
void output(struct student* students);
void summary(struct student* students);
void deallocate(struct student* students);

struct student{
	int id;
	int score;
};

/*
function description: Allocate memory
preconditions: None
postconditions: Allocated memory
*/
struct student* allocate(){
	/*Allocate memory for ten students*/
	int numStudents = 10;
	struct student* stud = malloc(numStudents * sizeof(struct student)); //Allocate the memory
	/*return the pointer*/
	return stud;
}

/*
function description: Make test scores 
preconditions: Allocated memory
postconditions: Scores for students
*/
void generate(struct student* students){
	/*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
	int x, random, maxId = 10, maxScore = 100;
	srand(time(NULL));
	for (int i = 0; i < maxId; i++){
		do{
			x = 1;
			random = (rand() % maxId + 1);			//Get a random value
			for (int j = 0; j < i && x == 1; j++){
				if (students[j].id == random){
					x = 0;
				};
			};
		} while (x == 0);
		students[i].id = random;					//Set the id to random
		students[i].score = (rand() % maxScore + 1);//Set their score to a random between 0-100
	};
}

/*
function description:Ouptut the information
preconditions: Students with ids and scores
postconditions: Printed information
*/
void output(struct student* students){
	/*Output information about the ten students in the format:*/
	for (int i = 0; i < 10; i++){
		printf("The score for student '%d' is %d\n", students[i].id, students[i].score);//Print out the students information
	};
}

/*
function description:Calculates the average
preconditions:Students scores
postconditions:Average
*/
void summary(struct student* students){
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	int numStudents = 10, minScore=100, maxScore=0;
	float avg = 0.0;
	for (int i = 0; i < numStudents; i++){
		if (students[i].score < minScore){			//See if its a new low score
			minScore = students[i].score;
		}
		else if (students[i].score > maxScore){		//See if its a new max score
			maxScore = students[i].score;
		};
		avg = avg + students[i].score;				//Add to the average
	};
	avg = avg / numStudents;						//Calculate the average
	printf("The average Score is: %f\nThe lowest score was: %d\nThe highest score was: %d\n", avg, minScore, maxScore);	//Print out the information
}

/*
function description: Deallocate memory
preconditions:memory to deallocate
postconditions:none
*/
void deallocate(struct student* stud){
	/*Deallocate memory from stud*/
	free(stud);
}

int main(){
	struct student* students = NULL;
	/*call allocate*/
	students = allocate();
	/*call generate*/
	generate(students);
	/*call output*/
	output(students);
	/*call summary*/
	summary(students);
	/*call deallocate*/
	deallocate(students);
	return 0;
}