/*
Programmer: Braden Ackles & Alex Wilson
Assignment: #3
Last modified: 4/22/15
*/
#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() {
    return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]) {
    struct linkedList *b;
    int n, i;
    double t1, t2;
    
    for(n=1000; n < 200000; n=n*2){ /* outer loop */
        b = createLinkedList();
        for( i = 0 ; i < n; i++){
            addList(b, (TYPE)i); /*Add elements*/
        }
        t1 = getMilliseconds();/*Time before contains()*/
        //printf("time before contains: %f\n", t1);
        //printf("reached here: \n");
        for(i=0; i<n; i++){
            containsList(b, i);
        }
        t2 = getMilliseconds();/*Time after contains()*/
        printf("Time for running contains() on %d elements: %g ms\n", n, t2-t1);
        /* delete DynArr */
        deleteLinkedList(b);
    }
    return 0;
}