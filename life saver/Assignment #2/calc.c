/* Pranav Ramesh & Sean Marty
* Assignment 2: calc.c
* January 22, 2015
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
   */
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if (strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if ((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
	*/
void add(struct DynArr *stack)
{
	TYPE temp1, temp2, result;

	if (sizeDynArr(stack) < 2){
		printf("ERROR, couldn't perform sum, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	temp2 = topDynArr(stack);
	popDynArr(stack);

	result = temp1 + temp2;
	pushDynArr(stack, result);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	TYPE temp1, temp2, result;

	if (sizeDynArr(stack) < 2){
		printf("ERROR, couldn't perform difference, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	temp2 = topDynArr(stack);
	popDynArr(stack);

	result = temp2 - temp1;
	pushDynArr(stack, result);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	TYPE temp1, temp2, result;

	if (sizeDynArr(stack) < 2){
		printf("ERROR, couldn't perform division, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	temp2 = topDynArr(stack);
	popDynArr(stack);

	result = temp2 / temp1;
	pushDynArr(stack, result);
}

void multiply(struct DynArr *stack){
	TYPE temp1, temp2, result;

	if (sizeDynArr(stack) < 2){
		printf("ERROR, couldn't perform multiplication, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	temp2 = topDynArr(stack);
	popDynArr(stack);

	result = temp1 * temp2;
	pushDynArr(stack, result);
}

void power(struct DynArr *stack){
	TYPE temp1, temp2, result;

	if (sizeDynArr(stack) < 2){
		printf("ERROR, couldn't perform power, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	temp2 = topDynArr(stack);
	popDynArr(stack);

	result = pow(temp2, temp1);
	pushDynArr(stack, result);
}

void square(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform square, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = pow(temp1, 2);
	pushDynArr(stack, result);
}

void cube(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform square, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = pow(temp1, 3);
	pushDynArr(stack, result);
}

void absolute(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform absolute value, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = fabs(temp1);
	pushDynArr(stack, result);
}
void squareRoot(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform square root, too few operands.");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = sqrt(temp1);
	pushDynArr(stack, result);
}

void exponential(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform exponential, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = exp(temp1);
	pushDynArr(stack, result);
}

void natLog(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform natural log, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = log(temp1);
	pushDynArr(stack, result);
}

void baseTenLog(struct DynArr *stack){
	TYPE temp1, result;

	if (sizeDynArr(stack) == 0){
		printf("ERROR, couldn't perform base 10 log, too few operands. \n");
		exit(0);
	}

	temp1 = topDynArr(stack);
	popDynArr(stack);
	result = log10(temp1);
	pushDynArr(stack, result);
}
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double num;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if (strcmp(s, "/") == 0)
			divide(stack);
		else if (strcmp(s, "x") == 0)
			multiply(stack);
		else if (strcmp(s, "^") == 0)
			power(stack);
		else if (strcmp(s, "^2") == 0)
			square(stack);
		else if (strcmp(s, "^3") == 0)
			cube(stack);
		else if (strcmp(s, "abs") == 0)
			absolute(stack);
		else if (strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if (strcmp(s, "exp") == 0)
			exponential(stack);
		else if (strcmp(s, "ln") == 0)
			natLog(stack);
		else if (strcmp(s, "log") == 0)
			baseTenLog(stack);
		else 
		{
			if (isNumber(s, &num))
				pushDynArr(stack, num);
			
			else if (strcmp(s, "pi") == 0)  //allows the user to enter 'pi' in calculations
				pushDynArr(stack, 3.14159265359);

			else if (strcmp(s, "e") == 0)  //allows the user to enter 'e' in calculations
				pushDynArr(stack, 2.718281828459045);

			else{
				printf("ERROR, entered value is not a valid operator or operand. \n");
				exit(0);
			}
				
			
		}


	}	//end for 
	if (sizeDynArr(stack) > 1){
		printf("ERROR, stack ended up with more than one value remaining. \n"); //checks to make sure the stack only has one value at the end
		exit(0);
	}
	if (sizeDynArr(stack) == 0){
		printf("ERROR, stack has zero items in it. \n");  //if it doesn't have any value, it throws an error.
	}

	result = getDynArr(stack, 0);  //if it passes the above checks, then it prints the result based on the user input.
	printf("Result: %f\n", result);
	
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
