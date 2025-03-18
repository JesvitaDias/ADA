#include<stdio.h>
#include<time.h>
int a[20],n;
void mergesort(int[],int,int);
void simplesort(int[],int,int,int);
void main()
{

    int i;
    clock_t start,end;
    double time;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    printf("Enter the elements ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    printf("Sorted array is: ");
    printf("Sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    time=(double)((end-start)/CLOCKS_PER_SEC);
    printf("\nTime taken is : %f", time);

}

void mergesort(int a[],int low, int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    simplesort(a,low,mid,high);
  }
}
void simplesort(int a[],int low, int mid,int high)
{
    int i=low,k=low,j=mid+1;
    int c[n];
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        c[k++]=a[i++];
    }
    while(j<=high)
    {
        c[k++]=a[j++];
    }
    for(i=low;i<=high;i++)
    {
        a[i]=c[i];
    }
}





