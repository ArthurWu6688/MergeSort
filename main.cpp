#include <stdio.h>
#define N 7

typedef int ElemType;

void Merge(ElemType *A,int low,int mid,int high){
    static ElemType B[N];
    int i,j,k;
    for(i=0;i<=high;++i){
        B[i]=A[i];
    }
    k=low;
    for(i=low,j=mid+1;i<=mid&&j<=high;){
        if(B[i]<B[j]){
            A[k++]=B[i++];
        }else{
            A[k++]=B[j++];
        }
    }
    while(i<=mid){
       A[k++]=B[i++];
    }
    while(k<=high){
       A[k++]=B[j++];
    }
}

void MergeSort(ElemType *A,int low,int high){
    int mid=(low+high)/2;
    if(low<high){
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

void Print(ElemType *A){
    for(int i=0;i<N-1;++i){
        printf("%3d",A[i]);
    }
    printf("\n");
}

int main(){
    ElemType A[N]={49,38,65,97,76,13,27};
    Print(A);
    MergeSort(A,0,6);
    Print(A);

    return 0;
}
