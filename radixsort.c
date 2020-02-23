/* radixsort.c -- running radixsort on a randomly generated list.
 * Authors: Philip Robinson, Hayden Liao
 *
 * Usage: ./radixsort [LIST_SIZE]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortlib.h"
#include "radixsort.h"


// radixsort on the array of integers, base 10
void radixsort( int arr[], int length) {
  //calculate max_length
    int max_value = get_max(arr, length);
    int max_length = 0;
    while(max_value > 0) {
      max_value = (int)(max_value/10);
      max_length++;
    }
    printf("max_length: %d\n", max_length);

    for(int i=0; i<max_length; i++){
      int place = power(10,i);
      int mod = place*10;

      int i;
      for(int j=0; j<length; j++){
        int key = arr[j];
        i = j-1;
        while (i>=0 && (arr[i]%mod)>key%mod){
          arr[i+1] = arr[i];
          i--;
        arr[i+1] = key;
        }
      }
    }
}

// int* insertionsort(int arr[], int length){
//   if(arr == NULL || length == 1) return arr;
//
//   int i;
//   for(int j=0; j<length; j++){
//     int key = arr[j];
//     i = j-1;
//     while (i>=0 && arr[i]>key){
//       arr[i+1] = arr[i];
//       i--;
//     arr[i+1] = key;
//     }
//   }
//   return arr;
// }

//only for non-negative powers
int power(int base, int power){
  int ret = 1;
  while(power>0){
    ret *= base;
    power--;
  }
  return ret;
}


int get_max(int arr[], int len){
  if (arr == NULL) return 0;
  int max = arr[0];
  for(int i=0; i<len; i++){
    if(arr[i]>max)
      max = arr[i];
  }
  return max;
}


////////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char const *argv[] ) {
    // Error check input
    if ( argc != 2 ) {
        printf( "Incorrect number of arguments! Usage: %s [POSITIVE INTEGER]\n", argv[0] );
        exit( EXIT_FAILURE );
    }
    // Get the number the user passed in
    int num_elements = atoi( argv[1] );
    if ( num_elements <= 0 ) {
        printf( "Must use a number greater than 0! Usage: %s [POSITIVE INTEGER]\n", argv[0] );
        exit( EXIT_FAILURE );
    }

    // Generate the input. The array pointer points to an array already alloced to the heap
    int * array = generate_input( num_elements );

    check_output( array, num_elements );

    // Sort the array using radixsort. This is in done in place on the heap
    radixsort(array, num_elements);

    // Print the first and last 5 elements to check if the sorting is working
    check_output( array, num_elements );

    // free and exit
    free( array );

    return EXIT_SUCCESS;
}
