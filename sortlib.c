/* sortlib.c -- The common list tools to generate a list of random integers and check the output
 * Authors: Philip Robinson, Hayden Liao
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortlib.h"

// Generate a random number between 0 and [limit] inclusive
// Source: https://stackoverflow.com/questions/2999075/generate-a-random-number-within-LIST_MAX/
int generate_random_num(int max_val) {
    int divisor = RAND_MAX / ( max_val + 1 );
    int retval;
    // Properly generate the random numbers without mod
    do {
        retval = rand() / divisor;
    } while ( retval > max_val );

    return retval;
}

// Generate array of size N with random digits.
int * generate_input( int num_elements ) {
    // malloc memory for an array of size N
    int * array = malloc( num_elements * sizeof( int ) );
    // Declare variables
    int i;
    // Intialize random number generator
    srand( (unsigned) time( NULL ) );
    // Populate the array and return it
    for( i = 0; i < num_elements; i++ ) {
        array[i] = generate_random_num(num_elements);
    }
    return array;
}

// Print the output
void check_output( int * arr, int size ) {
    if( size < 11 ) {
        for( int i = 0; i < size; i++ ) {
            printf( "%d ", arr[i] );
        }
        printf( "\n" );
    } else {
        // Print out the first and last 5
        printf( "%d %d %d %d %d ... %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4],
                arr[size-5], arr[size-4], arr[size-3], arr[size-2], arr[size-1] );
    }
}
