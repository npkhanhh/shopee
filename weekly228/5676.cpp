#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int start1 = 0, start0=0;
        for (int i=0; i<s.length();++i) {
            if (s[i] == '1') {
                if (i%2 == 0) {
                     cout << i << " " << s[i]<< endl;
                    start0 += 1;
                } else {        
                    start1 += 1;
                }
            } else {
                if (i % 2 == 0) {
                    start1 += 1;
                } else {
                    cout << i << endl;
                    start0 += 1;
                }
            }
        }
        cout << start0 << " " << start1 << endl;
        return min(start1, start0);
    }
};

int main() {
    Solution s;
    string str = "0100";
    cout << s.minOperations(str) << endl;
    return 0;
}