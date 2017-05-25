/*
Name: Braden Ackles & Alex Wilson
File Name: compare2.c
Date: 5/3/2015
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"

int	compare(TYPE left, TYPE right){
	if (((struct data *)left)->number < ((struct data *)right)->number){
		return -1;
	}else if (((struct data *)left)->number >((struct data *)right)->number){
		return 1;
	}else if (strcmp(((struct data *)left)->name, ((struct data *) right)->name) == 1){
		return 0;
	}
	return 0;
}

void print_type(TYPE value){
	printf("The Current Number value is: %d", ((struct data *)value)->number);
	printf("The Current Name value is: %s", ((struct data *)value)->name);
}