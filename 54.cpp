#include<iostream>
#include<vector>
#include <experimental/iterator>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res(m*n, 0);
        int index = 0, i=0, j=0, direction=1; //0 north, 1 east, 2 south, 3 west 
        visited[0][0] = true;
        while (index < m*n){
            res[index] = matrix[i][j];
            if (direction==1){
                if (j+1<n && !visited[i][j+1]){
                    j = j+1;
                }else{
                    i += 1;
                    direction = 2; 
                }

                cout << index << endl;
            }
            else if (direction==2){
                if (i+1<m && !visited[i+1][j]){
                    i +=1;
                }else{
                    j -= 1;
                    direction = 3; 
                }
            }
            else if (direction==3){
                if (j-1>=0 && !visited[i][j-1]){
                    j = j-1;
                }else{
                    i -= 1;
                    direction = 0; 
                }
            }
            else if (direction==0){
                if (i-1>=0 && !visited[i-1][j]){
                    i = i - 1;
                }else{
                    j += 1;
                    direction = 1; 
                }
            }
            index += 1;
            if (index >= m*n) {
                break;
            }
            visited[i][j] = true;
        }
        return res;
    }
};

void print(std::vector<int> const &input)
{
    copy(input.begin(),
         input.end(),
         experimental::make_ostream_joiner(cout, " "));
    cout << endl;
}

int main() {
    //vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> matrix{{1}};
    Solution s;
    print(s.spiralOrder(matrix));
    return 0;
}