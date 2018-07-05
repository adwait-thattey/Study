#include "linklist.cpp"
#include <iostream>

using namespace std;
int main() {
    linklist L;
    cout<<"\nEnter number of prisoners :";
    int N;
    cin>>N;
   
    for(int i = 1;i<=N;++i) {

        L.addAtEnd(i);
    }

    
    node *del = L.retHead();
    while(L.retSize()>1) {
        if(del==L.retTail()) {
            L.deleteAt(L.retHead());
            del = L.retHead();
            continue;
        }
        L.deleteAt(del->next);
        if(del==L.retTail()) {
            del = L.retHead();
            continue;
        }
        del = del->next;
        
    }

    cout<<"\n"<<L.retHead()->data;
    return 0;
}