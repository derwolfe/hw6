#include <iostream>
#include <stdlib.h>
#include <fstream>

#include <time.h>
#include <sys/time.h>
#include <assert.h>

#include <string>

using namespace std;

#include "data_type.h"

#include "utility.h"


int main(const int argc, char *argv[])
{
  DataType *data_array;
  int       elapsed_time;
  pivot_t   pivot_selected;
  sort_t    sort_selected;
  start_t   starting_conditions;
  int       sample_size;
  int       retval;

  if ( argc < 4 ) {
    cout << "Useage: ./complexity_tester <sample-size> <random|ascending|descending> <selection|insertion|bubble|merge|quick> <pivot-method>" << endl;
    exit(1);
  }

  /*
   * Convert command line arguments to more convenient enum type
   * values
   */
  sample_size         = atoi(argv[1]);
  starting_conditions = classify_start_arg(argv[2]);
  sort_selected       = classify_sort_arg(argv[3]);

  if ( sort_selected == QUICK_SORT ) {
    if ( argc < 5 ) {
      cout << "You must specify a pivot method default, mo3 or random when specifying quicksort" << endl;
      cout << "Useage: ./complexity_tester <sample-size> <random|ascending|descending> <selection|insertion|bubble|merge|quick> <pivot-method>" << endl;
      exit(1);
    }
    pivot_selected = classify_pivot_arg(argv[4]);
  } else {
    pivot_selected = NO_PIVOT;
  }

  /*
   * Declare Test Conditions
   */
  cout << "Sort Type  : " << sort2string(sort_selected) << endl;
  if ( sort_selected == QUICK_SORT ) {
    cout << "    Pivot  : " << pivot2string(pivot_selected) << endl;
  }
  cout << "Start Order: " << start2string(starting_conditions) << endl;
  cout << "Sample Size: " << sample_size << endl;

  /*
   * Now, actually do a test
   */
  elapsed_time = do_test(sample_size, starting_conditions, sort_selected, pivot_selected);
  cout << "Elapsed    : " << elapsed_time << endl;
  cout << endl;

  exit(0);
}
