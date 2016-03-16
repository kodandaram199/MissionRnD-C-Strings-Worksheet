/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int reverse(float number)
{
	int rev;
	for (rev = 0; number > 0.9; number /= 10)
	{
		rev = rev * 10 + (int)number % 10;
	}
	return rev;
}
void number_to_str(float number, char *str, int afterdecimal){
	int index = 0;
	if (number < 0)
	{
		str[index++] = '-';
		number *= -1;
	}
	int rev = reverse(number);
	while (rev > 0)
	{
		str[index++] = rev % 10 + '0';
		rev = rev / 10;
	}
	str[index++] = '.';
	for (rev = 1; rev <= afterdecimal; rev++)
	{
		number *= 10;
		str[index++] = (int)number % 10 + '0';
	}
}

