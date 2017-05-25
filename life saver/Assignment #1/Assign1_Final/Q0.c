/* CS261- Assignment 1 - Q. 0*/
/* Name: Pranav T. Ramesh
 * Date: 1/10/2015
 * Solution description: Simple program that passes the address of x to fooA() and prints various addresses and values. 
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Prints the value of the integer pointed to by iptr*/
     printf("The value of the integer pointed to by iptr is: %d\n", *iptr);
     /*Prints the address pointed to by iptr*/
     printf("The address pointed to by iptr is: %p\n", iptr);
     /*Prints the address of iptr itself*/
     printf("The address of iptr itself is: %p\n", &iptr);
}

int main(){
    int x = 10; /*declared a variable x and gave it a value of 10*/

    printf("The address of x is: %p\n", &x); /*prints the address of x*/

    fooA(&x); /*passes the address of x to fooA()*/

    printf("The value of x is: %d\n", x); /*prints the value of x*/

    return 0;
}
