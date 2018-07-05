#include <iostream>

using namespace std;

void countingSort(int* Arr , int low , int high);
int MIN(int* , int , int);
int MAX(int* , int , int);

int main()
{

    cout << "Enter Size of Array";
    int N;
    cin >> N;
    int Arr[N];
    cout << "\n Start entering Elements : \n";

    for (int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
    }

    countingSort(Arr, 0, N - 1);
    cout << "\n\n";
    for (int i = 0; i < N; ++i)
    {
        cout << Arr[i] << " ";
    }

    return 0;
}

void countingSort(int* Arr , int low , int high) {

    int max_number = MAX(Arr, low, high), min_number = MIN(Arr, low, high);

    int countSize = max_number - min_number + 1;
    
    int count[countSize];
    
    for(int i=0;i<countSize;++i) count[i]=0;

    for(int i=low;i<=high;++i) {
        ++count[Arr[i]-min_number];
    }

    for (int i = 0; i < countSize; ++i)
    {
        cout << count[i] << " ";
    }

    int k = 0;
    for(int i=0;i<countSize;++i) {
        while(count[i]>0) {
            Arr[k] = i+1;
            ++k;
            --count[i];
        }
    }
}

int MAX(int* Arr , int low , int high) {
    int max_number = Arr[0];
    for(int i=low;i<=high;++i) {
        if(Arr[i]>max_number) max_number = Arr[i];
    }

    return max_number;
}

int MIN(int *Arr, int low , int high)
{
    int min_number = Arr[0];
    for (int i = low; i <= high; ++i)
    {
        if (Arr[i] < min_number)
            min_number = Arr[i];
    }

    return min_number;
}