#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[20];
    while (i <= mid && j <= high) {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= high)
        temp[k++] = A[j++];
    for (i = 0; i < k; i++)
        A[low + i] = temp[i];
}
void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;   
        mergeSort(A, low, mid);       
        mergeSort(A, mid + 1, high);  
        merge(A, low, mid, high);     
    }
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    mergeSort(A, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}
