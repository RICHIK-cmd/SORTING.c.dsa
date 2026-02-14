#include<stdio.h>
void printArray(int* a, int n){
    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void bubblesort(int *a, int n){
    for(int i=0;i<n-1;i++)//for number of passes
    {
        for(int j=0;j<n-1-i;j++){ //for comparison in each pass
        if(a[j]>a[j+1]){
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        }
    } 
}
int main() {
    int a[] = {12,23,67,34,5,6};
    int n = 6;
    printArray(a,n);// printing the unsorted array
    bubblesort(a,n);//function oto sort the array
    printArray(a,n);//printing the sorted array
    return 0;
}