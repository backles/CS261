/*
Braden Ackles & Alex Wilson
Assignment 3: Part 3
4/26/2015
*/
#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	//Test your linked list in here!
	struct cirListDeque *cDeque = createCirListDeque();
	//Add to the "Front of the Deque
	addFrontCirListDeque(cDeque, 1);
	addFrontCirListDeque(cDeque, 2);
	addFrontCirListDeque(cDeque, 3);
	addFrontCirListDeque(cDeque, 4);
	addFrontCirListDeque(cDeque, 5);
	//Add to the"Back" of the Deque
	addBackCirListDeque(cDeque, 9);
	addBackCirListDeque(cDeque, 8);
	addBackCirListDeque(cDeque, 7);
	addBackCirListDeque(cDeque, 6);
	addBackCirListDeque(cDeque, 5);
	//Print the whole Deque
	printCirListDeque(cDeque);
	//Print the "Front" Value of the Deque
	int temp = frontCirListDeque(cDeque);
	printf("\nThe Front of the deque is: %d\n", temp);
	//Print the "Back" Value of the Deque
	temp = backCirListDeque(cDeque);
	printf("The Back of the deque is: %d\n", temp);
	//Remove elements from Deque
	printf("Removing Items\n");
	removeFrontCirListDeque(cDeque);
	removeFrontCirListDeque(cDeque);
	removeFrontCirListDeque(cDeque);
	removeFrontCirListDeque(cDeque);
	removeBackCirListDeque(cDeque);
	removeBackCirListDeque(cDeque);
	removeBackCirListDeque(cDeque);
	removeBackCirListDeque(cDeque);
	removeBackCirListDeque(cDeque);
	removeBackCirListDeque(cDeque);


	if (isEmptyCirListDeque(cDeque)){
		printf("The Deque is empty! This is the expected result!\n");
	} else{
		printf("The Deque was not empty! This means something went wrong!\n");
	}
	return 0;
}


