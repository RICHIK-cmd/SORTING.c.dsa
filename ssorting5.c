#include<stdio.h>

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}
void ssort(int *a, int n) {
    int indmin;
    printf("RUNNING SELECTION SORT.....\n");
    for(int i=0;i<n-1;i++){
        indmin=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[indmin])
            indmin=j;
        }
        int temp=a[i];
        a[i]=a[indmin];
        a[indmin]=temp;
     }
}
int main(){
    int a[]={5, 61, 39, 90, 26, 7};
    int n=6;
    printArray(a, n);
    ssort(a,n);
    printArray(a, n);
    return 0;
}