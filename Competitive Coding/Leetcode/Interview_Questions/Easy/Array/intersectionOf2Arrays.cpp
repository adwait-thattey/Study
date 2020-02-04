#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> intersectMethod1(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> intersection;
        unordered_map<int, int>  nums1Map;
        unordered_map<int, int>  nums2Map;

        for (auto x: nums1){
            if (nums1Map.find(x) == nums1Map.end()){
                nums1Map[x] = 1;
            }
            else {
                nums1Map[x]+=1;
            }
        }
        for (auto x: nums2){
            if (nums2Map.find(x) == nums2Map.end()){
                nums2Map[x] = 1;
            }
            else {
                nums2Map[x]+=1;
            }
        }
        
        auto smallerMap = nums1Map;
        auto biggerMap = nums2Map;

        if (smallerMap.size() > biggerMap.size()){
            swap(smallerMap, biggerMap);
        }

        for (auto p: smallerMap){
            if (biggerMap.find(p.first) == biggerMap.end()) continue ;

            int count = p.second;
            if (biggerMap[p.first] < p.second ) count = biggerMap[p.first];

            for (int i=0;i<count;++i){
                intersection.push_back(p.first);
            }

        }

        return intersection;
}

int main() {
    vector<int> V1, V2;
    int size1, size2;
    cout << "Arr1 size:";
    cin >> size1;
    cout << "\nArr2 size:";
    cin >> size2;

    cout<<"\nArr1: \n";
    for (int i=0;i<size1;++i){
        int inp;
        cin >> inp;
        V1.push_back(inp);
    }

    cout<<"\n Arr2 \n";
    for (int i=0;i<size1;++i){
        int inp;
        cin >> inp;
        V2.push_back(inp);
    }

    cout <<"\nintersection\n";
    for (auto i: intersectMethod1(V1, V2)) cout << i << " ";
    return 0;
}