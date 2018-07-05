#include <iostream>
#include <stdio.h>

using namespace std;
int find_min_pos(int* , int , int);
void selection_sort(int *Arr , int N) {
    for(int i=0;i<N-1;++i) {
        int min_pos = find_min_pos(Arr,i,N-1);
        swap(Arr[i],Arr[min_pos]);
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

    selection_sort(Arr, N);

    cout << "\nArray :..\n";

    for (int i = 0; i < N; ++i)
    {
        printf(" %d", Arr[i]);
    }
    return 0;
}


int find_min_pos(int *A , int start , int end) {
    int min_pos = start;
    for(int i=start;i<=end;++i) {
        if(A[i]<A[min_pos]) min_pos = i;
    }

    return min_pos;
}