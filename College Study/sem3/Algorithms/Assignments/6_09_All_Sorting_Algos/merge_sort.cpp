#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <stdlib.h> 
#include <time.h>   

using namespace std;

void merge(vector<double> &V, long int s1, long int e1, long int s2, long int e2 ){
    vector<double> *merged_vector = new vector<double>;


    long int i = s1, j=s2;
    while(i<=e1 && j<=e2) {
        if (V[i] <= V[j]) {
            merged_vector->push_back(V[i]);
            ++i;
        }

        else {
            merged_vector->push_back(V[j]);
            ++j;
        }
    }
    
    while (i<=e1) {
        merged_vector->push_back(V[i]);
        ++i;
    }

    while (j<=e2) {
        merged_vector->push_back(V[j]);
        ++j;
    }

    auto iter = merged_vector->begin();
    while(s1<=e1) {
        V[s1] = *iter;
        ++s1;
        ++iter;
    }
    while(s2<=e2) {
        V[s2] = *iter;
        ++s2;
        ++iter;
    }

    delete merged_vector;    
}

void merge_sort(vector<double> &V, long int start, long int end) {
    if(end == start) {
        return;
    }

    merge_sort(V,start,(start+end)/2);
    merge_sort(V,((start+end)/2)+1,end);
    merge(V,start,(start+end)/2,((start+end)/2)+1,end);

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
    merge_sort(*V,0,V->size()-1);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Sorting Completed in " << elapsed.count() << " seconds\n";
    
    string output_file = "sorted" + file_name;
    
    /* for (auto i = V->begin();i!=V->end();++i) {
        cout<<*i<<"\n";
    } */

    writeback(*V,output_file);
    // cout<<"Sorted Output written to "<<output_file<<"\n";

    

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
