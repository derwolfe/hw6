using namespace std;
#include <string>

#include "data_type.h"
#include "utility.h"

/*
 * Finds the largest item in an array.
 *
 * Precondition: theArray is an array of size items, size >= 1.
 * Postcondition: None.
 * Parameter: theArray  The given array.
 * Parameter: size  The number of elements in theArray.
 * Return: The index of the largest item in the array. The
 *          arguments are unchanged. 
 */
int indexOfLargest(const DataType theArray[], int size)
{
  int indexSoFar = 0;  // index of largest item
  /*
   * found so far
   */
  for (int currentIndex = 1; currentIndex < size; ++currentIndex) {  
    /*
     * Invariant: theArray[indexSoFar] >=    
     *            theArray[0..currentIndex-1]
     */
    if (theArray[currentIndex] > theArray[indexSoFar]) {
      indexSoFar = currentIndex;
    }
  } 

  /*
   * index of largest item
   */
  return indexSoFar;  
}

/*
 * Sorts the items in an array into ascending order.
 * Precondition:  theArray is an array of n items.
 * Postcondition: The array theArray is sorted into 
 *                ascending order; n is unchanged.
 * Parameter: theArray  The array to sort.
 * Parameter: n  The size of theArray. 
 */
void selectionSort(DataType theArray[], int n)
{
  /*
   * last = index of the last item in the subarray of  
   *        items yet to be sorted,		       
   * largest = index of the largest item found         
   */
  for (int last = n-1; last >= 1; --last) {  
    /*
     * Invariant: theArray[last+1..n-1] is sorted and
     * > theArray[0..last]                           
     *
     * select largest item in theArray[0..last]
     */
    int largest = indexOfLargest(theArray, last+1);

    /*
     * swap largest item theArray[largest] with
     * theArray[last]                           
     */
    swap(theArray[largest], theArray[last]);
  }  
}  

