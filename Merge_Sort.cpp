#include<iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = (s+e)/2;

    // length of the two arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Making 2 arrays left and right
    int *first = new int[len1];
    int *second = new int[len2];

    // Copying the data of array into left and right array
    int k = s;
    for (int i=0; i<len1; i++) {
        first[i] = arr[k++];
    }

    k = mid+1;
    for (int i=0; i<len2; i++) {
        second[i] = arr[k++];
    }

    // Merge 2 sorted arrays 
    int index1 = 0;
    int index2 = 0;
    k = s;

    // while loop until index reaches to the end of arrays
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[k++] = first[index1++];
        }
        else {
            arr[k++] = second[index2++];
        }
    }

    // Check for the remaining elements in both the arrays
    while (index1 < len1) {
        arr[k++] = first[index1++];
    }

    while (index2 < len2) {
        arr[k++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }

    // finding the mid of the array
    int mid = (s+e)/2;

    // Calling merge sort for the left part
    mergeSort(arr, s, mid);
    // Calling merge sort for the right part
    mergeSort(arr, mid+1, e);

    // Merging the right and the left part
    merge(arr, s, e);
}

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n-1);

    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}