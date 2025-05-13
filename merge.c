#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int l, int m, int r) {
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;

 int L[n1], R[n2];

 for (i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];

 i = 0;
 j = 0;
 k = l;

 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 } else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }

 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }

 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }
}
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
 int m = (l + (r - 1)) / 2;

mergeSort(arr, l, m);
 mergeSort(arr, m + 1, r);

 merge(arr, l, m, r);
 }
}
int main() {
 srand(time(NULL));
 int n = 10000;
 int elements[n];


 for (int i = 0; i < n; i++) {
 elements[i] = rand() % 1000;
 }

 printf("Enter the number of elements to sort: ");
 int num;
 scanf("%d", &num);

 if (num > n || num <= 0) {
 printf("Invalid input size. Please enter a number between 1 and %d\n", n);
 return 1;
 }

 int sort_arr[num];

 printf("Enter %d numbers:\n", num);
 for (int i = 0; i < num; i++) {
 scanf("%d", &sort_arr[i]);
 }


 clock_t start = clock();
 mergeSort(sort_arr, 0, num - 1);
 clock_t end = clock();


 printf("Sorted Array:\n");
 for (int i = 0; i < num; i++) {
 printf("%d ", sort_arr[i]);
 }
 printf("\nTotal time taken to sort the Input Array is: %1f seconds\n", ((double)(end - start))
/ CLOCKS_PER_SEC);


 for (int size = 500; size <= n; size += 500) {
 int arr_temp[size];
for (int i = 0; i < size; i++) {
 arr_temp[i] = elements[i];
 }

 clock_t start = clock();
 mergeSort(arr_temp, 0, size - 1);
 clock_t end = clock();

 printf("Total time taken to sort %d elements is %1f seconds\n", size, ((double)(end -
start)) / CLOCKS_PER_SEC);
 }

 return 0;
}
