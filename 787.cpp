#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<math.h>

using namespace std;

// for (int i=0; i< k; i++){
    
//     // do sth
//     chọn current node, thì không ưu tiên cost thấp nhất nữa, mà ưu tiên depth trước rồi mới tới cost
//     i là depth, số edge từ source tới nó 
//     k = 1
//     // 1 - 2 - 3     1-2: 1, 2-3: 1, 2-4: 2
//     //  \ /    |     1-4: 100, 4-5: 3
//     //   4 --- 5    cost[4] = 2
//     cost[0][2] = 1
//     cost[0][4] = 100
//     cost[0][3] = cost[0][5] = INT_MAX
//     cost[1][3] = 2
//     cost[1][4] = 3
//     cost[1][5] = 103 = min(cost[0][5], cost[0][4]+weight4_5) = min(INT_MAX, 100+3)
//     cost[2][5] = min(cost[1][5], cost[1][3]+weight3_5, cost[1][4]+weight4_5) = min(103, 3+3) = 6
//     thứ tự current node: 
//     (0, 2), (0, 4), (1, 3), (1, 4), (2, 5)
//     k là 2, return 6 , k là 1 thì return 103
//     cost[i][x] là cost đường đi ngắn nhất tới x trong vòng i 
//     cost[i][x] = min(cost[i-1][x], cost[i-1][y]+weight) với y là 1 node connect tới x với cost là weight 
// }

class Solution {
public:
    struct compare  
    {  
        bool operator()(vector<int> l, vector<int> r)  
        {  
            //v[0]: là depth, v[1] là cost, v[2] là node
            if (l[0] == r[0]) {
                return l[1] > r[1];
            }
            return l[0] > r[0];  
        }  
    }; 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) {
            return 0;
        } 
        if (flights.size() == 0) {
            return -1;
        }
        int num_flights = flights.size();
        
        vector<vector<pair<int, int>>> adj_matrix(n);
        vector<vector<bool>> visited(K+2, vector<bool>(n, false));
        vector<vector<int>> cost(K+2, vector<int>(n, INT_MAX));
        cost[0][src] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, compare > pq;
        
        for (int i=0; i<num_flights; i++){
            adj_matrix[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        
        pq.push({0, 0, src});

        while (!pq.empty()){
            vector<int> head_node = pq.top();
            int current_node = head_node[2];
            pq.pop();
            
            int current_depth = head_node[0];
            if (visited[current_depth][current_node]) {
                continue;
            }
            visited[current_depth][current_node] = true;
            if (current_depth - 1 == K) {
                continue;
            }
            vector<pair<int, int>> neighbors = adj_matrix[current_node];
            
            
            for (int i=0; i< neighbors.size(); i++)
            {
                int next_node = neighbors[i].first, weight = neighbors[i].second;
                cost[current_depth+1][next_node] = min(cost[current_depth+1][next_node], cost[current_depth][next_node]);
                cost[current_depth+1][next_node] = min(cost[current_depth+1][next_node], cost[current_depth][current_node] + weight);
                if (current_depth < k) {
                    pq.push({current_depth+1, cost[current_depth+1][next_node], next_node});
                }
                
            } 
        }
        int result = INT_MAX;
        for (int i = 0;i<=K+1;++i) {
            if (cost[i][dst] < result) {
                result = cost[i][dst];
            }
        }
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> test{{0,1,2}, {1,2,1}, {2,0,10}};
    cout <<  s.findCheapestPrice(3, test, 1, 2, 1) << endl;
    return 0;
}
