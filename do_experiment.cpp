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
  const int data_size    = 4;

  /*
   * Perform the sorts for all the combination of parameter values and
   * fill in elapsed times
   */
  /*
   * IMPLEMENT ME: each algorithm will need to test each sample size, 
   * so that is 5*3 per set
   */
  for (int i = 0; i <= 4; i++) {
    elapsed_times[ASCENDING_ORDER][i] = do_test( sample_sizes[i], ASCENDING_ORDER, sort_type, pivot_type);
    elapsed_times[DESCENDING_ORDER][i] = do_test( sample_sizes[i], DESCENDING_ORDER, sort_type, pivot_type);
    elapsed_times[RANDOM_ORDER][i] = do_test( sample_sizes[i], RANDOM_ORDER, sort_type, pivot_type);
  }
  /*
   * Example call to do-test - note you can use ENUMS as array indices
   */
  //elapsed_times[ASCENDING_ORDER][i] = do_test(sample_sizes[i], ASCENDING_ORDER, sort_type, pivot_type);

  /*
   * Output Sort name and Column Headers
   *
   * Also, make alternate output statements to create a CSV to throw to excel.
   */
  cout << endl;
  cout << sort2string(sort_type) << " Results" << endl;
  /* only add pivot information if there is a pivot */
  if (pivot_type != NO_PIVOT) {
    cout << pivot2string(pivot_type) << endl;
  }
  /* make the line of dashes
   */
  cout << setfill('-') << setw(line_width) << '-' << endl;
  cout << setfill(' ');
  /* then reset the fill 
   * 
   * Set up the headings for the table
   */

  int index = 0;
  while ( index < data_size ) { 
    cout << setw(label_width) << left << "Initial";
    for (int i = 0; i <= 4; i++) {
      cout << setw(number_width) <<  sample_sizes[index]; 
      index++;
      if ( index >= data_size ) {
        cout << endl << endl;
        break;
      }
    }
  }
  

  /*
   * Ascending row data
   */
  index = 0;
  while ( index < data_size ) { 
    cout << setw(label_width) << "Ascending";
    for (int i = 0; i <= 4; i++) {
      cout << setw(number_width) << elapsed_times[ASCENDING_ORDER][index]; 
      index++;
      if ( index >= data_size ) {
        cout << endl << endl;
        break;
      }
    }
  }

  /*
   * Descending Row
   */
  index = 0;
  while ( index < data_size ) { 
    cout << setw(label_width) << "Descending";
    for (int i = 0; i <= 4; i++) {
      cout << setw(number_width) << elapsed_times[DESCENDING_ORDER][index]; 
      index++;
      if ( index >= data_size ) {
        cout << endl << endl;
        break;
      }
    }
  }

  /*
   * Random Row
   */
  index = 0;
  while ( index < data_size ) { 
    cout << setw(label_width) << "Random";
    for (int i = 0; i <= 4; i++) {
      cout << setw(number_width) << elapsed_times[RANDOM_ORDER][index]; 
      index++;
      if ( index >= data_size ) {
        cout << endl << endl;
        break;
      }
    }
  }
}


int main(const int argc, char *argv[])
{

  if ( argc > 1 ) {
    cout << "Useage: ./do_experiment " << endl;
    exit(1);
  }

  do_table(BUBBLE_SORT, NO_PIVOT);
//  do_table(INSERTION_SORT, NO_PIVOT);
//  do_table(MERGE_SORT, NO_PIVOT);
//  do_table(SELECTION_SORT, NO_PIVOT);
//  do_table(QUICK_SORT, DEFAULT_PIVOT);
//  do_table(QUICK_SORT, MEDIAN_OF_THREE_PIVOT);
//  do_table(QUICK_SORT, RANDOM_PIVOT);
  
  exit(0);
}
