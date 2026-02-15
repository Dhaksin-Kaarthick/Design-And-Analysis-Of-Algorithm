//CH.SC.U4CSE24115
#include <stdio.h>

int jobs(int p[], int d[], int n) {
    for (int i = 0; i < n; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] > p[max]) {
                max = j;
            }
        }
        int temp = p[max];
        p[max] = p[i];
        p[i] = temp;

        temp = d[max];
        d[max] = d[i];
        d[i] = temp;
    }

    int t[n + 1];   
    for (int i = 0; i <= n; i++) {
        t[i] = 0;
    }

    int profit = 0;

    for (int i = 0; i < n; i++) {
        if (t[d[i]] == 0) {
            t[d[i]] = 1;
            profit += p[i];
        }
        else {
            continue;
        }
    }

    return profit;
}

int main() {
    int a;

    printf("Enter the number of profits: ");
    scanf("%d", &a);

    int p[a], d[a];

    for (int i = 0; i < a; i++) {
        printf("Enter the p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < a; i++) {
        printf("Enter the d[%d]: ", i);
        scanf("%d", &d[i]);
    }

    int profits = jobs(p, d, a);
    printf("The total profit is: %d\n", profits);
    return 0;
}