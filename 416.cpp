#include <iostream>
#include <vector>
#include <numeric>
#include<map>
using namespace std;                            

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2!=0){
            return false;
        }
        int w = sum/2;
        int n = nums.size();
        // dp[i][j] == true nếu tới số i có cách tính tổng ra j
        vector<vector<bool>> dp(n+1, vector<bool>(w+1, false));
        dp[0][0] = true;
        for (int i=1; i<=n; i++){
            
            for (int j=1; j<=w; j++){
                if (j-nums[i-1]>=0){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]] ;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][w];
    }
    
};

int main() {
    Solution s;
    vector<int> t = {1,5,11,5};
    vector<int> t2 = {1,2,3,5};
    cout << s.canPartition(t) << " " << true << endl;
    cout << s.canPartition(t2) << " " << false << endl;
    return 0;
}