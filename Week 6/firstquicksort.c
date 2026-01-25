//CH.SC.U4CSE24115
#include <stdio.h>

int partition_first(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    a[low] = a[j];
    a[j] = pivot;
    return j;
}

void quicksort_first(int a[], int low, int high) {
    if (low < high) {
        int p = partition_first(a, low, high);
        quicksort_first(a, low, p - 1);
        quicksort_first(a, p + 1, high);
    }
}
