#include <iostream>

using namespace std;
int get_max_bin(int* ,int , int);
int main() {

    int Arr[5];

    for(int i=0;i<5;++i) {
        cin>>Arr[i];
    }

    int m = get_max_bin(Arr,0,4);
    cout<<"\n"<<Arr[m];

    return 0;

}

int get_max_bin(int* Arr , int low , int high) {

    int mid = (low + high)/2;
    if(low>=high) return high;
    else if(Arr[mid]>Arr[mid+1]) return mid;
    else if( Arr[low] <Arr[high]) return get_max_bin(Arr,mid+1,high);
    else return get_max_bin(Arr,low,mid-1);
}