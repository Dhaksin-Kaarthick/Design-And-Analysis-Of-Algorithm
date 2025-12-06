#include <stdio.h>


void minHeapify(int arr[], int heapSize, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && arr[left] < arr[smallest])
        smallest = left;
    if (right < heapSize && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        int tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;
        minHeapify(arr, heapSize, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void heapSortMin(int arr[], int n) {
    buildMinHeap(arr, n);
    for (int i = n - 1; i >= 1; i--) {

        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {42, 23, 4, 16, 8, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSortMin(arr, n);

    printf("Sorted (descending) using min-heap heapsort:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
