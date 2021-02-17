#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// f(i, "cooldown") = max(f(i-1, "cooldown"), f(i-1, "buy"), f(i-1, "sell"))
// f(i, "sell") = f(i-1, "buy") + prices[i]
// f(i, "buy") = max(f(i-1, "cooldown") - prices[i], f(i-2, "sell") - prices[i], f(i-1, "buy"))
// f(i) = max(f(i, "cooldown"), f(i, "buy"), f(i, "sell"))
class Solution {
public:
    int max_in_vector(vector<int> v){
        int res = v[0];
        for (int i = 1;i<v.size();++i) {
            if (v[i] > res) {
                res = v[i];
            }
        }  
        return res;
    }
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int> (3, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        for (int i = 1;i< prices.size();++i) {
            dp[i][0] = max_in_vector(dp[i-1]);
            dp[i][1] = dp[i-1][2] + prices[i];
            dp[i][2] = max(dp[i-1][0] - prices[i], dp[i-1][2]);
        }
        return max_in_vector(dp[prices.size()-1]); 
    }
};


int main() {
    Solution s;
    vector<int> test = {1,2,0,2,4};
    cout << s.maxProfit(test) << endl;
    return 0;
}