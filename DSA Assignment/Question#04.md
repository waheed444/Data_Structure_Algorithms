## Question # 04)
### The Quick Sort Algorithm sorts an array by recursively partitioning it into subarrays. Here's a breakdown of the steps, assuming the pivot is always the first element:
#### 1. Partitioning:

- a. Choose a pivot: In this case, we'll use the first element of the array as the pivot.

- b. Partition the array: Rearrange the array so that all elements smaller than the pivot are placed before the pivot, and all elements greater than the pivot are placed after it. This leaves the pivot in its final sorted position.
### 2. Recursion:
- a. Left Subarray: Recursively apply the Quick Sort algorithm to the subarray containing elements smaller than the pivot.

- b. Right Subarray: Recursively apply the Quick Sort algorithm to the subarray containing elements larger than the pivot.

Example (Using your array):

Initial Array: [54, 26, 93, 17, 77, 31, 44, 55, 20]

#### Step 1: Partitioning (Pivot = 54)

- Pointers: Left Pointer starts at 26, Right Pointer starts at 20
- Swaps:
Left finds 93 (greater than 54), Right finds 20 (smaller than 54). Swap. [54, 20, 93, 17, 77, 31, 44, 55, 26]
Left finds 17 (smaller than 54), Right finds 26 (smaller than 54). Swap. [54, 20, 26, 17, 77, 31, 44, 55, 93]
Pointers cross. Swap 26 (right pointer) with the pivot (54). [26, 20, 54, 17, 77, 31, 44, 55, 93]
- Result: Pivot is in place (sorted position).

#### Step 2: Recursion:

- Left Subarray: [26, 20, 54] - Recursively sort this subarray
- Right Subarray: [17, 77, 31, 44, 55, 93] - Recursively sort this subarray
Continue recursively partitioning and sorting the subarrays until the entire array is sorted.

```cpp Pragram
#include <iostream>
using namespace std;
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```


