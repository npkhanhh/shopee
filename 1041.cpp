#include <iostream>
#include <vector>
#include <assert.h> 
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int count_g=0, count_l=0, count_r = 0;
        int x=0, y=0;
        int face = 0;
        for (int i = 0; i<instructions.length(); ++i) {
            if (instructions[i] == 'G') {
                count_g += 1;
                if (face == 0) {
                    y += 1;
                } else if (face == 1) {
                    x += 1;
                } else if (face == 2) {
                    y -= 1;
                } else {
                    x -= 1;
                }
            } else if (instructions[i] == 'L') {
                count_l += 1;
                face -= 1;
                if (face < 0) {
                    face += 4;
                }
            } else {
                count_r += 1;
                face += 1;
                face = face % 4;
            }
        } 
        if (x==0 &&y==0 && face==0){
            return true;
        }
        if (abs(count_l - count_r) % 4 == 0 && count_g > 0) {
            return false;
        } 
        return true;
    }
};



int main() {
    Solution s; 
    bool b;
    cout << b << endl;
    int a;
    cout << a << endl;
    return 0;
}
