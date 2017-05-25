/* CS261- Assignment 1 - Q.2*/
/* Name: Pranav T. Ramesh
 * Date: 1/12/2015
 * Solution description: Simple program that does different manipulations on variables that have been declared in main by using pointers.
 */
 
#include <stdio.h>
#include <stdlib.h>



int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    int A, B;
    A = 2*(*a);
    /*Set b to half its original value*/
    B = (*b)/ 2;
    /*Assign a+b to c*/
    c = A + B;
    /*Return c*/
    return c;

}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x, y, z;
    x = 7;
    y = 8;
    z = 9;
    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("The value returned by foo is: %d\n", foo(&x, &y, z));
    
    /*Print the values of x, y and z again*/
	printf("Values x, y, and z printed again: \n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}  
/* Yes, the return value is different than the value of z. This is because in the previous step we called foo() passing it the arguments x,y,z. 
In foo(), the values that were passed were used for different manipulations and at the end the value of c was returned. The value of c 
originally was given the value of z, but after the manipulations the value changed for 18. The reason it printed out the value 18 is because we 
returned c after the manipulation. By returning the value of c, it does NOT change the original value of z hence why when it was printed again 
it output its original value.*/