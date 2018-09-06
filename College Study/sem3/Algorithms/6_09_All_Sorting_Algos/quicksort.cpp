#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>   

using namespace std;

//void swap(int &A , int &B);
long int getPivot(vector<double> A , long int low , long int high) {
    if(high==low) {
        return low;
    }
    long int pivot = (rand() % (high - low) ) + low;
    return pivot;
}

void quickSort(vector<double> &Arr , long int low , long int high) {
    static int count_debug = 1;
    
    /* Assumes last element as pivot */
    // cout<<"start\n";
    long int pivot = getPivot(Arr,low,high);
    // cout<<count_debug++<<"\n";
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


void writeback(vector<double> V, string output_file) {
    ofstream outfile;
    outfile.open (output_file);

    for(auto I = V.begin();I!=V.end();++I) {
        outfile << *I<<"\n";
    }

    outfile.close();
}

void start(string file_name) {
    string line;
    vector <double> V;
    ifstream myfile (file_name);
    
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            double F = stod(line);
            V.push_back(F);
        }
        myfile.close();
    }
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(V,0,V.size()-1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Sorting Completed in " << elapsed.count() << " seconds\n";
    
    string output_file = "sorted" + file_name;
    
    writeback(V,output_file);
    cout<<"Sorted Output written to "<<output_file<<"\n";

}

int main(int argc, char *argv[]) {
    
    srand (time(NULL));
    if(argc<2) {
        cout<<"No File Provided\nTerminating!";
        exit(0);
    }
    start(argv[1]);

    return 0;
}


