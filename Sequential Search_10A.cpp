#include <iostream>
using namespace std;

// Sequential Search
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    // Sequential Search
    int seqIndex = sequentialSearch(arr, n, key);
    cout << "Sequential Search Index: " << seqIndex << endl;

    // Binary Search
    int binIndex = binarySearch(arr, 0, n - 1, key);
    cout << "Binary Search Index: " << binIndex << endl;

    return 0;
}
