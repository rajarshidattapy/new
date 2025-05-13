#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quicksort(int a[],int low,int high);
int partition(int a[],int low,int high);
void swap(int*,int*);
void quicksort(int a[],int low,int high)
{
if(low<high)
{
int pi = partition(a,low,high);
quicksort(a,low,pi-1);
quicksort(a,pi+1,high);
}
}
void swap(int *a,int *b)
{
int c=*a;
*a=*b;
*b=c;
}
int partition(int a[],int low,int high)
{
int pivot=a[high];
int i=low-1;
for(int j=low;j<=high-1;j++)
{
if(a[j]<=pivot)
{
i++;
swap(&a[i],&a[j]);
}
}
swap(&a[i+1],&a[high]); return (i+1);
}
void main()
{
srand(time(NULL));
int a[100000],n=100000;
int elements[n];
for(int i=0;i<n;i++)
 {
 elements[i]=rand()%1000;
 }
 for(int size=5000;size<=n;size+=2000)
{
int arr[size];
for(int i=0;i<size;i++)
{
arr[i]=elements[i];
}
clock_t start=clock();
quicksort(a,0,size);
clock_t end=clock();
printf("Total time taken to sort %d elements is %lf\n",size,((double)(endstart)/CLOCKS_PER_SEC));
}
}
