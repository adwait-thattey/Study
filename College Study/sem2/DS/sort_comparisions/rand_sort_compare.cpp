#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

template <class T>
void bubbleSort(T *, int);
template <class T>
void selection_sort(T *, int);
template <class T>
int find_min_pos(T *, int, int);
template <class T>
void insertionSort(T *, int);
template <class T>
void merge(T *, int, int, int);
template <class T>
void in_place_merge(T *, int, int, int);
template <class T>
void mergeSort(T *, int, int);
template <class T>
void in_place_mergeSort(T *, int, int);
template <class T>
void quickSort(T *, int, int);
template <class T>
int getPivot(T *, int, int);
template <class T>
void quick3Sort(T *, int, int);

template <class T>
void printArray(T *A, long unsigned int N)
{
    if (N <= 0)
    {
        cout << "\n";
        return;
    }
    printArray(A, N - 1);
    cout << A[N - 1] << " ";
}

template <class T>
void copyArray(T *A, T *A2, long unsigned int N)
{
    for (int i = 0; i < N; ++i)
    {
        A2[i] = A[i];
    }
}

int main()
{
    int revS[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    FILE *F;
    F = fopen("data_rand.csv", "w");
    fputs("N ,bub,sel,ins,merge,in_merge,quick,quick3\n", F);
    //printf("%7s  %15s msec \n", "N", "Time Required");
    clock_t begin, end;
    fclose(F);
    for (long unsigned int N = 10; N <= 500000; N *= 2)
    {
        F = fopen("data_rand.csv", "a");
        cout << "\n Taking Array Size : " << N << "\n";
        srand(time(NULL));
        long unsigned int Arr[N], Arr2[N];
        for (int i = 0; i < N; ++i)
        {
            Arr[i] = rand()%5000;
        }
        //printArray(Arr,N);

        copyArray(Arr, Arr2, N);
        cout << "\nbubble started\n";
        begin = clock();
        bubbleSort(Arr2, N);
        end = clock();

        double bub_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        copyArray(Arr, Arr2, N);

        cout << "\nselection started\n";
        begin = clock();
        selection_sort(Arr2, N);
        end = clock();

        double sel_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        copyArray(Arr, Arr2, N);

        cout << "\ninsertion started\n";
        begin = clock();
        insertionSort(Arr2, N);
        end = clock();

        double ins_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
        copyArray(Arr, Arr2, N);

        cout << "\nmerge started\n";
        begin = clock();
        mergeSort(Arr2, 0, N - 1);
        end = clock();

        double merge_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
        copyArray(Arr, Arr2, N);

        /*cout << "\nin place merge\n";
        begin = clock();
            in_place_mergeSort(Arr2,0,N-1);
        end = clock();
*/
        double inmerge_spent = 0.0; //(double)(end - begin) / (double)CLOCKS_PER_SEC;
        copyArray(Arr, Arr2, N);

        cout << "\nquick started\n";
        begin = clock();
        quickSort(Arr2, 0, N - 1);
        end = clock();

        double quick_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;
        copyArray(Arr, Arr2, N);

        cout << "\nquick median of 3 started\n";
        begin = clock();
        quick3Sort(Arr2, 0, N - 1);
        end = clock();

        double quick3_spent = (double)(end - begin) / (double)CLOCKS_PER_SEC;

        char strtime[100000];

        snprintf(strtime, 100000, "%ld,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", N, bub_spent, sel_spent, ins_spent, merge_spent, inmerge_spent, quick_spent, quick3_spent);

        fputs(strtime, F);

        fclose(F);

        // mergeSort(Arr,0,N-1);
        // in_place_mergeSort(Arr,0,N-1);
        // quickSort(Arr,0,N-1);
        // quick3Sort(Arr,0,N-1);
    }

    return 0;
}

template <class T>
void bubbleSort(T *Arr, int N)
{

    for (int i = 0; i < N; ++i)
    {
        int swapflag = 0;
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (Arr[j] > Arr[j + 1])
            {
                int temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                swapflag = 1;
            }
        }
        if (swapflag == 0)
        {
            break;
        }
    }
}
template <class T>
void selection_sort(T *Arr, int N)
{
    for (int i = 0; i < N - 1; ++i)
    {
        int min_pos = find_min_pos(Arr, i, N - 1);
        swap(Arr[i], Arr[min_pos]);
    }
}

template <class T>
int find_min_pos(T *A, int start, int end)
{
    int min_pos = start;
    for (int i = start; i <= end; ++i)
    {
        if (A[i] < A[min_pos])
            min_pos = i;
    }

    return min_pos;
}

template <class T>
void insertionSort(T *Arr, int N)
{
    for (int i = 1; i < N; ++i)
    {
        int element = Arr[i];
        int j = i - 1;
        while (Arr[j] > element && j >= 0)
        {
            Arr[j + 1] = Arr[j];
            --j;
        }

        Arr[j + 1] = element;
    }
}

template <class T>
void merge(T *Arr, int start, int mid, int end)
{
    int mergedArray[end - start + 1];
    int i, j, k;
    for (i = start, j = mid + 1, k = 0; i <= mid && j <= end;)
    {
        if (Arr[i] < Arr[j])
        {
            mergedArray[k] = Arr[i];
            ++i;
        }
        else
        {
            mergedArray[k] = Arr[j];
            ++j;
        }
        ++k;
    }

    while (i <= mid)
    {
        mergedArray[k++] = Arr[i++];
    }
    while (j <= end)
    {
        mergedArray[k++] = Arr[j++];
    }

    for (k = 0; k < end - start + 1; ++k)
    {
        Arr[start + k] = mergedArray[k];
    }
}

template <class T>
void mergeSort(T *Arr, int start, int end)
{

    if (end - start <= 0)
        return;

    int mid = (start + end) / 2;

    mergeSort(Arr, start, mid);
    mergeSort(Arr, mid + 1, end);

    merge(Arr, start, mid, end);
}

template <class T>
void in_place_merge(T *Arr, int start, int mid, int end)
{
    while (start <= mid)
    {

        while (Arr[start] < Arr[mid + 1])
        {
            ++start;
        }

        if (Arr[start] > Arr[mid + 1])
        {
            int temp = Arr[start];
            Arr[start] = Arr[mid + 1];
            int j;
            for (j = mid + 1 + 1; j <= end && Arr[j] < temp; ++j)
            {
                Arr[j - 1] = Arr[j];
            }
            Arr[j - 1] = temp;
        }
    }
}

template <class T>
void in_place_mergeSort(T *Arr, int start, int end)
{
    cout << "\nstuck\n";

    if (end - start <= 0)
        return;

    int mid = (start + end) / 2;

    in_place_mergeSort(Arr, start, mid);
    in_place_mergeSort(Arr, mid + 1, end);

    in_place_merge(Arr, start, mid, end);
}

template <class T>
void quickSort(T *Arr, int low, int high)
{

    /* Assumes last element as pivot */

    if (low >= high)
    {
        return;
    }
    int j = low;

    for (int i = low; i < high; ++i)
    {
        if (Arr[i] < Arr[high])
        {
            swap(Arr[i], Arr[j]);
            ++j;
        }
    }

    swap(Arr[j], Arr[high]);

    quickSort(Arr, low, j - 1);
    quickSort(Arr, j + 1, high);
}

template <class T>
void quick3Sort(T *Arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    /* Assumes last element as pivot */
    int pivot = getPivot(Arr, low, high);

    swap(Arr[pivot], Arr[high]);

    int j = low;

    for (int i = low; i < high; ++i)
    {
        if (Arr[i] < Arr[high])
        {
            swap(Arr[i], Arr[j]);
            ++j;
        }
    }

    swap(Arr[j], Arr[high]);

    quick3Sort(Arr, low, j - 1);
    quick3Sort(Arr, j + 1, high);
}

template <class T>
int getPivot(T *Arr, int low, int high)
{
    int mid = (low + high) / 2;
    int pos = (Arr[low] <= Arr[mid]) ? mid : low;
    if (Arr[pos] <= Arr[high])
        return pos;
    else
    {
        if (Arr[high] > Arr[low])
            return high;
        else
            return (Arr[low] < Arr[mid]) ? low : mid;
    }
}
