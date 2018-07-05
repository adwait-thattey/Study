#include <iostream>
#include <stdio.h>

using namespace std;

void insertionSort(int* Arr , int N) {
    for (int i=1;i<N;++i) {
         int element = Arr[i];
         int j = i-1;
         while(Arr[j] > element && j>=0) {
             Arr[j+1] = Arr[j];
             --j;
         }

         Arr[j+1] = element;
    }
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

    insertionSort(Arr, N);

    cout << "\nArray :..\n";

    for (int i = 0; i < N; ++i)
    {
        printf(" %d", Arr[i]);
    }
    return 0;
}
