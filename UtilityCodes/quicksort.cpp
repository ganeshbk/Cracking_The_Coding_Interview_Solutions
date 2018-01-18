#include<iostream>
using namespace std;

class quickSort{
    int start,end,*A;
public:
    quickSort(int, int, int *);
    int partition(int *,int,int);
    void qSort(int*,int,int);
    void swap(int *, int*);
};

quickSort::quickSort(int start, int end, int B[]){
    this->start = start;
    this->end = end;
    this->A= B;
}

int quickSort::partition(int A[], int start, int end){
    int pivot = A[end], pIndex = start;
    for(int i= start; i< end-1;i++){
        if(A[i]<= pivot){
            swap(&A[i], &A[pIndex]);
            pIndex++;
        }
    }
    swap(&A[end],&A[pIndex]);
    return pIndex;
}

void quickSort::qSort(int A[], int start, int end){
    if(start<end){
        int pIndex = partition(A,start, end);
        qSort(A,start, pIndex-1);
        qSort(A, pIndex+1, end);
    }
}


void quickSort::swap(int *a, int *b){
    int t= *a;
    *a= *b;
    *b = t;
}

int main(void){
 
    int start = 0, end=10,A[10]={1,2,-12,-100,123,6125003,01,231,123,123};
    quickSort q(start, end, A);
    q.qSort(A, start, end);
    for(int i=0;i<10;i++){
        cout<< A[i] << " ";
    }
}