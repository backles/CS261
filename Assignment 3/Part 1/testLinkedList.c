/*
Programmer: Braden Ackles & Alex Wilson
Assignment: #3
Last modified: 4/22/15
*/
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){   
	//Test your linked list in here!
	struct linkedList * testLinkList = createLinkedList();
	
	//add tests
	printf("These tests will add to the list\n");
	addFrontList(testLinkList, 25);
	addFrontList(testLinkList, 35);
	addFrontList(testLinkList, 45);
	addBackList(testLinkList, 5);
	printList(testLinkList);
	addBackList(testLinkList, 15);
	printList(testLinkList);
	addBackList(testLinkList, 25);
	printList(testLinkList);
	//get front Value
	int tmp = frontList(testLinkList);
	printf("The First Value in the List is: %d\n", tmp);
	//get rear value
	tmp = backList(testLinkList);
	printf("The Last Value in the List is: %d\n", tmp);
	//remove tests
	printf("These tests will remove from the array\n");
	removeFrontList(testLinkList);
	printList(testLinkList);
	removeFrontList(testLinkList);
	printList(testLinkList);
	removeFrontList(testLinkList);
	printList(testLinkList);
	removeBackList(testLinkList);
	printList(testLinkList);
	removeBackList(testLinkList);
	printList(testLinkList);
	removeBackList(testLinkList);
	printList(testLinkList);
	
	if (isEmptyList(testLinkList)){
		printf("The List is empty this is the expected result!\n");
	} else{
		printf("The List is not empty this is not the expected result!\n");
	}
	return 0;
}