#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0) {
            if (n % 2 ==1 ) {
                res += 1;
                n -= 1;
            }
            n /= 2;
        }        
        return res;
    }
};

int main() {
    Solution s;
    s.hammingWeight(3);
    return 0;
}