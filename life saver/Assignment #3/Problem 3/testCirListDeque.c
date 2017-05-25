#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        
    struct cirListDeque *deque = createCirListDeque();
    
    addFrontCirListDeque(deque, 30);
    addFrontCirListDeque(deque, 20);
    addFrontCirListDeque(deque, 10);
    addBackCirListDeque(deque, 40);
    addBackCirListDeque(deque, 50);
    addBackCirListDeque(deque, 60);
    
    printCirListDeque(deque);
    
    printf("Front link value: %f \n", frontCirListDeque(deque));
    printf("Back link value: %f \n", backCirListDeque(deque));
    
    printf("\nRemoving first and last element... \n\n");
    removeFrontCirListDeque(deque);
    removeBackCirListDeque(deque);
    
    printf("Front link value: %f \n", frontCirListDeque(deque));
    printf("Back link value: %f \n", backCirListDeque(deque));
    
    printf("\nRemoving all four remaining links... \n\n");
    removeBackCirListDeque(deque);
    removeBackCirListDeque(deque);
    removeBackCirListDeque(deque);
    removeBackCirListDeque(deque);
    
    
    
    if (isEmptyCirListDeque(deque)) {
        printf("isEmptyCirListDeque confirms the list is empty. \n");
    }
    else {
        printf("ERROR isEmptyCirListDeque thinks there are still one or more links present.  \n");
    }

	return 0;
}


