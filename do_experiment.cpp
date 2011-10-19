#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

#include <time.h>
#include <sys/time.h>
#include <assert.h>

#include <string>

using namespace std;

#include "data_type.h"

#include "utility.h"


void do_table(sort_t sort_type, pivot_t pivot_type)
{
  DataType *data_array;
  long      elapsed_times[3][5];  /* sort_type x sample_size */
  pivot_t   pivot_selected;
  sort_t    sort_selected;
  start_t   starting_conditions;
  int       sample_sizes[5] = {100, 500, 1000, 10000, 100000};
  int       retval;

  const int number_width = 10;
  const int label_width  = 12;
  const int line_width   = label_width + 5*number_width;

  /*
   * Perform the sorts for all the combination of parameter values and
   * fill in elapsed times
   */
  /*
   * IMPLEMENT ME
   */

  /*
   * Example call to do-test - note you can use ENUMS as array indices
   */
  elapsed_time[ASCENDING_ORDER][i] = do_test(sample_sizes[i], ASCENDING_ORDER, sort_type, pivot_type);

  /*
   * Output Sort name and Column Headers
   */
  /*
   * IMPLEMENT ME
   */

  /*
   * Ascending row
   */
  /*
   * IMPLEMENT ME
   */

  /*
   * Descending Row
   */
  /*
   * IMPLEMENT ME
   */

  /*
   * Random Row
   */
  /*
   * IMPLEMENT ME
   */

}


int main(const int argc, char *argv[])
{

  if ( argc > 1 ) {
    cout << "Useage: ./do_experiment " << endl;
    exit(1);
  }

  do_table(BUBBLE_SORT, NO_PIVOT);
  do_table(INSERTION_SORT, NO_PIVOT);
  do_table(MERGE_SORT, NO_PIVOT);
  do_table(SELECTION_SORT, NO_PIVOT);
  do_table(QUICK_SORT, DEFAULT_PIVOT);
  do_table(QUICK_SORT, MEDIAN_OF_THREE_PIVOT);
  do_table(QUICK_SORT, RANDOM_PIVOT);

  exit(0);
}
