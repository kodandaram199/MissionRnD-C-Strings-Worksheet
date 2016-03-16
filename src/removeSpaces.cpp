/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	if (str == '\0')
		return '\0';
	int index, result;
	for (index=0; str[index] != 32; index++)
	{
		if (str[index] == '\0')
			return 0;
	}
	result = index;
	for (index = index + 1; str[index] != '\0'; index++)
	{
		if (str[index] == 32)
			continue;
		str[result] = str[index];
		result++;
	}
	str[result] = '\0';
	
}