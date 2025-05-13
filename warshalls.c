#include<stdio.h>
#include<time.h>

int a[10][10],D[10][10],n;
void warshal(int [][10],int);
int main()
{
    clock_t start,end;
printf("Enter the no. of vertices:");
scanf("%d",&n);
printf("Enter the cost adjacency matrix:\n");
int i,j;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
}
}
start=clock();
warshal(a,n);
end=clock();
printf("Distance Matrix:\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d ",D[i][j]);
}
printf("\n");
}
printf("Time complexity is : %f", (end-start)/CLK_TCK);
return 0;
}

void warshal(int a[][10],int n){
int i,j,k;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
D[i][j]=a[i][j];
}
}

for(k=0;k<n;k++){
for(i=0;i<n;i++){
for(j=0;j<n;j++){
        if(D[i][k]==1 && D[k][j]==1)
        {
            D[i][j]=1;
        }

}
}
}
}




