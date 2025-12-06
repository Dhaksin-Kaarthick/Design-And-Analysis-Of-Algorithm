#include <stdio.h>

#define BUCKETS 10     
#define MAX_BUCKET_SIZE 20  

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void bucketSort(int arr[], int n) {
    int buckets[BUCKETS][MAX_BUCKET_SIZE];
    int bucketCount[BUCKETS] = {0};

    int max = arr[0];

    // Find maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }


    for (int i = 0; i < n; i++) {
        int index = (arr[i] * BUCKETS) / (max + 1); // bucket index
        buckets[index][bucketCount[index]++] = arr[i];
    }

    // Sort each bucket & merge them back to original array
    int k = 0;
    for (int i = 0; i < BUCKETS; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(buckets[i], bucketCount[i]);

            // Copy from bucket to original array
            for (int j = 0; j < bucketCount[i]; j++) {
                arr[k++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int arr[] = {42, 23, 4, 16, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
