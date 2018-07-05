/*

Please compile the file using c++ 17 or C++14 standard only.

Use g++ -std=c++14 file.cpp
OR
g++ -std=c++17 file.cpp 

*/

#include <iostream>
#include <string>

using namespace std;

string convert_word_to_ASCII(string S) {
    string ASCII="";
    
    for(string::iterator I = S.begin();I!=S.end();++I) {
        int x = int(*I);
        string temp = to_string(x);
        while(temp.size() < 3) {
            temp = "0" + temp;
        }

        ASCII = ASCII + temp;
    }

    return ASCII;
}

void convert_all_words_to_ASCII(string W[] , int size) {

    for(int i=0;i<size;++i) {
        W[i] = convert_word_to_ASCII(W[i]);
    }

}

void append_dates(string W[] , string dates[] , int size) {

    for(int i=0;i<size;++i) {
        W[i] = dates[i] + W[i];
    }
}

string find_max_string(string Array[] , int size) {
    string max_string = "";
    for(int i=0;i<size;++i) {
        if(Array[i].size()>max_string.size()) max_string = Array[i];
    }

    return max_string;
}

void append_zeros(string W[] , int size) {
    string max_string = find_max_string(W,7);
    int length = max_string.size();
    for(int i=0;i<size;++i) {
        while(W[i].size()<length) W[i] = W[i] + "0";
    }
}

void counting_sort(string Arr[] , int size , int position) {

    int count[] = {0,0,0,0,0,0,0,0,0,0};
    string sorted_array[size];
    int digits[size];
    int length = Arr[0].size();
    for(int i=0;i<size;++i) {
        digits[i] = int(Arr[i][length-position-1]) - int('0');
    }

    for(int i = 0;i<size;++i) ++count[digits[i]];

    for(int i=1;i<10;++i) count[i]+=count[i-1];

    
    for(int i=size-1;i>=0;--i) {
        
        int index = count[digits[i]] - 1;
        sorted_array[index] = Arr[i];
        --count[digits[i]];
    }

    for(int i=0;i<size;++i) {
        Arr[i] = sorted_array[i];
    }

}
void radix_sort(string Array[] , int size) {

    int length = Array[0].size();

    for(int i=0;i<length;++i) {
        counting_sort(Array,size,i);
    }

}

string strip_zeroes_from_string(string S) {

    while(S[0]=='0') {
        S = S.substr(1);
    }

    return S;
}
void strip_zeros_from_all(string Arr[] , int size) {

    for(int i=0;i<size;++i) {
        Arr[i] = strip_zeroes_from_string(Arr[i]);
    }
}


int main() {

    string dates[] = {"14032018" , "20011876" , "23121947" , "28022000" , "01012012" , "08051934" , "16091999"};
    string W[] = {"we" , "are" , "trying" , "to" , "sort" , "the" , "words"};
    
    cout<<"Given Words :";

    for (int i = 0; i < 7; ++i)
    {
        cout << W[i] << " \n";
    }

    cout<<"\n\n";

    cout<<"Given Dates : \n";
    for (int i = 0; i < 7; ++i)
    {
        cout << dates[i] << " \n";
    }
    convert_all_words_to_ASCII(W , 7);
    append_dates(W,dates,7);

    append_zeros(W, 7);

    cout<<"\n After Appending Dates and Zeros Before Sorting : \n";

    for(int i=0;i<7;++i) {
        cout<<W[i]<<" \n";
    }

    

    radix_sort(W,7);


    //strip_zeros_from_all(W,7);

    cout<<"\n\n After Sorting : \n";
    for (int i = 0; i < 7; ++i)
    {
        cout << W[i] << " \n";
    }
    return 0;
}
