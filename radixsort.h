/* radixsort.h -- running radixsort on a randomly generated list.
 * Authors: Philip Robinson, Hayden Liao
 */

#ifndef RADIXSORT_H_
#define RADIXSORT_H_

void radixsort(int arr[],int n,int maxx);
void countsort(int arr[], int length, int place);
int* insertionsort_radix(int arr[], int length, int mod);
int get_max(int arr[], int len);

#endif
