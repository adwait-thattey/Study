/*
This code is broken. Does not give correct answer for some cases. 
Example : 1 2 3 4 5
Repair work in progress
*/
#warning "This code is broken. Does not give correct answer for some cases. Example : 1 2 3 4 5 . Repair work in progress"


#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Heap {
    private:
        vector <int> heap;
    public:
        Heap(int* Arr,int size) {
            cout<<sizeof(Arr);
            heap = vector <int>(Arr, Arr + size);
        }

        Heap(vector <int> V) {
            heap = V;
        }
        vector <int> getHeap() {
            // returns heap vector
            return heap;
        }

        void maxHeapify(int index, int stop_index=numeric_limits<int>::max()) {
            /* Corrects A single violation of the max heap property at that point 
                Stops at stop index.
            */

            
            if(2*index >= heap.size() || 2*index > stop_index) {
                return;
            }

            else if((2*index + 1) > stop_index || (2*index + 1) >= heap.size())  {
                if(heap[2*index] > heap[index]) {
                    swap(heap[2*index],heap[index]);
                    maxHeapify(2*index, stop_index);
                }
            }

            else {
                if(heap[2*index] > heap[index]) {
                    if(heap[2*index + 1] > heap[2*index]) {
                        swap(heap[index],heap[2*index + 1]);
                        maxHeapify(2*index + 1, stop_index);
                    }
                    else {
                        swap(heap[index],heap[2*index]);
                        maxHeapify(2*index, stop_index);
                    }
                }

                else if(heap[2*index + 1] > heap[index]) {
                    swap(heap[2*index + 1],heap[index]);
                    maxHeapify(2*index + 1, stop_index);
                }
            }
        }

        void minHeapify(int index) {
            /* Corrects a single violation of min heap property at given point */
        }

        void buildMaxHeap(){
            /* Converts the heap to a max_heap */
            for(int i = heap.size()/2 - 1;i>=0;--i) {
                maxHeapify(i);
            }
        }

        void buildMinHeap(){
            /* Converts the heap to a min_heap */
        }

        void printHeap() {
            cout<<"\n";
            for (auto i = heap.begin();i!=heap.end();++i) {
                cout<<*i<<" ";
            }
            cout<<"\n";
        }

        vector <int> sort() {
            /* Sorts the Vector V using Max Heap Sort */
            
            buildMaxHeap();
            // printHeap();
            
            vector <int> retV(heap.size());
            
            for(int k = heap.size() - 1;k>=0;--k) {
                // retV[heap.size() - 1 - k] = heap[0];
                
                int temp = heap[0];
                heap[0] = heap[k];
                heap[k] = temp;;

                maxHeapify(0, k);

            }
        }
};


int main(int argc , char* argv[]) {
    vector <int> V(argc-1);
    for(int i = 0;i<argc-1;++i) {
        V[i] = atoi(argv[i+1]);    
    }

    Heap H(V);
    H.printHeap();

    H.buildMaxHeap();

    H.printHeap();
    

    // vector <int> Vsorted = Heap.sort(V);
    // H.buildMaxHeap()
    return 0;
}

