#include<iostream>
#include<vector>
#include<math.h>
#include<numeric>
#include <experimental/iterator>

using namespace std;

class Solution {
private:

    int myfunc(vector<int>& values, vector<int>& weights, int max_weight, int current_weight,int current_value,int idx){    
        
        if (current_weight > max_weight){
            return -1;
        }
        if (idx < 0){
            return current_value;
        }
        int include = myfunc(values, weights, max_weight, current_weight + weights[idx], current_value + values[idx], idx-1);
        int exclude = myfunc(values, weights, max_weight, current_weight, current_value,idx-1);
        return max(include, exclude);
    }

public:
        void print(std::vector<int> const &input){
        copy(input.begin(),
            input.end(),
            experimental::make_ostream_joiner(cout, " "));
        cout << endl;
        }

    int knapsack(vector<int>& values, vector<int>& weights, int w) {
        //return myfunc(values, weights,w, 0, 0, values.size() );
        int n = values.size();
        
        vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=w; j++){
                if (j-weights[i-1]>=0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]]+ values[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for (int i = 0; i<=n; i++) {
            print(dp[i]);
        }
        return dp[n][w];
    }
};

//dp[i, W] value max khi tính tới i và có current weight <= W, w[i] là weight thg i 
//dp[i,W] = max(dp[i-1, W], {dp[i-1, W-w[i]]+ value[i]}) 

int main() {
    Solution s;
    // vector<int> values = {60, 100, 120};
    // vector<int> weights = {10, 20, 30};
    // int total1 = s.knapsack(values, weights, 50);
    // cout << total1 << endl;
    
    // vector<int> values2 = {260, 100, 120};
    // vector<int> weights2 = {10, 20, 30};
    // int total2 = s.knapsack(values2, weights2, 50);
    // cout << total2 << endl;


    vector<int> values3 {20, 5, 10, 40, 15, 25};
    vector<int> weights3 = { 1, 2, 3, 8, 7, 4 };
    int total3 = s.knapsack(values3, weights3, 3);
    cout << total3 << endl;

    return 0;
}
// current capital = c

// [1000, 100,]


// dp[i] là max capital đã làm i project => dp[k] là kết quả
// dp[i] = dp[i-1] + P_j với P_j là max trong đám chưa làm mà có capital <= dp[i-1]

// dp[i] = dp[i-1] + max(dp[j]) with c_j<=dp[i-1], 

// dp[i][j]

// dp[i][c] là max capital khi đã làm i project và có c capital trước khi làm project thứ i

// dp[i][c]= max(dp[i-1][c-p_j]) với p_j là max profit trong đám chưa làm có capital <= c-p_j

// dp[i][c]

// done=[False]*n


// dp[i] là max profit khi đã làm i project
