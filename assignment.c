#include <stdio.h>
#include <limits.h>

int n;                      
int cost[10][10];          
int assigned[10];           
int minCost = INT_MAX;      

void findMinCost(int person, int currentCost) {
    if (person == n) {
        if (currentCost < minCost)
            minCost = currentCost;
        return;
    }

    for (int job = 0; job < n; job++) {
        if (!assigned[job]) {
            assigned[job] = 1;
            findMinCost(person + 1, currentCost + cost[person][job]);
            assigned[job] = 0;
        }
    }
}

int main() {
    printf("Enter number of jobs/persons: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    findMinCost(0, 0);

    printf("Minimum total cost: %d\n", minCost);
    return 0;
}
