//CH.SC.U4CSE24115
#include <stdio.h>
int partition_middle(int a[], int low, int high) {
    int mid = (low + high) / 2;

    int temp = a[low];
    a[low] = a[mid];
    a[mid] = temp;

    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[low] = a[j];
    a[j] = pivot;

    return j;
}

void quicksort_middle(int a[], int low, int high) {
    if (low < high) {
        int p = partition_middle(a, low, high);
        quicksort_middle(a, low, p - 1);
        quicksort_middle(a, p + 1, high);
    }
}

int main() {
    int a[] = {25, 17, 31, 13, 2, 40, 9};
    int n = sizeof(a) / sizeof(a[0]);

    quicksort_middle(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
