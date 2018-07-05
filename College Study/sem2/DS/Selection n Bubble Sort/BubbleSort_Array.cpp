#include <iostream>
#include <stdio.h>
using namespace std;

void bubbleSort(int* Arr , int N) {

    for(int i=0;i<N;++i) {
        int swapflag = 0;
        for(int j=0;j<N-i-1;++j) {
            if(Arr[j]>Arr[j+1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                swapflag = 1;
            }
        }
        if(swapflag ==0) {
            break;
        }
    }

}

int main() {
    int Arr[1000];

    cout<<"\nEnter no of Elements :";
    int N;
    cin>>N;
    cout<<"Enter Elements";
    for (int i=0;i<N;++i) {
        scanf("%d",&Arr[i]);
    }

    bubbleSort(Arr , N);

    cout<<"\nArray :..\n";

    for (int i = 0; i < N; ++i)
    {
        printf(" %d",Arr[i]);
    }
    return 0;
}

