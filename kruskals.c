#include<stdio.h>
int sum,t[10][2],cost[10][10];
void kruskals(int cost[10][10],int n);
int find(int parent[10],int i);
void main()
{
    int i,j,n,cost[10][10];
    printf("Enter the number of vertices \n");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix  \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d ",&cost[i][j]);
        }
    }
    kruskals(cost,n);
    printf("Edges of MST are:  ");
    for(i=0;i<n-1;i++)
    {
        printf("(%d,%d) ",t[i][0],t[i][1]);
    }
    printf("\nSum of edges of MST is %d ",sum);
}


void kruskals(int cost[10][10], int n) {
int min, u, v, count, k;
int parent[10];
k = 0;
sum = 0;

for (int i = 0; i<n; i++) {
parent[i] = i;
}
count = 0;
while (count<n - 1) {
min = 999;
u = -1;
v = -1;

for (int i = 0; i<n; i++) {
for (int j = 0; j<n; j++) {
if (find(parent, i) != find(parent, j) && cost[i][j]<min) {
min = cost[i][j];
u = i;
v = j;
}
}
}

int root_u = find(parent, u);
int root_v = find(parent, v);

if (root_u != root_v) {
parent[root_u] = root_v;
t[k][0] = u;
t[k][1] = v;
sum += min;
k++;
count++;
}
}
}
int find(int parent[10], int i) {
while (parent[i] != i) {
i = parent[i];
}
return i;
}


