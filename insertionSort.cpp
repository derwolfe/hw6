using namespace std;
#include <string>

#include "data_type.h"
#include "utility.h"

/* Sorts the items in an array into ascending order.
 * @pre theArray is an array of n items.
 * @post theArray is sorted into ascending order; n is unchanged.
 * @param theArray  The given array.
 * @param n  The size of theArray. 
 */
void insertionSort(DataType theArray[], int n)
{
  /*
   * unsorted = first index of the unsorted region,
   * loc = index of insertion in the sorted region,
   * nextItem = next item in the unsorted region    
   */

  /*
   * Initially, sorted region is theArray[0], unsorted region is
   * theArray[1..n-1]. In general, sorted region is
   * theArray[0..unsorted-1], unsorted region is
   * theArray[unsorted..n-1]
   */
   for (int unsorted = 1; unsorted < n; ++unsorted) {  

     /*
      * Invariant: theArray[0..unsorted-1] is sorted
      *
      * Find the right position (loc) in theArray[0..unsorted] for
      *	theArray[unsorted], which is the first item in the unsorted
      *	region; shift, if necessary, to make room
      */
      DataType nextItem = theArray[unsorted];
      int loc = unsorted;

      for (  ; (loc > 0) && (theArray[loc-1 ]> nextItem) ; --loc) {
 	/*
	 * Shift theArray[loc-1] to the right
	 */
         theArray[loc] = theArray[loc-1];
      }

      /*
       * Assertion: theArray[loc] is where nextItem belongs
       *
       * Insert nextItem into Sorted region
       */
      theArray[loc] = nextItem;
   }  
}  
