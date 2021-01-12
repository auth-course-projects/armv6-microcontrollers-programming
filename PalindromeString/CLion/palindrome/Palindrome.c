#include "Palindrome.h"

/**
 * @brief Check if ${string} is a palindrome.
 * @author Thanasis Charisoudis
 * @param string
 * @return 1 if TRUE, 0 if FALSE
 */
int isPalindrome(const char *string)
{
    // Compute string length
    unsigned int length = 0;
    while( string[++length] != '\0' );
//    fprintf( stdout, "String's length = %02d\n", length );

    // Check edge characters
    for( unsigned int left = 0, right = length - 1; left < right; left++, right-- )
    {
        if ( string[left] != string[right] )
            return 0;
    }

    return 1;
}
