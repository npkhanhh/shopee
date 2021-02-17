#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        //vector<vector<int>> m(n+1, vector<int>(10, 0));
        vector<int> v(10, 0);
 
        vector<vector<int>> m(n+1, v);

 
        map<int, vector<int>> mymap;
        mymap[0]={4,6};
        mymap[1]={8,6};
        mymap[2]={7,9};
        mymap[3]={4,8};
        mymap[4]={0,3,9};
        mymap[6]={0,1,7};
        mymap[7]={2,6};
        mymap[8]={1,3};
        mymap[9]={2,4};
        for (int i=1; i< m.size(); i++){

            for (int j=0; j<10; j++){
                if (i==1){
                    m[i][j]=1;
                    continue;
                }

                if (j!=5){
                    vector<int> from_index = mymap[j];
                    m[i][j] = (m[i-1][from_index[0]] + m[i-1][from_index[1]])%1000000007;
                    if (from_index.size()==3){
                        m[i][j] += (m[i-1][from_index[2]]);
                    }
                    m[i][j] = m[i][j] % 1000000007;
                }
                
            }
        }
        long long total = 0;
        for (int j=0;j<10; j++){
            total += m[n][j];
            total = total % 1000000007;
        }
        return total;
    }
};
int main(){

    Solution s;
    cout << s.knightDialer(1) << endl;
    cout << s.knightDialer(2) << endl; 
    cout << s.knightDialer(4) << endl; 
    cout << s.knightDialer(3131) << endl;  
}