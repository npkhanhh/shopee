#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        priority_queue<int> pq;
        int res;
        for (int i = 0;i<nums.size();++i) {
            pq.push(nums[i]);
        }
        pq.push(0);
        while(maxOperations > 0) {
            int cur = pq.top();
            if (cur == 1) {
                return cur;
            }
            pq.pop();
            int next = pq.top();
            int all_first = 1 + ((cur - 1) / (maxOperations+1));
            if (next <= all_first) {
                return all_first;
            } else {
                int new_ele = cur / 2;
                pq.push(new_ele);
                new_ele += cur % 2;
                pq.push(new_ele);
            }
            --maxOperations;
        }
        return pq.top();
    }
};

int main() {
    Solution s;
    vector<int> v{2,4,8,2};
    cout << s.minimumSize(v, 4) << endl;

    return 0;
}