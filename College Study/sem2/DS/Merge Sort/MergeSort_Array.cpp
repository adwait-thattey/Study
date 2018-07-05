#include <iostream>
#include <stdio.h>

using namespace std;
int* merge(int* Arr ,int start , int mid , int end) {
    int mergedArray[end-start+1];
    int i,j,k;
    for(i=start,j=mid+1,k=0;i<=mid && j<=end;) {
        if(Arr[i]<Arr[j]) {
            mergedArray[k] = Arr[i];
            ++i;
        }
        else {
            mergedArray[k] = Arr[j];
            ++j;
        }
        ++k;
    }

    while(i<=mid) {
        mergedArray[k++] = Arr[i++];
    }
    while(j<=end) {
        mergedArray[k++] = Arr[j++];
    }

    for(k=0;k<end-start+1;++k) {
        Arr[start+k] = mergedArray[k];
    }

}

void mergeSort(int* Arr , int start , int end) {

    if(end-start <=0) return;

    int mid = (start+end)/2;

    mergeSort(Arr,start,mid);
    mergeSort(Arr,mid+1,end);

    merge(Arr,start,mid,end);

}

int main()
{
    int Arr[1000];

    cout << "\nEnter no of Elements :";
    int N;
    cin >> N;
    cout << "Enter Elements";
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &Arr[i]);
    } 

    mergeSort(Arr, 0 , N-1);

    cout << "\nSorted Array :..\n";

    for (int i = 0; i < N; ++i)
    {
        printf(" %d", Arr[i]);
    }
    return 0;
}
