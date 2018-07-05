#include <iostream>
#include <string>
using namespace std;

string get_sum(string num1 , string num2) {
    string final_sum = "";
    int cur_carry = 0;
    string::reverse_iterator ri1 = num1.rbegin() , ri2 = num2.rbegin();
    while(ri1!=num1.rend() && ri2!=num2.rend()) {
        int i1 = int(*ri1) - 48;
        int i2 = int(*ri2) - 48;
        int sum = i1 + i2 + cur_carry;
        cur_carry = sum/10;
        final_sum = to_string(sum%10) + final_sum;
        ++ri1;
        ++ri2;

    }

    if(ri1==num1.rend()) {
        if(ri2==num2.rend()) {
            if (cur_carry==0){
                return final_sum;
            }
            else {
                return to_string(cur_carry) + final_sum;
            }
        }
        else {
            while(ri2!=num2.rend()) {
                int i2 = int(*ri2) - 48;
                int sum =i2 + cur_carry;
                cur_carry = sum / 10;
                final_sum = to_string(sum % 10) + final_sum;
                ++ri2;
            }
            if (cur_carry==0){
                return final_sum;
            }
            else {
                return to_string(cur_carry) + final_sum;
            }
            
        }
    }
    else {
        while(ri1!=num1.rend()) {
                int i1 = int(*ri1) - 48;
                int sum = i1 + cur_carry;
                cur_carry = sum / 10;
                final_sum = to_string(sum % 10) + final_sum;
                ++ri1;
            }
            if (cur_carry==0){
                return final_sum;
            }
            else {
                return to_string(cur_carry) + final_sum;
            }
    }

    return final_sum;

}
int main() {

    int T;
    cin>>T;
    while(T){
        --T;
        string num1,num2;
        int n1,n2;
        cin>>n1>>n2;
        cin>>num1;
        cin>>num2;
    
        string sum = get_sum(num1,num2);
        while (sum.length()>1 && sum[0]=='0') {
            sum = sum.substr(1);
        }
        cout<<sum<<"\n";
    }

    
}    