/* CS261- Assignment 1 - Q.5*/
/* Name: Pranav T. Ramesh
 * Date: 1/13/2015
 * Solution description: Takes input from user and converts the word they entered into StUdLy format.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
	int i = 0;
	int alternateValue = 2;
	while (word[i] != 0) {		 
		if (i % alternateValue == 0) {  /* this statement checks each character in the array to see whether it is captial or lowercase.*/
			if (!isupper(word[i]))  
				word[i] = toUpperCase(word[i]);
		}											/*uses the isupper and islower functions from ctype.h*/
		else if ((i % alternateValue != 0)) {
			if (!islower(word[i]))
				word[i] = toLowerCase(word[i]);
		}
			i++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
	char word[256];
	printf("Enter a word: ");
	scanf("%s", word);
    /*Call studly*/
	studly(word);
    /*Print the new word*/
	printf("The word in studly caps: %s\n", word);
    return 0;
}
