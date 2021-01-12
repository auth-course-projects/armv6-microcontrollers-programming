#include <stdio.h>
#include <assert.h>
#include "Palindrome.h"

const char *ExamplePalindromes[] = {
    "anna",
    "civic",
    "kayak",
    "level",
    "madam",
    "mom",
    "noon",
    "racecar",
    "radar",
    "redder",
    "refer",
    "repaper",
    "rotator",
    "rotor",
    "sagas",
    "solos",
    "stats",
    "tenet",
    "wow"
};

int main()
{
    for( unsigned int exampleIndex = 0; exampleIndex < 19; exampleIndex++ )
    {
        const char *example = ExamplePalindromes[ exampleIndex ];
        int isExamplePalindrome = isPalindrome( example );

        fprintf( stdout,"\"%s\" IS %s PALINDROME\n", example, 0 == isExamplePalindrome ? "NOT A" : "A" );
        assert( isExamplePalindrome == 1 );
    }
    fprintf( stdout, "--> TEST SUCCESSFUL <--" );

    return 0;
}
