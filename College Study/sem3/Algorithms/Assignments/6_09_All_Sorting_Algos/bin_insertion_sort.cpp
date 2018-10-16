#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

void insertionSort(vector<double> &Arr) {
    long int N = Arr.size();
    for (long int i=1;i<N;++i) {
        double element = Arr[i];
        long int j = i-1;
        while(Arr[j] > element && j>=0) {
            Arr[j+1] = Arr[j];
            --j;
        }

        Arr[j+1] = element;
    }
}

void binInsertionSort(vector<double> &Arr) {
    long int N = Arr.size();
    for (long int i=1;i<N;++i) {
        
        double element = Arr[i];
        long int j = i-1;
        int pos = 0;
        if(Arr[0] > element) {
            pos = 0;
        }
        else if(Arr[i-1] < element) {
            continue;
        }
        else {
            long int l = 0,u = i-1;
            while(l<=u) {
                long int mid = (l + u)/2;
                if(Arr[mid]==element) {
                    pos = mid+1;
                    break;
                }
                else if(Arr[mid] < element) {
                    if(Arr[mid+1] > element) {
                        pos = mid+1;
                        break;
                    }
                    else {
                        l = mid+1;
                        continue;
                    }
                }
                else if(Arr[mid] > element) {
                    if(Arr[mid - 1] < element) {
                        pos= mid;
                        break;
                    }
                    else {
                        u = mid - 1;
                        continue;
                    }
                }
                else {
                    cout<<"EXCEPTION CAUGHT!!. EXIT!!!";
                    exit(-1);
                }
            }
        }

        while(j>=pos) {
            Arr[j+1] = Arr[j];
            --j;
        }
        Arr[pos] = element;
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
    // cout<<"File Opened. Reading... \n ";
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            double F = stod(line);
            V->push_back(F);
        }
        myfile.close();
    }
    // cout<<"Completed\n";

    // cout<<"Sorting...\n";
    auto start = std::chrono::high_resolution_clock::now();
    binInsertionSort(*V);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << elapsed.count();
    
    string output_file = "sorted" + file_name;
    // cout<<"Writing back...\n";
    writeback(*V,output_file);
    // cout<<"Completed. Output written to "<<output_file<<"\n";

}

int main(int argc, char *argv[]) {
    if(argc<2) {
        cout<<"No File Provided\nTerminating!";
        exit(0);
    }
    start(argv[1]);

    return 0;
}