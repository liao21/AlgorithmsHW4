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


#define RANGE 10 //because we're in base 10

// https://www.hackerearth.com/practice/algorithms/sorting/radix-sort/tutorial/
void countsort(int arr[],int n,int place)
{
  int i,freq[RANGE]={0};
  int output[n];
  for(i=0;i<n;i++)
    // occur: frequency of arr[i]: freq[(arr[i]/place)%RANGE]
    freq[(arr[i]/place)%RANGE]++;
  for(i=1;i<RANGE;i++)
    //make freq array cumulative
    //occur represents # elements that should be before arr[i]
    freq[i]+=freq[i-1];
  for(i=n-1;i>=0;i--) {

    // put arr[i] right before the occur spot in output
      //the -1 accounts for being 0 indexed
    output[freq[(arr[i]/place)%RANGE]-1]=arr[i];
    //decrement occur so the next occurance of this number goes to a before ^^^ this one
    //since the for loop is backwards, this countsort is stable
    freq[(arr[i]/place)%RANGE]--;
  }
  //copy output into the array
  for(i=0;i<n;i++){
    arr[i]=output[i];
  }
}
void radixsort(int arr[],int n,int maxx)  //maxx is the maximum element in the array
{
  int place=1;
  for(int max=maxx; max>0; max/=10){
    countsort(arr,n,place);
    place*=10;
  }
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

    // check_output( array, num_elements );

    int maxx = get_max(array, num_elements);
    // Sort the array using radixsort. This is in done in place on the heap
    radixsort(array, num_elements, maxx);

    // Print the first and last 5 elements to check if the sorting is working
    // check_output( array, num_elements );

    // free and exit
    free( array );

    return EXIT_SUCCESS;
}
