/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>

char KthIndexFromEnd(char *str, int K) {
	int index;
	if (str == 0 || str == "" || K<0)
		return '\0';
	for (index = 0; str[index] != '\0'; index++);
	return(str[index - K - 1]);
}