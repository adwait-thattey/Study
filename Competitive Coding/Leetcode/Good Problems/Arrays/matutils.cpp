#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;

template <class T>
void print_mat(std::vector<std::vector<T>> mat, int gap = 1){

    for (auto i = mat.begin();i!=mat.end();++i) {
        for(auto j = i->begin();j!=i->end();++j){
            std::cout << *j << string(gap, ' ');
        }

        std::cout << "\n";
    }
}

template <class T>
vector<vector<T>> input_mat(int m, int n){
    std::vector<std::vector<T>> mat;

    for(int i=0;i<m;++i){
        std::vector<T> line;
        std::string inp_str;

        getline(std::cin, inp_str);
        T temp;
        stringstream ss(inp_str);

        for(int j=0;j<n;++j){
            ss >> temp;
            line.push_back(temp);
        }
        

        mat.push_back(line);
    }

    return mat;
}