#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_ele = nums[0];
        for (int i : nums) {
            if (i > max_ele) {
                max_ele = i;
            }
        }
        
        vector<int> map(max_ele+1, 0);
        for (int i : nums) {
            map[i] += i;
        }
        if (max_ele == 1) {
            return map[1];   
        }
        vector<int> dp(max_ele+1, 0);
        dp[1] = map[1];
        
        dp[2] = map[2];
        for (int i = 3; i<=max_ele;++i) {
            dp[i] = max(dp[i-2], dp[i-3]) + map[i];
        }
        return max(dp[max_ele], dp[max_ele-1]);       
    }
};

int main(){
    Solution s;
    vector<int> a{1, 1};
    //vector<int> a{1, 0,1, 1, 0, 1};
    cout << s.deleteAndEarn(a) << endl;

    return 0;
}
