#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int num_flights = flights.size();
        
        vector<vector<pair<int, int>>> adj_matrix(n);
        vector<int> visited(n, false);
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        
        for (int i=0; i<num_flights; i++){
            adj_matrix[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        
        queue<int> myqueue;
        myqueue.push(src);
        
        while (!myqueue.empty()){
            int from = myqueue.front();
            myqueue.pop();
            visited[from] = true;
            vector<pair<int, int>> neighbors = adj_matrix[from];
            cout << "from: " << from << endl;
            
            for (int i=0; i< neighbors.size(); i++){
                int to = neighbors[i].first;
                int weight = neighbors[i].second;
                
                if (!visited[to]){
                    cout << "to: " << to << " " << cost[from]+weight << endl;
                    cost[to] = min(cost[to], cost[from] + weight);
                    myqueue.push(to);
                }
                
            }
        }
        return cost[dst];
    }
};

int main() {
    Solution s;
    vector<vector<int>> test{{1, 2, 7}, {1,3,9}, {1,6,14}, {2, 3,10}, {2, 4, 15}, {3,4,11}, {3,6,2}, {6,5,9},{4,5,6}};
    cout <<  s.findCheapestPrice(6, test, 1, 5, 0) << endl;
    return 0;
}
