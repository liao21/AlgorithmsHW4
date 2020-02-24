# Algorithms Homework 4 -- Part A
### Authors: Philip Robinson, Hayden Liao

## Sorting algorithms completed:

* quicksort A
  radixsort A

## Included:

* **sortlib**
  * **Files:** *sortlib.c / sortlib.h*
  * **Description:** contains all the important common functions for sorting, i.e. generating random list of specific length, printing first and last 5 elements
  * **Functions:**
    * `generate_random_num`
      * params: *int* num_elements
      * return: *int*
    * `generate_input`
      * params: *int* num_elements
      * return: *int[]*
    * `check_output`
      * params: *int* * arr, *int* size
      * return: *void*

* **quicksort**
  * **Files:** *quicksort.c / quicksort.h*
  * **Description:** contains a recursive quicksort algorithm that uses a helper partition function that does the sorting
  * **Functions:**
    * `quicksort`
      * params: *int* * arr, *int* low, *int* high
      * return: *void*
    * `partition`
      * params: *int* * arr, *int* low, *int* high
      * return: *int*

* **radixsort**
  * **Files:** *radixsort.c / radixsort.h*
  * **Description:** contains quicksort algorithm which uses insertionsort as
  a stable sort for each digit
  * **Functions:**
    * `radixsort`
      * params: *int* arr[], *int* length
      * return *void*
    * `power`
      * params: *int* base *int* power
      * return *int* ret
    * `get_max`
      * params *int* arr[] *int* len
      * return *int* max
* **MAKEFILE**

## 'make' Usage:

`make all` -- makes both quicksort and radixsort

`make quicksort` -- makes quicksort

`make radixsort` -- makes radixsort
