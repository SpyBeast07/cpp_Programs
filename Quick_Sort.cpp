#include<iostream>
using namespace std;

int partition(int *arr, int s, int e) {
    int p = s;
    int c=0;

    for (int k=s+1; k<=e; k++) {
        if (arr[k] <= arr[p]) {
            c++;
        }
    }

    // Put pivot to its right position by swaping
    int temp = arr[p];
    arr[p] = arr[s+c];
    arr[s+c] = temp;
    p = s+c;

    // left and right part elements
    int i=s, j=e;

    while (i < p && j > p) {
        while (arr[i] <= arr[p]) {
            i++;
        }
        while (arr[j] > arr[p]) {
            j--;
        }
        if (i < p && j > p) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;j--;
        }
    }

    return p;
}

void quickSort(int *arr, int s, int e) {
    if (s >= e) {
        return;
    }

    // Partition
    int p = partition(arr, s, e);

    // Sort left part
    quickSort(arr, s, p-1);
    // Sort right part
    quickSort(arr, p+1, e);
}

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n-1);

    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}