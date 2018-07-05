#include <iostream>

using namespace std;
void quickSort(int *Arr , int low , int high);
int getPivot(int* , int , int);
//void swap(int &A , int &B);

int main() {

    cout<<"Enter Size of Array";
    int N;
    cin>>N;
    int Arr[N];
    cout<<"\n Start entering Elements : \n";

    for(int i=0;i<N;++i) {
        cin>>Arr[i];
    }

    quickSort(Arr,0,N-1);
    cout<<"\n\n";
    for (int i = 0; i < N; ++i)
    {
        cout <<Arr[i]<<" ";
    }


    return 0;
}

void quickSort(int *Arr , int low , int high) {

    /* Assumes last element as pivot */
    int pivot = getPivot(Arr,low,high);

    swap(Arr[pivot],Arr[high]);

    if(low>=high) {
        return;
    }
    int j = low;

    for(int i = low;i<high;++i) {
       if(Arr[i]<Arr[high]) {
            swap(Arr[i],Arr[j]);
            ++j;
       }
    }
    
    swap(Arr[j],Arr[high]);

    quickSort(Arr,low,j-1);
    quickSort(Arr,j+1,high);
}

int getPivot(int* A , int low , int high) {
    return high;
}