/* sortlib.h -- The common list tools to generate a list of random integers and check the output
 * Authors: Philip Robinson, Hayden Liao
 */

#ifndef SORTLIB_H_
#define SORTLIB_H_

#define LIST_MAX 100

int generate_random_num(int max_val);
int * generate_input(int num_elements);
void check_output(int * arr, int size);

#endif
