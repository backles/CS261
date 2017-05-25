/*
Programmer: Braden Ackles & Alex Wilson
Assignment: #3
Last modified: 4/22/15
*/
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    struct linkedList *testList = createLinkedList();
    
    addFrontList(testList, 1);
    addFrontList(testList, 2);
    addFrontList(testList, 3);
    addBackList(testList, 10);
	addBackList(testList, 20);
	addBackList(testList, 30);
    printList(testList);
    
    removeFrontList(testList);
    printList(testList);
    removeFrontList(testList);
    printList(testList);
    removeBackList(testList);
    printList(testList);
    removeBackList(testList);
    printList(testList);
	removeBackList(testList);
	printList(testList);
	removeBackList(testList);
	printList(testList);
    
    if (isEmptyList(testList)){
        printf("The List is empty this is good, and the expected result \n");
    } else {
        printf("Uh Oh something went wrong! The list wasn't empty \n");
    }
    return 0;
}