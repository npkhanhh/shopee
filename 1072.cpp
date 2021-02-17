#include <iostream>
#include <vector>
#include <assert.h> 
#include <string>
#include<map>

using namespace std;


class Solution {
public:
    int maxEqualRowsAfterFlips(vector< vector<int> >& matrix) {
        map<string, int> m;
        for (int i=0; i<matrix.size(); i++){
            bool flip = false;
            string row= "";
            for (int j=0; j< matrix[0].size(); j++){
                if (j == 0) {
                    flip = matrix[i][j] == 0;
                }
                if (flip){
                    matrix[i][j] = 1 - matrix[i][j];
                }
                row += to_string(matrix[i][j]);
            }
            if ( m.find(row) == m.end() ) {
                m[row] = 1;
            } else {
                m[row] += 1;
            }
        }
        auto iter = m.begin();
        int max_value = 0;
        while (iter != m.end()) {
            if (iter->second > max_value){
                max_value = iter->second;
            }
            ++iter;
        }
        return max_value;
    }
};

int main() {
    Solution s;
    //test 1
    vector<int> row1 = {0, 0, 0};
    vector<int> row2 = {0, 0, 1};
    vector<int> row3 = {1, 1, 0};
    vector< vector<int> > test1 = {row1, row2, row3};
    
    assert (2 == s.maxEqualRowsAfterFlips(test1));
    cout << s.maxEqualRowsAfterFlips(test1);
    return 0;
}
