#include "PalindromeString.h"

/**
 * @brief Check if ${string} is a palindrome.
 * @author Thanasis Charisoudis
 * @param string
 * @return 1 if TRUE, 0 if FALSE
 */
uint8_t isPalindrome(const char *string)
{
    unsigned int length, left, right;
	
    // Compute string length
		length = 0;
    while( string[++length] != '\0' );
//    fprintf( stdout, "String's length = %02d\n", length );

    // Check edge characters
    for( left = 0, right = length - 1; left < right; left++, right-- )
    {
        if ( string[left] != string[right] )
            return 0;
    }

    return 1;
}

/**
 * @brief Check if ${string} is a palindrome using Embedded ARM assembly.
 * @author Thanasis Charisoudis
 * @param string
 * @param result (pointer to result variable)
 * @return void
 */
__asm void isPalindromeAsm(const char *string, uint8_t *result)
{
	// r0 <-- &string[0]
	// r1 <-- &result
	
	PUSH {r0, r1, r2, r3, r4}
	
	// r2 <-- &string[left]
	// r3 <-- string[left]
	// r0 <-- &string[right]
	// r4 <-- string[right]
	MOV r2, r0
	
strlen_loop
	LDRB r3, [r0], #1	// r3 <-- (*string)++
	CMP r3, #0
	BNE strlen_loop

strlen_loop_end
	SUB r0, r0, #2		// right <-- strlen(string) - 1
	
checkedges_loop
	LDRB r3, [r2]
	LDRB r4, [r0]
	CMP r3, r4
	BNE return_result_false
	
	ADD r2, r2, #1
	SUB r0, r0, #1
	CMP r2, r0
	BPL return_result_true
	
	B checkedges_loop
	
	
return_result_false
	MOV r0, #0
	B return_result
	
return_result_true
	MOV r0, #1
	B return_result
	
return_result
	STRB r0, [r1]
	POP {r0, r1, r2, r3, r4}
	BX lr
}
