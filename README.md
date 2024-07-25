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

