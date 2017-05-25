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
	if (((struct data1 *)left)->val < ((struct data1 *)right)->val){
		return -1;
	}else if (((struct data1 *)left)->val > ((struct data1 *)right)->val){
		return 1;
	}else if (strcmp(((struct data1 *)left) ->stringLength, ((struct data1 *) right) ->stringLength) == 1){
		return 0;
	}
	return 0;
}

void print_type(TYPE value){
	printf("The Current Number value is: %f", ((struct dataOne *)value)->val);
	printf("The Current String value is: %s", ((struct dataOne*)value)->stringLength);
}