#include <stdio.h>
#define LEFT -1
#define RIGHT 1
int getMobile(int p[], int d[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++)
        if ((i + d[i] >= 0 && i + d[i] < n) && p[i] > p[i + d[i]] && p[i] > mobile)
            mobile = p[i];
    return mobile;
}
int findPos(int p[], int n, int val) {
    for (int i = 0; i < n; i++)
        if (p[i] == val) return i;
    return -1;
}
void print(int p[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", p[i]);
    printf("\n");
}
void johnsonTrotter(int n) {
    int p[n], d[n];
    for (int i = 0; i < n; i++) { p[i] = i + 1; d[i] = LEFT; }
    print(p, n);
    while (1) {
        int m = getMobile(p, d, n);
        if (m == 0) break;
        int i = findPos(p, n, m), j = i + d[i];
        int t = p[i]; p[i] = p[j]; p[j] = t;
        t = d[i]; d[i] = d[j]; d[j] = t;
        for (int k = 0; k < n; k++)
            if (p[k] > m) d[k] = -d[k];
        print(p, n);
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
