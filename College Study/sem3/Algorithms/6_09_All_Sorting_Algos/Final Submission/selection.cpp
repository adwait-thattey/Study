#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

int find_min_pos(vector<double> A , long int start , long int end) {
    int min_pos = start;
    for(int i=start;i<=end;++i) {
        if(A[i]<A[min_pos]) min_pos = i;
    }

    return min_pos;
}

void selection_sort(vector<double> &Arr) {
    long int N = Arr.size();
    for(int i=0;i<N-1;++i) {
        int min_pos = find_min_pos(Arr,i,N-1);
        swap(Arr[i],Arr[min_pos]);
    }
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
    selection_sort(V);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Sorting Completed in " << elapsed.count() << " seconds\n";
    
    string output_file = "sorted" + file_name;
    
    writeback(V,output_file);
    cout<<"Sorted Output written to "<<output_file<<"\n";

}

int main(int argc, char *argv[]) {
    if(argc<2) {
        cout<<"No File Provided\nTerminating!";
        exit(0);
    }
    start(argv[1]);
    return 0;
}

