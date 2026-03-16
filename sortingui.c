#include <stdio.h>
#include <stdlib.h>

struct element{
    int value;
    int freq;
};

int compare(const void *a,const void *b){
    struct element *x=(struct element*)a;
    struct element *y=(struct element*)b;

    if(x->freq==y->freq)
        return x->value - y->value;

    return y->freq - x->freq;
}

int main(){

    int arr[]={4,6,2,2,6,4,4,4};
    int n=8;

    int freq[100]={0};

    for(int i=0;i<n;i++)
        freq[arr[i]]++;

    struct element e[100];
    int m=0;

    for(int i=0;i<100;i++){
        if(freq[i]>0){
            e[m].value=i;
            e[m].freq=freq[i];
            m++;
        }
    }

    qsort(e,m,sizeof(struct element),compare);

    for(int i=0;i<m;i++){
        for(int j=0;j<e[i].freq;j++)
            printf("%d ",e[i].value);
    }

    return 0;
}