#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

using namespace std;

#include "data_type.h"
#include "utility.h"

extern void bubbleSort(DataType theArray[], int n);
extern void insertionSort(DataType theArray[], int n);
extern void mergesort(DataType theArray[], int first, int last);
extern void quicksort(DataType theArray[], int first, int last, pivot_t pivot_choice);
extern void selectionSort(DataType theArray[], int n);

/* Swaps two items.
 * Precondition: x and y are the items to be swapped.
 * 
 * Postcondition: Contents of actual locations that x and y represent
 *   are swapped.
 *       
 * Parameter x:  Given data item.
 * Parameter y:  Given data item. 
 */
void swap(DataType& x, DataType& y)
{
   DataType temp = x;
   x = y;
   y = temp;
}  


sort_t classify_sort_arg(const string &in_str)
{
  if ( in_str.compare("bubble") == 0 ) {
    return (BUBBLE_SORT);
  } else if ( in_str.compare("insertion") == 0 ) {
    return (INSERTION_SORT);
  } else if ( in_str.compare("merge")  == 0) {
    return (MERGE_SORT);
  } else if ( in_str.compare("quick")  == 0) {
    return (QUICK_SORT);
  } else if ( in_str.compare("selection")  == 0) {
    return (SELECTION_SORT);
  } else {
    cout << "ERROR: unrecognized sort algorithm name: " << in_str << endl;
  }
}

string sort2string(sort_t sort_val)  
{
  switch (sort_val) {
  case BUBBLE_SORT:
    return string("Bubble");
    break;

  case INSERTION_SORT:
    return string("Insertion");
    break;

  case MERGE_SORT:
    return string("Merge");
    break;

  case QUICK_SORT:
    return string("Quick");
    break;

  case SELECTION_SORT:
    return string("Selection");
    break;

  default:
    return string("Unknown Sort Type");
  }

}

start_t classify_start_arg(const string &in_str)
{
  if ( in_str.compare("ascending") == 0 ) {
    return (ASCENDING_ORDER);
  } else if ( in_str.compare("descending") == 0 ) {
    return (DESCENDING_ORDER);
  } else if ( in_str.compare("random")  == 0) {
    return (RANDOM_ORDER);
  } else {
    cout << "ERROR: unrecognized starting condition name: " << in_str << endl;
  }
}

string start2string(start_t start_val)
{
  switch (start_val) {
  case ASCENDING_ORDER:
    return string("Ascending");
    break;

  case DESCENDING_ORDER:
    return string("Descending");
    break;

  case RANDOM_ORDER:
    return string("Random");
    break;

  default:
    return string("Unknown Start Type");
  }
}

pivot_t classify_pivot_arg(const string &in_str)
{
  if ( in_str.compare("mo3") == 0 ) {
    return (MEDIAN_OF_THREE_PIVOT);
  } else if ( in_str.compare("random") == 0 ) {
    return (RANDOM_PIVOT);
  } else if ( in_str.compare("default") == 0 ) {
    return (DEFAULT_PIVOT);
  } else {
    cout << "ERROR: unrecognized pivot type: " << in_str << endl;
  }
}

string pivot2string(pivot_t pivot_val)
{
  switch (pivot_val) {
  case MEDIAN_OF_THREE_PIVOT:
    return string("Median of 3");
    break;

  case RANDOM_PIVOT:
    return string("Random");
    break;

  case DEFAULT_PIVOT:
    return string("Default");
    break;

  case NO_PIVOT:
    return string("No Pivot");
    break;

  default:
    return string("Unknown Pivot Type");
  }
}

DataType *create_data_set(int sample_size, start_t starting_conditions)
{
  DataType *data_array;
  int descender = sample_size;
  /* I am allocating to the heap for testing. Though, I am not sure 
   * where I should be deallocating.
   */ 
  data_array = new DataType[sample_size];

  /*
   * Determine the Starting Conditions and fill in the initial data
   * acccordingly
   */
  switch (starting_conditions) {
    case ASCENDING_ORDER:
      for ( int i = 0; i <= sample_size; i++ ) {
       data_array[i]  = i; 
      }
      return data_array;
      break;

    case DESCENDING_ORDER:
        /* [0] == sample size, then sample_size-- for i++
         */
      for ( int i = 0; i <= sample_size; i++ ) {
        data_array[i] = descender--;
      }
      return data_array;
      break;

    case RANDOM_ORDER:
        /* Use the random number generator and fill up the array
         * with all of them.
         */
      srand( time(NULL) );
      for (int i = 0; i <= sample_size; i++) {
        data_array[i] = ( rand() % sample_size ) + 1;
      //  cout << data_array[i] << endl;
      } 
      return data_array;
      break;
     
    default:
      cout <<" ERROR: unknown starting condition type return value" << endl;
    }

  return data_array;
}

/*
 * A constant and a utility routine to help with time calculations
 */
const int  MICROSECONDS_PER_SECOND = 1000000;

int microsecond_difference(struct timeval *start, struct timeval *stop)
{
  int elapsed_microseconds;

  if ( start->tv_sec > stop->tv_sec ) {
    cout << "ERROR: the start seconds is greater than the stop seconds!" << endl;
    return 0;
  }

  /*
   * Several subcases are more easily handled individually
   */
  if ( start->tv_sec == stop->tv_sec) {
    /*
     * It all happened within the same second, so the elapsed
     * micorseconds is just the difference between the two microsecond
     * values.
     */
    elapsed_microseconds = stop->tv_usec - start->tv_usec;
  } else if ( start->tv_sec == (stop->tv_sec - 1) ) {
    /*
     * The seconds rolled over only once the elapsed is just the
     * number of micorsedconds from the start to the rollover, plus
     * the number from the rollover to the stop value.
     */
    /*
     * IMPLEMENT ME
     */
  } else {
    /*
     * The seconds rooled over more than once, so figure the offsets
     * as before for the fractional seconds on either end, but then
     * add in the full seconds worth for those in between.
     *
     * Yes, we could combine this case with the roll-over once case,
     * but I think this is clearer code. YMMV.
     */
    /*
     * IMPLEMENT ME
     */
  }

  return elapsed_microseconds;
}

/*
 * Conduct a test. Measure the time for a sort. return the number of
 * microseconds required to do the sort.
 */
int do_test(int sample_size, start_t starting_conditions, 
            sort_t sort_selected, pivot_t pivot_selected)
{
  int *data_array;
  int  elapsed_microseconds;
  int  ret_val;

  /*
   * Structs to store start and stop times as returned by
   * gettimeofday().
   */
  struct timeval start;
  struct timeval stop;

  /*
   * Create an array of integers big enough to hold the desired data,
   * and fill it with data according tot he specified starting
   * conditions.
   */
  data_array = create_data_set(sample_size, starting_conditions);

  /*
   * Now, grab a time stamp right before performing the sort, and
   * right after.
   */
  gettimeofday(&start, NULL); 
  
  switch (sort_selected) { 
    case BUBBLE_SORT:  
      bubbleSort(data_array, sample_size); 
      break; 
    case INSERTION_SORT:
      insertionSort(data_array, sample_size);
      break;
    case MERGE_SORT:
      mergesort(data_array, data_array[0], data_array[sample_size]);
      break;
/* 
 * figure out the implementation of quick sort and how 
 * the pivot should be chosen.
 */

//    case QUICK_SORT:
//      choosePivot(data_array,
//          data_array[0],
//          data_array[sample_size - 1];
//          
//      quicksort(data_array, 
//          data_array[1], 
//          data_array[sample_size],

    case SELECTION_SORT:
      selectionSort(data_array, sample_size);
      break;
  /* 
   * Slap the stopwatch at the end of the run
   */
    default:
      cout << "ERROR: unknown sort type" << endl;
      break;
  }
  gettimeofday(&stop, NULL);
  /*
   * IMPLEMENT ME
   */

  /*
   * Figure out the elapsed time between the two, in micorseconds, and
   * return the value to the calling context.
   */
  elapsed_microseconds = microsecond_difference(&start, &stop);
  return elapsed_microseconds;
}

