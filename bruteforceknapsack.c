#include <stdio.h>
#define MAX_ITEMS 10
int knapsack(int weights[], int values[], int n, int capacity) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    if (weights[n - 1] > capacity) {
        return knapsack(weights, values, n - 1, capacity);
    } else {
        int include = values[n - 1] + knapsack(weights, values, n - 1, capacity - weights[n - 1]);
        int exclude = knapsack(weights, values, n - 1, capacity);
        return (include > exclude) ? include : exclude;
    }
}
int main() {
    int weights[MAX_ITEMS], values[MAX_ITEMS];
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter weights of items: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter values of items: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    int maxValue = knapsack(weights, values, n, capacity);
    printf("The maximum value that can be obtained is: %d\n", maxValue);
    return 0;
}
