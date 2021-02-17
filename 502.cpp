#include<iostream>
#include<vector>
#include<queue>


using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        
        int res = W;
        int n = Profits.size();
        vector<pair<int, int>> tuples;
        for (int i = 0;i<n;++i) {
            tuples.push_back(make_pair(Capital[i], Profits[i]));
        }
        sort(tuples.begin(), tuples.end()); 

        priority_queue<pair<int, int>> pq;
        int pop_count = 0;
        for (int i=0;i<n;++i) {
            pair<int, int> tuple = tuples[i];
            while (tuple.first > res && !pq.empty()) {
                pair<int, int> top_project = pq.top();
                pq.pop();
                res += top_project.first;
                pop_count += 1;
                
                if(pop_count == k) {
                    return res;
                }
                 
            }
            if (tuple.first > res && pq.empty()) {
                return res;
            } 
            pq.push(make_pair(tuple.second, tuple.first));
            
        }
        while (pop_count < k && pop_count<n) {
            pair<int, int> top_project = pq.top();
            pq.pop();
            res += top_project.first;
            pop_count += 1;
        }
        return res; 
    }
};

int main() {
    Solution s;
    vector<int> Profits {100, 1, 1, 3, 5};
    vector<int> Capitals {1000, 1000, 0, 1, 1};

    int total3 = s.findMaximizedCapital(4, 0,Profits, Capitals);
    cout << total3 << endl;
    return 0;
}
