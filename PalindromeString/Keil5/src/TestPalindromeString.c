#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include "PalindromeString.h"

void testIsPalindrome(void);
void testIsPalindromeAsm(void);

static char testString[] = "racecar";

int main()
{
	// testIsPalindrome();
	testIsPalindromeAsm();
}

void testIsPalindrome(void)
{
	uint8_t result;
	result = isPalindrome(testString);
	
	printf("\"%s\" IS%s A PALINDROME", testString, result ? "" : " NOT");
}

void testIsPalindromeAsm(void)
{
	uint8_t result;
	isPalindromeAsm(testString, &result);
	
	printf("\"%s\" IS%s A PALINDROME", testString, result ? "" : " NOT");
}
