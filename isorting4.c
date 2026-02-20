#include<stdio.h>
void printarray (int *a, int n){
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void insertionsort(int *a, int n){
    for (int i = 0; i<=n-1; i++){ // no. of passes
        int key=a[i];
        int j=i-1;
        while (j>0 && a[j] > key){ //for each pass
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main() {
    int a[] = {12, 78, 56, 72, 67, 23};
    int n = 6;
    printarray(a, n);
    insertionsort(a,n);
    printarray(a,n);
    return 0;
}