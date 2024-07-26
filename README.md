# Algorithms Documentation

## QuickSort Algorithm
### Overview 
This C++ program implements the QuickSort algorithm, a highly efficient and widely used sorting algorithm. QuickSort follows the divide-and-conquer strategy to sort an array of integers. The algorithm selects a 'pivot' element and partitions the array into two subarrays: elements less than the pivot and elements greater than the pivot. It then recursively applies the same process to the subarrays.
### Explaination
#### Partion Function
##### Purpose:
Rearranges the elements in the array so that all elements less than the pivot are to its left and all elements greater are to its right.
##### Parameters:
- arr[]: The array to be partitioned.
- s: The starting index of the subarray.
- e: The ending index of the subarray.
##### Process:
1. Selects the last element as the pivot.
2. Iterates through the array, comparing each element with the pivot.
3. Swaps elements as needed to place elements smaller than the pivot to its left.
4. Finally, places the pivot element in its correct position.
##### Return Value: 
The index of the pivot element after partitioning.
#### QuickSort Function
##### Purpose: 
Sorts the array using the QuickSort algorithm.
##### Parameters:
- arr[]: The array to be sorted.
- s: The starting index of the subarray.
- e: The ending index of the subarray.
##### Process:
1. Calls the Partition function to get the pivot index.
2. Recursively sorts the subarrays to the left and right of the pivot.
### Complexity Analysis
#### Time Complexity
##### Best Case: 𝑂(𝑛log⁡𝑛)
When the pivot divides the array into two nearly equal halves.

##### Average Case: 𝑂(𝑛log⁡𝑛)
On average, the pivot divides the array into reasonably balanced partitions.

##### Worst Case: 𝑂(𝑛2)
When the pivot is the smallest or largest element, leading to unbalanced partitions (e.g., when the array is already sorted or reverse-sorted).

#### Space Complexity
##### Auxiliary Space: 𝑂(log𝑛)
This accounts for the space used by the recursion stack. The maximum depth of recursion is 𝑂(log𝑛) in the best case and average case. In the worst case, it can be 
𝑂(𝑛) if the recursion is highly unbalanced.
### Additional Notes

#### -> Stability: 
QuickSort is not a stable sort. Equal elements might not maintain their original relative order.

#### -> In-Place Sorting: 
QuickSort sorts the array in-place, requiring only a small, constant amount of additional memory.

---
# Insertion Sort Algorithm

## Overview
This C++ program implements the Insertion Sort algorithm, a simple and intuitive sorting algorithm that builds the final sorted array (or list) one item at a time. It is similar to how you might sort playing cards in your hands. The algorithm divides the input into a sorted and an unsorted region and repeatedly picks the next item from the unsorted region and inserts it into the correct position in the sorted region.

#### InsertionSort Function

##### Purpose:
Sorts an array of integers using the Insertion Sort algorithm.

##### Parameters:
- `array[]`: The array of integers to be sorted.
- `size`: The number of elements in the array.

##### Process:
1. **Initialization:** Start with the second element of the array (index 1) as the current element (`key`) to be inserted into the sorted portion.
2. **Inner Loop:** Compare the `key` with elements in the sorted portion (elements to the left of the current element). If the element in the sorted portion is greater than the `key`, shift the element to the right.
3. **Insertion:** Insert the `key` into its correct position in the sorted portion.
### Complexity Analysis

#### Time Complexity
- **Best Case: 𝑂(𝑛)**
  - When the array is already sorted, each key is compared with only one element.
- **Average Case: 𝑂(𝑛^2)**
  - When elements are randomly ordered, each insertion requires shifting elements.
- **Worst Case: 𝑂(𝑛^2)**
  - When the array is sorted in reverse order, each key needs to be compared with all previously sorted elements.

#### Space Complexity
- **Auxiliary Space: 𝑂(1)**
  - Insertion Sort sorts the array in-place, using a constant amount of extra memory beyond the input array.
### Additional Notes

#### Stability:
Insertion Sort is a stable sort. It maintains the relative order of equal elements.

#### In-Place Sorting:
Insertion Sort sorts the array in-place, meaning it requires no additional storage proportional to the array size.

---

## Merge Sort Algorithm in C++
### Overview
This C++ program implements the Merge Sort algorithm, a stable and efficient sorting algorithm based on the divide-and-conquer strategy. Merge Sort recursively divides the array into smaller subarrays until each subarray contains a single element. It then merges these subarrays back together in sorted order.

### Code Explanation
#### Merge Function
##### Purpose:
Merges two sorted subarrays into a single sorted subarray.

##### Parameters:
- arr: The array containing the two subarrays to be merged.
- left: The starting index of the left subarray.
- mid: The ending index of the left subarray (and the starting index of the right subarray).
- right: The ending index of the right subarray.
##### Process:
- Initialize Sizes: Determine the sizes of the left and right subarrays.
- Create Temporary Vectors: Create vectors to hold the elements of the left and right subarrays.
- Copy Data: Copy the elements from arr into the temporary vectors.
- Merge: Compare elements from the two temporary vectors and merge them back into the original array.
- Copy Remaining Elements: Copy any remaining elements from the left or right subarrays into the original array.
#### MergeSort Function
##### Purpose:
Sorts the array using the Merge Sort algorithm.

##### Parameters:
- arr: The array to be sorted.
- left: The starting index of the subarray.
- right: The ending index of the subarray.
##### Process:
- Divide: Find the middle point and recursively sort the left and right halves.
- Merge: Call the merge function to combine the sorted halves.
##### Complexity Analysis
###### Time Complexity
- Best Case: 𝑂(𝑛log𝑛)
When the array is already sorted or requires minimal merging.

Average Case: 𝑂(𝑛log⁡𝑛)
On average, the array will be divided and merged in 𝑂(𝑛log⁡𝑛) time.

Worst Case: 𝑂(𝑛log𝑛)
The time complexity remains 𝑂(𝑛log𝑛) even if the array is initially unsorted.

Space Complexity
Auxiliary Space: 𝑂(𝑛)
Merge Sort requires additional space proportional to the size of the array for temporary storage during merging. The space complexity is 𝑂(𝑛) because of the additional space used for the temporary vectors.

##### Additional Notes
-> Stability:
Merge Sort is a stable sort. It maintains the relative order of equal elements.

-> In-Place Sorting:
Merge Sort is not an in-place sort. It requires additional space for temporary vectors during the merging process.
