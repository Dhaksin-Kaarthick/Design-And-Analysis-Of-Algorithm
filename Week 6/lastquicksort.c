//CH.SC.U4CSE24115

#include <stdio.h>

int partition_last(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quicksort_last(int a[], int low, int high) {
    if (low < high) {
        int p = partition_last(a, low, high);
        quicksort_last(a, low, p - 1);
        quicksort_last(a, p + 1, high);
    }
}

int main() {
    int a[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    quicksort_last(a, 0, n - 1);

    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
