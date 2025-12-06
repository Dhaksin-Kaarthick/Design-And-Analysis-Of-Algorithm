#include <stdio.h>


void maxHeapify(int arr[], int heapSize, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && arr[left] > arr[largest])
        largest = left;
    if (right < heapSize && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        maxHeapify(arr, heapSize, largest);
    }
}

void buildMaxHeap(int arr[], int n) {

    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSortMax(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 1; i--) {
        // Move current max to end
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        // Heapify reduced heap
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {42, 23, 4, 16, 8, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSortMax(arr, n);

    printf("Sorted (ascending) using max-heap heapsort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
