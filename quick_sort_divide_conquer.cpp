#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int P = low + 1;
    int Q = high;
    while (P <= Q) {
        while (P <= high && arr[P] <= pivot)
            P++;
        while (arr[Q] > pivot)
            Q--;

        if (P < Q)
            swap(arr[P], arr[Q]);
    }
    swap(arr[low], arr[Q]);
    return Q;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}