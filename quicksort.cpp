#include <iostream>
#include <stdlib.h>

using namespace std;
#include <string>

#include "data_type.h"
#include "utility.h"

/* Chooses a pivot for quicksort's partition algorithm and swaps it
 * with the first item in an array.
 * 
 * Precondition: theArray[first..last] is an array; first <= last.
 * Postcondition: theArray[first] is the pivot.
 * Parameter: theArray  The given array.
 * Parameter: first  The first element to consider in theArray.
 * Parameter: last  The last element to consider in theArray. 
 */
void choosePivot(DataType theArray[], int first, int last, pivot_t pivot_choice)
{
  int range;
  
  range = last - first; // stores the size of the array

  /*
   * Taking no action chooses the first item as the pivot 
   */
  if ( pivot_choice == MEDIAN_OF_THREE_PIVOT) {
    if ( range < 3 ) {
      ; // do nothing
    } else {
      int middle = first + last / 2;
      if ( middle > first ) {
        swap ( middle, first );
      }
      if ( first > last ) {
        swap ( first, last );
      }
      if ( middle > last ) {
        swap ( middle, last );
       }

    /*
     * find the median of the first, middle, and last elements
     */
    }
  }

  if ( pivot_choice == RANDOM_PIVOT) {
    /*
     * Generate a random number using current time as a seed
     * then, to make sure the number falls inside the range, 
     * take the modulo of the number and add 1, to account for 
     * the index.
     * 
     * Then swap the first and randomly indexed values.
     */
    int random_index;
    srand( time(NULL) );
    random_index = ( rand () % range ) + 1;
    swap( theArray[first], theArray[random_index] );
  }

  return; 
}

/*
 * Partitions an array for quicksort.
 *
 * Precondition: theArray[first..last] is an array; first <= last.
 * Postcondition:
 *
 * Partitions theArray[first..last] such that:
 *    S1 = theArray[first..pivotIndex-1] <  pivot
 *         theArray[pivotIndex]          == pivot
 *    S2 = theArray[pivotIndex+1..last]  >= pivot
 *
 * Parameter: theArray  The given array.
 * Parameter: first  The first element to consider in theArray.
 * Parameter: last  The last element to consider in theArray.
 * Parameter: pivotIndex  The index of the pivot after partitioning. 
 */
void partition(DataType theArray[],
               int first, int last, int& pivotIndex, pivot_t pivot_choice)
{
  /*
   * place pivot in theArray[first]
   */
  choosePivot(theArray, first, last, pivot_choice);
  DataType pivot = theArray[first];     /* copy pivot */

  // initially, everything but pivot is in unknown
  int lastS1 = first;           /* index of last item in S1 */
  int firstUnknown = first + 1; /* index of first item in */
                                /* unknown */

  /*
   * move one item at a time until unknown region is empty
   */
  for (; firstUnknown <= last; ++firstUnknown) {  
    /*
     * Invariant: theArray[first+1..lastS1] < pivot	  
     *         theArray[lastS1+1..firstUnknown-1] >= pivot
     */
    
    /*
     * move item from unknown to proper region
     */
    if (theArray[firstUnknown] < pivot) {  
      /*
       * item from unknown belongs in S1
       */
      ++lastS1;
      swap(theArray[firstUnknown], theArray[lastS1]);
    }  
    /*
     * else item from unknown belongs in S2
     */
  }  

  /*
   * place pivot in proper position and mark its location
   */
  swap(theArray[first], theArray[lastS1]);
  pivotIndex = lastS1;
}  

/** Sorts the items in an array into ascending order.
 * Precondition: theArray[first..last] is an array.
 * Postcondition: theArray[first..last] is sorted.
 * Parameter: theArray  The given array.
 * Parameter: first  The first element to consider in theArray.
 * parameter: last  The last element to consider in theArray. 
 */
void quicksort(DataType theArray[], int first, int last, pivot_t pivot_choice)
{
  int pivotIndex;

  if (first < last) {  
    /*
     * create the partition: S1, pivot, S2
     */
    partition(theArray, first, last, pivotIndex, pivot_choice);

    /*
     * sort regions S1 and S2
     */
    quicksort(theArray, first, pivotIndex-1, pivot_choice);
    quicksort(theArray, pivotIndex+1, last, pivot_choice);
  }  
} 

