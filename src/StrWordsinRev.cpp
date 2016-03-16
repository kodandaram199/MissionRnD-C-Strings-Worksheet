/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void reverse(char* str, int begin, int end)
{
	int length = end - begin + 1;
	char temp;
	int i;
	for (i = 1; i <= length / 2; i++)
	{
		temp = str[begin];
		str[begin++] = str[end];
		str[end--] = temp;
	}
}
void str_words_in_rev(char *input, int len){
	int index, startindex = 0;
	reverse(input, 0, len - 1);
	for (index = 0; index <= len; index++)
	{
		if (input[index] == 32 || index == len)
		{
			reverse(input, startindex, index - 1);
			startindex = index + 1;
		}
	}
}


