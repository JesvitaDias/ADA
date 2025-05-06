#include <stdio.h>

int matrix[25][25], visited[10], n, cost = 0;

int tsp(int city) {
    int next = -1, min = 999, i;
    for(i = 0; i < n; i++) {
        if(matrix[city][i] && !visited[i]) {
            int total = matrix[city][i] + matrix[i][0];
            if(total < min) {
                min = total;
                next = i;
            }
        }
    }
    if(next != -1) cost += matrix[city][next];
    return next;
}

void find_min_cost(int city) {
    printf("%d ", city + 1);
    visited[city] = 1;
    int next = tsp(city);
    if(next == -1) {
        printf("%d", 1);
        cost += matrix[city][0];
        return;
    }
    find_min_cost(next);
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }

    printf("Path: ");
    find_min_cost(0);
    printf("\nMinimum cost: %d\n", cost);
    return 0;
}
