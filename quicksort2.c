#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void quicksort(int[], int, int);
int partition(int[], int, int);

void main() {
    int n, i, a[MAX];
    clock_t start, end;
    int ch = 1;

    while (ch) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            a[i] = rand() % 200;
        }

        printf("Randomly created array is: ");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }


        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\nSorted array is ");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }


        printf("\nTime taken is %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

        printf("Do you want to continue or stop?0/1: ");
        scanf("%d", &ch);
    }
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int i = low + 1, j = high;
    int key = a[low], temp;

    while (i <= j) {
        while (i <= high && a[i] <= key) {
            i++;
        }
        while (a[j] > key) {
            j--;
        }

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }

    return j;
}

