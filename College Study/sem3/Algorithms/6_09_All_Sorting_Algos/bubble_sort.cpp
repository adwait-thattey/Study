#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

void bubbleSort(vector<double> &Arr) {

    long int N = Arr.size();
    
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
    vector <double> *V = new vector<double>;
    ifstream myfile (file_name);
    
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            double F = stod(line);
            V->push_back(F);
        }
        myfile.close();
    }
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(*V);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Sorting Completed in " << elapsed.count() << " seconds\n";
    
    string output_file = "sorted" + file_name;
    
    writeback(*V,output_file);
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


