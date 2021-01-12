#ifndef PALINDROME_PALINDROME_H
#define PALINDROME_PALINDROME_H

#include <inttypes.h>

/**
 * @brief Check if ${string} is a palindrome.
 * @author Thanasis Charisoudis
 * @param string
 * @return 1 if TRUE, 0 if FALSE
 */
uint8_t isPalindrome(const char *string);

/**
 * @brief Check if ${string} is a palindrome using Embedded ARM assembly.
 * @author Thanasis Charisoudis
 * @param string
 * @param result (pointer to result variable)
 * @return void
 */
void isPalindromeAsm(const char *string, uint8_t *result);

#endif //PALINDROME_PALINDROME_H
