#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        
        int n = A.size();
        int count = 0;
        int accu_sum = 0;
        unordered_map<int, int> m({{0, 1}});
        cout << m[0] << endl;
        for (int i = 0; i< n;++i) {
            accu_sum += A[i];
            count += m[accu_sum - S];
            m[accu_sum] += 1;
        }
        return count;
    }
};


int main(){
    Solution s;
    vector<int> a{0, 0, 0, 0, 0};
    //vector<int> a{1, 0,1, 1, 0, 1};
    cout << s.numSubarraysWithSum(a, 0) << endl;

    cout << s.numSubarraysWithSum(a, 1) << endl;

    cout << s.numSubarraysWithSum(a, 2) << endl;
    return 0;
}
