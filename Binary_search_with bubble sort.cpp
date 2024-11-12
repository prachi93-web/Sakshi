#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {         // Using i++ (post-increment)
        for (int j = 0; j < n - i - 1; j++) 
		//We use n - i - 1 to avoid comparing the elements that are already sorted in previous passes.
		{ // Using j++ (post-increment)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    const int n = 5; // Fixed size of the array
    int arr[n]; // Statically allocated array

    cout << "Enter " << n << " array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    // Sort the array using Bubble Sort
    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Binary Search
    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in array" << endl;
    }

    return 0;
}
//The while loop in Binary Search runs O(logn) times because it halves the search space with every iteration.
