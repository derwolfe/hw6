using namespace std;
#include <string>

#include "data_type.h"
#include "utility.h"

/* 
 * Sorts the items in an array into ascending order using the Bubble
 * sort algorithm.
 * 
 * Precondition:  theArray is an array of n items of DataType.
 * 
 * Postcondition: theArray is sorted into ascending order; n is unchanged.
 * 
 * Parameter theArray:  The given array of data items to be sorted.
 * 
 * Parameter n:  The size of theArray. 
 */
void bubbleSort(DataType theArray[], int n)
{
  bool sorted = false;  /* false when swaps occur */

  /*
   * Perform a series of passes through the data moving items out of
   * place with repsect to those around them closer to where they
   * should be in a sorted array.
   */
  for (int pass = 1; (pass < n) && !sorted; ++pass) {  
    /* Invariant: theArray[n+1-pass..n-1] is sorted and all elements
     * in this range are greater than all elements in
     * theArray[0..n-pass]
     *
     * We assume the next pass is sorted until we see otherwise by
     * finding items that must be swapped.
     */
    sorted = true;  
    for (int index = 0; index < n-pass; ++index) {  
      /*
       * Invariant: theArray[0..index-1] <= theArray[index]
       */
      int nextIndex = index + 1;
      if (theArray[index] > theArray[nextIndex]) {  
	/*
	 * The elements are out of order, and so we need to swap them
	 * and note that the array was not yet in sorted order.
	 */
	swap(theArray[index], theArray[nextIndex]);
	sorted = false;  
      }  
    }  
    /*
     * Asertion: theArray[0..n-pass-1] < theArray[n-pass]
     */
  }  
} 
