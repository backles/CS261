/* CS261- Assignment 1 - Q. 0*/
/* Name: Braden Ackles
* Date: 4/3/2015
* Solution description: practice with pointers
*/

#include <stdio.h>
#include <stdlib.h>

void fooA(int*);

 /*
	function description: Print the values of x out
	preconditions: Argc and ARGV
	postconditions: Printed values
    */
int main(int argc, char ** argv){
	int x;	/*declare an integer x*/
	x = 10;	/*Give it a value*/
	/*print the address of x*/
	printf("The address of x is: %p\n", &x);
	/*Call fooA() with the address of x*/
	fooA(&x);
	/*print the value of x*/
	printf("The value of x is: %d\n", x);
};

 /*
	function description:Print values based on pointer
	preconditions:Pointer
	postconditions:Printed values
    */
void fooA(int* iptr){
	/*Print the value of the integer pointed to by iptr*/
	printf("The value iptr points to is: %d\n", *iptr);
	/*Print the address pointed to by iptr*/
	printf("The address iptr pointer to is: %p\n", iptr);
	/*Print the address of iptr itself*/
	printf("The address of iptr pointer is: %p\n", &iptr);
};