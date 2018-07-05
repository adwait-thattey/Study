#include <iostream>
#include <stdio.h>

using namespace std;
int in_place_merge(int *Arr, int start, int mid, int end)
{
    while(start<=mid) {
        
        while(Arr[start]<Arr[mid+1]) {
            ++start;
        }
        
        if(Arr[start]>Arr[mid+1]) {
            int temp = Arr[start];
            Arr[start] = Arr[mid+1];
            int j;
            for(j=mid+1+1;j<=end && Arr[j]<temp;++j) {
                Arr[j-1] = Arr[j];
            }
            Arr[j-1] = temp;    
        }
    }
}

void in_place_mergeSort(int *Arr, int start, int end)
{
	cout<<"\nin sort\n";
    if (end - start <= 0)
        return;

    int mid = (start + end) / 2;

    in_place_mergeSort(Arr, start, mid);
    in_place_mergeSort(Arr, mid + 1, end);

    in_place_merge(Arr, start, mid, end);
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

    in_place_mergeSort(Arr, 0, N - 1);

    cout << "\nSorted Array :..\n";

    for (int i = 0; i < N; ++i)
    {
        printf(" %d", Arr[i]);
    }
    return 0;
}
