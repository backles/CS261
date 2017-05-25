/* CS261- Assignment 1 - Q.5*/
/* Name: Braden Ackles
* Date: 4/8/2015
* Solution description: Creates upper/lowercase
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
	return ch - 'a' + 'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
	return ch - 'A' + 'a';
}

/*
function description:Changes letter casing
preconditions: Word
postconditions:Word with alternate casing
*/
void studly(char* word){
	/*Convert to studly caps*/
	int i = 0, alt = 2;
	while (word[i] != 0){
		if (i%alt == 0){
			if (!isupper(word[i])){
				word[i] = toUpperCase(word[i]);
			};
		}
		else if (i%alt != 0){
			if (!islower(word[i])){
				word[i] = toLowerCase(word[i]);
			}
		};
		i++;
	};
}

/*
function description:gets and prints the word
preconditions:None
postconditions: Word with letters in alternating caps
*/
int main(){
	/*Read word from the keyboard using scanf*/
	char word[256];
	printf("Please enter a word:\n");
	scanf("%s", word);
	/*Call studly*/
	studly(word);
	/*Print the new word*/
	printf("The word put through studly returns: %s\n", word);
	return 0;
}