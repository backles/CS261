/* CS261- Assignment 1 - Q.2*/
/* Name: Braden Ackles
* Date:	4/3/2015
* Solution description:
*/

#include <stdio.h>
#include <stdlib.h>

 /*
	function description:Practice pointers
	preconditions:Two pointers and a variable
	postconditions:Altered values pointers point to and return c
    */
int foo(int* a, int* b, int c){
	/*Set a to double its original value*/
	*a = *a * 2;
	/*Set b to half its original value*/
	*b = *b / 2;
	/*Assign a+b to c*/
	c = *a + *b;
	/*Return c*/
	return c;
}

 /*
	function description:Practice passing pointer
	preconditions: None
	postconditions:Printed out values of pointers
    */
int main(){
	/*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
	int x = 7, y = 8, z = 9;
	/*Print the values of x, y and z*/
	printf("The value of x is: %d\nThe value of y is: %d\nThe value of z is: %d\n", x, y, z);
	/*Call foo() appropriately, passing x,y,z as parameters*/
	/*Print the value returned by foo*/
	printf("The value of the returned value of foo is: %d\n", foo(&x, &y, z));
	/*Print the values of x, y and z again*/
	printf("The doubled value of x is: %d\n", x);
	printf("The halfed value of y is: %d\n", y);
	printf("The value of z is: %d\n", z);
	/*Is the return value different than the value of z?  Why?*/
	printf("The value returned by foo and z should be different "
			"because you are not passing a pointer to foo it can "
			"not change the value of z it only can change what the "
			"local function has. Which is c.\n");
	return 0;
}

/*The value is differnt because you are returning a value. You also pass z into
foo as c which is a variable and not a pointer so you can't alter the value of z in main */

