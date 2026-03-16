#include <stdio.h>

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int heap[], int n, int i){
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && heap[l]<heap[smallest])
        smallest=l;

    if(r<n && heap[r]<heap[smallest])
        smallest=r;

    if(smallest!=i){
        swap(&heap[i],&heap[smallest]);
        heapify(heap,n,smallest);
    }
}

void buildHeap(int heap[], int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(heap,n,i);
}

int extractMin(int heap[], int *size){
    int root=heap[0];
    heap[0]=heap[*size-1];
    (*size)--;
    heapify(heap,*size,0);
    return root;
}

void insertHeap(int heap[], int *size, int val){
    int i=*size;
    heap[i]=val;
    (*size)++;

    while(i!=0 && heap[(i-1)/2]>heap[i]){
        swap(&heap[i],&heap[(i-1)/2]);
        i=(i-1)/2;
    }
}

void sortK(int arr[], int n, int k){
    int heap[100];
    int size=0;

    for(int i=0;i<=k;i++)
        heap[size++]=arr[i];

    buildHeap(heap,size);

    int index=0;

    for(int i=k+1;i<n;i++){
        arr[index++]=extractMin(heap,&size);
        insertHeap(heap,&size,arr[i]);
    }

    while(size>0)
        arr[index++]=extractMin(heap,&size);
}

int main(){
    int arr[]={6,5,3,2,8,10,9};
    int n=7,k=3;

    sortK(arr,n,k);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}