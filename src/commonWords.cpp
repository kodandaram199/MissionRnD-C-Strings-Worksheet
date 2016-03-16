/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".
INPUTS: Two strings.
OUTPUT: common words in two given strings, return 2D array of strings.
ERROR CASES: Return NULL for invalid inputs.
NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

int strlen(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int split(char** temp, char* str)
{
	int i, len1;
	int row = 0;
	int indexChar1 = 0;
	len1 = strlen(str);
	for (i = 0; i <= len1; i++)
	{
		if (str[i] == 32)
		{
			while (indexChar1<31)
			{
				temp[row][indexChar1++] = '\0';
			}
			row++;
			indexChar1 = 0;
			continue;
		}
		temp[row][indexChar1++] = str[i];
	}
	return row;
}

int strcmp(char* str1, char* str2)
{
	int i;
	for (i = 0; i<strlen(str1); i++)
	{
		if (str1[i] == str2[i])
		{
			continue;
		}
		return 0;
	}
	return 1;
}

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;

	int i, j, k, numWords1 = 31, numWords2 = 31, resultLen = 31;
	int indexChar1 = 0, indexChar2 = 0, resWords = 0, row = 0;

	char ** temp1, **temp2, **result;

	temp1 = (char**)malloc(numWords1 * sizeof(char*));

	for (i = 0; i<31; i++)
	{
		temp1[i] = (char*)malloc(31 * sizeof(char));
	}

	temp2 = (char**)malloc(numWords2 * sizeof(char*));

	for (i = 0; i<31; i++)
	{
		temp2[i] = (char*)malloc(31 * sizeof(char));
	}

	result = (char**)malloc(resultLen * sizeof(char*));

	for (i = 0; i<31; i++)
	{
		result[i] = (char*)malloc(31 * sizeof(char));
	}
	for (i = 0; i < 31; i++)
	{
		for (j = 0; j < 31; j++)
		{
			result[i][j] = '\0';
		}
	}

	numWords1 = split(temp1, str1);
	numWords2 = split(temp2, str2);

	for (i = 0; i <= numWords1; i++)
	{
		for (j = 0; j <= numWords2; j++)
		{
			if (strcmp(temp1[i], temp2[j]))
			{
				for (k = 0; k<strlen(temp1[i]); k++)
				{
					result[row][resWords++] = temp1[i][k];
				}

				row++;
				resWords = 0;
			}
		}
	}
	if (result[0][0] == '\0')
		return NULL;
	return result;
}